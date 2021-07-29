// Resize a not compressed 24-bit BMP file
// usage format: ./resize ratio infile outfile

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize ratio infile outfile\n");
        return 1;
    }

    // Ensure proper resize factor
    float ratio = atof(argv[1]);
    if (ratio <= 0 || ratio >100)
    {
        fprintf(stderr, "The resize factor, must satisfy 0 < n <= 100.\n");
        return 1;
    }
    
    // Remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    // Recalculate headers data based on new picture size
    int biHeightOri = abs(bi.biHeight);
    int biWidthOri = bi.biWidth;
    
    
    bi.biWidth *= ratio;
    bi.biHeight *= ratio;
    bi.biSizeImage = bi.biWidth * abs(bi.biHeight) * sizeof(RGBTRIPLE) + abs(bi.biHeight) * ((4 - (sizeof(RGBTRIPLE) * bi.biWidth) % 4) % 4);
    bf.bfSize = bf.bfOffBits + bi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int paddingIn = (4 - (biWidthOri * sizeof(RGBTRIPLE)) % 4) % 4;    
    int paddingOut = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    if (ratio >= 1)
    {
        // Increasing picture size
        // Iterate over infile's scanlines
        // ..by strings
        for (int i = 0; i < biHeightOri; i++)
        {
            
            // We will repeat this with one string RATIO times to create several strings in outfile
            for (int rs = 0; rs < ratio; rs++)
            {
                // iterate over pixels in infile scanline 
                for (int j = 0; j < biWidthOri; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;
                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
                    // write RGB triple to outfile. Do it RATIO times.       
                    for (int rc = 0; rc < ratio; rc++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }    
                // Add 0-pattern paddingit to outfile at the end of triple string
                for (int n = 0; n < paddingOut; n++)
                {
                    fputc(0x00, outptr);
                }
                // Return infile pointer to the begining of the infile string
                fseek(inptr, -biWidthOri * sizeof(RGBTRIPLE), SEEK_CUR);
            }

            // Go to the next string in infile
            fseek(inptr, sizeof(RGBTRIPLE) * biWidthOri + paddingIn, SEEK_CUR);
        }
    }
    else
    {
        // decreasing picture size
        // k is decreasing ratio
        int k = (int)(1 / ratio);
        // iterate over infile's scanlines        
        for (int i = 0; i < biHeightOri; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < biWidthOri; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                if ((j % k == 0) && (i % k == 0) && (j / k < bi.biWidth) && (i / k < abs(bi.biHeight)))
                {
                    // write every k RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);   
                }
                
            }
            // Add 0-pattern paddingit to outfile at the end of triple string
            if (i % k == 0)
            {
                for (int n = 0; n < paddingOut; n++)
                {
                    fputc(0x00, outptr);
                }
            }

            // skip over padding in infile
            fseek(inptr, paddingIn, SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

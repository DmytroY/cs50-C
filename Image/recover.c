// recovers deleted jpg images stored in FAT file system.
// Usage: ./recover rawimagefile.
// card.raw can be used as test rawimagefile file.  
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// alias for C primitive data type
typedef uint32_t DWORD;

int main(int argc, char *argv[])
{
    unsigned char block[512];
    DWORD dword;
    int j = -1;
    char outfile[8];
    FILE *outptr;    
    
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // open input file
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    while (!feof(inptr))
    {
        
        // write outfile's 
        if (j >= 0) { fwrite(&block, 512, 1, outptr); }
        // read input file by 512 bytes chunks
        fread(&block, 512, 1, inptr);
        // find begining of jpg file
        dword = (int)block[0] + (int)block[1] * 0x100 + (int)block[2] * 0x10000 + ((int)block[3] & 0xf0) *0x1000000;
        if (dword == 0xe0ffd8ff)
        {
            // to close previous jpg file
            if (j >= 0) { fclose(outptr); }
            j++;
            // create name and open next jpg file
            sprintf(outfile, "%03d%s", j, ".jpg");
            outptr = fopen(outfile, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                printf("Could not create %s.\n", outfile);
                return 3;
            }
        }
    }
    fclose(outptr);
    fclose(inptr);
}

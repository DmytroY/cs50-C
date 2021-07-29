// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *finput = fopen(argv[1], "r");
    if (finput == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *foutput = fopen(argv[2], "w");
    if (foutput == NULL)
    {
        printf("Could not open output file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // allocate memory for header data
    int *pointer = malloc(HEADER_SIZE);
    if (!pointer)
    {
        printf("Can't allocate memory for header");
        return 1;
    }
    
    // read header from infile
    fread(pointer, HEADER_SIZE, 1, finput);
    
    // write header to outfile
    fwrite(pointer, HEADER_SIZE, 1, foutput);
    // free memory
    free(pointer);
    
    // TODO: Read samples from input file and write updated data to output file
    // read a byte, convert, vrite a byte till the EOF
    int16_t sample, sample2;

    while (1)
    {
        fread(&sample, sizeof(sample), 1, finput);
        if (feof(finput))
        {
            break;
        }
        sample = sample * factor;
        fwrite(&sample, sizeof(sample), 1, foutput);
    }
    
    // Close files
    fclose(finput);
    fclose(foutput);
}

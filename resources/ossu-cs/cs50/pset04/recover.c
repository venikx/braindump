#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usuage: ./recover rawFile\n");
        return 1;
    }

    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Not possible to open %s. Please try again.\n", infile);
        return 2;
    }

    unsigned char *buffer = malloc(512);
    if (buffer == NULL)
    {
        fprintf(stderr, "Could not allocate memory for block");
        return 3;
    }

    FILE *picture = NULL;
    char fileName[15];
    int counter = 0;

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        // check the first couple bytes to match JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (picture != NULL)
            {
                printf("%s\n", fileName);
                fclose(picture);
                counter++;
            }

            sprintf(fileName, "%03i.jpg", counter);
            picture = fopen(fileName, "w");

            if (picture == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", fileName);
                return 4;
            }
        }

        if (picture != NULL)
        {
            fwrite(buffer, 512, 1, picture);
        }
    }

    fclose(picture);
    return 0;
}

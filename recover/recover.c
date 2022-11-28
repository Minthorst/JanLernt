#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int BLOCK_SIZE = 512;
int counter = 0;
char filename[8];
FILE *img = NULL;

int main(int argc, char *argv[])
{
    // error if more than one command line arg
    if (argc != 2)
    {
        printf("Usage: only one image\n");
        return 1;
    }

    // open file
    FILE *file = fopen(argv[1], "r");

    // error when file cannot be opened
    if (file == NULL)
    {
        printf("cannot open image\n");
        return 1;
    }

    // allocate buffer
    BYTE *buffer = malloc(BLOCK_SIZE);

    // as long as there is a Block write block into buffer
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {

        // for first file
        if (counter == 0)
        {
            // if the Block starts with jpeg headers
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // make filename
                sprintf(filename, "%03i.jpg", counter);
                // open new file
                img = fopen(filename, "w");
                // write from buffer to file
                fwrite(buffer, 1, BLOCK_SIZE, img);
                // add to counter
                counter++;
            }
            else
            {
            }
        }
        else
        {
            // if headers match JPEG add new file s.o.
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {

                // close old file
                fclose(img);
                // name new file according to counter
                sprintf(filename, "%03i.jpg", counter);
                // open new file
                img = fopen(filename, "w");
                // copy from buffer to file
                fwrite(buffer, 1, BLOCK_SIZE, img);
                // add to counter
                counter++;
            }
            else
            {
                // if not jpeg header just write buffer into excisting file
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
    }
    // close the last img
    fclose(img);
    // close the Argv file
    fclose(file);
    // free from malloc
    free(buffer);
}
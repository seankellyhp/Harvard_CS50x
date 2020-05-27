#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
// Check if proper image argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;

    }
    else
    {

        FILE *recFile = fopen(argv[1], "r");

        if (recFile == NULL)
        {
            fprintf(stderr, "Failed to open %s\n", argv[1]);
            return 2;
        }

// Buffer Array
        unsigned char buffer[512];

// Count Number of Images
        int imgNum = 0;

// Array for Name of Image
        char imgName[8];

// File Storage
        FILE *img;

// Track if file is open for later
        bool fileOpen = false;


        while (fread(buffer, 512, 1, recFile) == 1)
        {
// If starts with pattern then new JPG

            if (buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                ((buffer[3] & 0xf0) == 0xe0))
            {
// If starts with pattern and already open, then new image
                if (fileOpen == true)
                {
                    fclose(img);
                }
// If starts with pattern then store info as image with name as counter number
                sprintf(imgName, "%03i.jpg", imgNum);
                imgNum++;

                img = fopen(imgName, "w");
                fileOpen = true;

// Write image data to buffer
                fwrite(buffer, 512, 1, img);
            }
            else
            {
// If does not start with pattern, but file is open then it is more data from previous image. Write to buffer.
                if (fileOpen == true)
                {
                    fwrite(buffer, 512, 1, img);
                }
            }
        }
// Close all open
        fclose(recFile);
        fclose(img);

        return 0;
    }
}

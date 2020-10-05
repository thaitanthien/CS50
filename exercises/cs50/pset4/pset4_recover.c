#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/**PSEUDOCODE:
 * Open memory card
 * Repeat until end of card:
 *      Read 512 bytes into a buffer
 *      If start of new JPEG
 *          If first JPEG
 *              000.jpg
 *          Else, already found a JPEG
 *              close the file just writing to
 *              open up new file and continue writing to file
 *      Else
 *          If already found a JPEG and writing into it: Keep writing to it
 * Close any remaining files (reach the end of memory card)
**/

#define BLOCKSIZE 512
typedef uint8_t BYTE;
BYTE buffer[BLOCKSIZE];

BYTE jpgCount = 0;
bool writingToNewFile = false;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2) {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image file
    FILE *forensicImage = fopen(argv[1], "r");

    // Ensure the file can be opened for reading
    if (!forensicImage) {
        return 1;
    }

    // Allocate memory to hold 000.jpg plus '\0'
    char *jpgFilename = malloc((sizeof(char *)) * strlen("000.jpg") + 1);

    // Create file pointer for the newly created jpg
    FILE *jpgFile;

    while (!feof(forensicImage)) {   // Loop til end of file

        // Read 512 bytes from file into a buffer
        fread(buffer, sizeof(BYTE), BLOCKSIZE, forensicImage);

        // Find start of JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {

            // Making a new JPEG file to write data to
            // Create filename for the next jpg
            sprintf(jpgFilename, "%03i.jpg", jpgCount);

            if(!writingToNewFile) {     // First jpg
                // Open a new jpg file to write data to
                jpgFile = fopen(jpgFilename, "w");
                if(!jpgFile) {
                    return 1;
                }

                // Write data to file
                fwrite(buffer, sizeof(BYTE), BLOCKSIZE, jpgFile);
                writingToNewFile = true;
            }
            if(writingToNewFile) {      // Already found jpg
                // Close the previous jpg
                fclose(jpgFile);

                // Open a new jpg to write data to
                jpgFile = fopen(jpgFilename, "w");
                if(!jpgFile) {
                    return 1;
                }

                // Write data to file
                fwrite(buffer, sizeof(BYTE), BLOCKSIZE, jpgFile);

                // Increment file number of the next image
                jpgCount++;
            }
        }
        else if(writingToNewFile) {
            // Keep writing to file
            fwrite(buffer, sizeof(BYTE), BLOCKSIZE, jpgFile);
        }
    }

    // Close last created jpg file if it still opened
    if(jpgFile) {
        fclose(jpgFile);
    }

    // Close file
    fclose(forensicImage);

    return 0;
}
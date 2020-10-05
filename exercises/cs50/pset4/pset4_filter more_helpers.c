#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Compute the average of 3 channel values
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // grayscale value of each channel
            image[i][j].rgbtBlue  = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed   = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            // Swap left side and right side pixels
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
//Ensure index is valid
bool isValid(int i, int j, int height, int width) {
    return i >= 0 && i < height && j >= 0 && j < width;
}

//Compute blurred image
BYTE computeBlurredChanel(int height, int width, RGBTRIPLE image[height][width], int i, int j, char c) {

    int deltaI[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int deltaJ[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    float sum = 0; //Sum of the color values of pixels and its neighbor
    int validNeighborsCount = 0;
    for (int k = 0; k < 9; k++) {
        int newI = i + deltaI[k];
        int newJ = j + deltaJ[k];

        if (isValid(newI, newJ, height, width)) {
            validNeighborsCount++;

            if (c == 'R') {
                sum += image[newI][newJ].rgbtRed;
            }
            else if (c == 'G') {
                sum += image[newI][newJ].rgbtGreen;
            }
            else if (c == 'B') {
                sum += image[newI][newJ].rgbtBlue;
            }
        }
    }

    return round(sum / validNeighborsCount);
}


void blur(int height, int width, RGBTRIPLE image[height][width]) {
    //Allocate memory for blurred image
    RGBTRIPLE(*blurredImage)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    //Compute blurred image from current image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <width; j++) {
            blurredImage[i][j].rgbtRed   = computeBlurredChanel(height, width, image, i, j, 'R');
            blurredImage[i][j].rgbtGreen = computeBlurredChanel(height, width, image, i, j, 'G');
            blurredImage[i][j].rgbtBlue  = computeBlurredChanel(height, width, image, i, j, 'B');
        }
    }

    //Replace current image by blurred image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = blurredImage[i][j];
        }
    }
    return;
}
//----------------
// Detect edges

int computeEdgesChanel(int height, int width,            // image size
                        RGBTRIPLE image[height][width],  // original image
                        int i, int j,                    // current pixel
                        char direction,                  // direction Gx or Gy
                        char c) {                        // desired channel
    int deltaI[9]  = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int deltaJ[9]  = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int kernelX[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int kernelY[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    int sum  = 0;
    for (int k = 0; k < 9; k++) {

        int newi = i + deltaI[k];
        int newj = j + deltaJ[k];

        if (isValid(newi, newj, height, width)) {

            if (direction == 'X') {
                if (c == 'R') {
                    sum += image[newi][newj].rgbtRed * kernelX[k];
                } else if (c == 'G') {
                    sum += image[newi][newj].rgbtGreen * kernelX[k];
                } else if (c == 'B') {
                    sum += image[newi][newj].rgbtBlue * kernelX[k];
                }
            } else if (direction == 'Y') {
                if (c == 'R') {
                    sum += image[newi][newj].rgbtRed * kernelY[k];
                } else if (c == 'G') {
                    sum += image[newi][newj].rgbtGreen * kernelY[k];
                } else if (c == 'B') {
                    sum += image[newi][newj].rgbtBlue * kernelY[k];
                }
            }
        }
    }
    return sum;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Allocate memory for edges detected image
    RGBTRIPLE(*edgesImage)[width]   = calloc(height, width * sizeof(RGBTRIPLE));

    //Compute edges detected image from current image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            //Compute two values Gx and Gy
            int redX   = computeEdgesChanel(height, width, image, i, j, 'X', 'R');
            int greenX = computeEdgesChanel(height, width, image, i, j, 'X', 'G');
            int blueX  = computeEdgesChanel(height, width, image, i, j, 'X', 'B');

            int redY   = computeEdgesChanel(height, width, image, i, j, 'Y', 'R');
            int greenY = computeEdgesChanel(height, width, image, i, j, 'Y', 'G');
            int blueY  = computeEdgesChanel(height, width, image, i, j, 'Y', 'B');

            //Combine Gx and Gy
            int edgesImageRed   = round(sqrt(redX*redX + redY*redY));
            int edgesImageGreen = round(sqrt(greenX*greenX + greenY*greenY));
            int edgesImageBlue  = round(sqrt(blueX*blueX + blueY*blueY));

            // Cap the resulting value at 255
            edgesImage[i][j].rgbtRed   = (edgesImageRed  > 255)  ? 255 : (BYTE)edgesImageRed;
            edgesImage[i][j].rgbtGreen = (edgesImageGreen > 255) ? 255 : (BYTE)edgesImageGreen;
            edgesImage[i][j].rgbtBlue  = (edgesImageBlue > 255)  ? 255 : (BYTE)edgesImageBlue;
        }
    }

    //Replace current image by edges detected image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = edgesImage[i][j];
        }
    }

    return;
}

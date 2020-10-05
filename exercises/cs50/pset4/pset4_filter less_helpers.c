#include "helpers.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            // Compute the average of the red, green, and blue values
            float averageInFloat = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            // Round averageInFloat to the nearest integer
            int averageInInteger = round(averageInFloat);
            // grayscale value of each channel
            image[i][j].rgbtBlue = averageInInteger;
            image[i][j].rgbtGreen = averageInInteger;
            image[i][j].rgbtRed = averageInInteger;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {

            // Compute the sepia color values and round them to the nearest integer
            int integerSepiaR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int integerSepiaG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int integerSepiaB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Guarantee the values between 0 and 255, inclusive
            image[i][j].rgbtRed   = (integerSepiaR > 255) ? 255 : (BYTE)integerSepiaR;
            image[i][j].rgbtGreen = (integerSepiaG > 255) ? 255 : (BYTE)integerSepiaG;
            image[i][j].rgbtBlue  = (integerSepiaB > 255) ? 255 : (BYTE)integerSepiaB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width / 2; j++) {
            // Swap left side and right side pixels
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
// Return true if i and j are valid index
bool isValid(int i, int j, int height, int width) {
    return (0 <= i) && (i < height) &&
           (0 <= j) && (j < width);
}

BYTE computeBlurredChannel(int height, int width,           // image size
                           RGBTRIPLE image[height][width],  // original image
                           int i, int j,                    // current pixel
                           char c) {                        // desired channel
    int deltaI[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int deltaJ[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    float sum = 0;     // sum of the values of all the neighbouring and itself pixels
    int validNeighborsCount = 0;
    for(int k = 0 ; k < 9; k++) {
        int newi = i + deltaI[k];
        int newj = j + deltaJ[k];

        if (isValid(newi, newj, height, width)) {
            validNeighborsCount += 1;

            if (c == 'R') {
                sum += image[newi][newj].rgbtRed;
            } else if (c == 'G') {
                sum += image[newi][newj].rgbtGreen;
            } else if (c == 'B') {
                sum += image[newi][newj].rgbtBlue;
            }
        }
    }
    return round(sum / validNeighborsCount);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for blurred image
    RGBTRIPLE(*blurredImage)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    // Compute blurred image from current image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            blurredImage[i][j].rgbtRed   = computeBlurredChannel(height, width, image, i, j, 'R');
            blurredImage[i][j].rgbtGreen = computeBlurredChannel(height, width, image, i, j, 'G');
            blurredImage[i][j].rgbtBlue  = computeBlurredChannel(height, width, image, i, j, 'B');
        }
    }

    // Replace the image with the blurred image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            image[i][j] = blurredImage[i][j];
        }
    }

}
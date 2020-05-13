#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

/// Get RGB Values and Average them
            int Bl = image[i][j].rgbtBlue;
            int Gr = image[i][j].rgbtGreen;
            int Re = image[i][j].rgbtRed;
            int TrAvg = round((Bl + Gr + Re) / 3.0);

/// Assign new values as Average
            image[i][j].rgbtBlue = TrAvg;
            image[i][j].rgbtGreen = TrAvg;
            image[i][j].rgbtRed = TrAvg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            /// Get RGB Values into useable object
            int Bl = image[i][j].rgbtBlue;
            int Gr = image[i][j].rgbtGreen;
            int Re = image[i][j].rgbtRed;

            /// Calculate new Sepia Values using algorithm
            int BlSep = round(.272 * Re + .534 * Gr + .131 * Bl);
            int GrSep = round(.349 * Re + .686 * Gr + .168 * Bl);
            int ReSep = round(.393 * Re + .769 * Gr + .189 * Bl);

            /// Assign new Sep values within range

            do
            {
                if (BlSep > 255)
                {
                    BlSep = 255;
                }
                else if (GrSep > 255)
                {
                    GrSep = 255;
                }
                else if (ReSep > 255)
                {
                    ReSep = 255;
                }
            }
            while (BlSep > 255 || GrSep > 255 || ReSep > 255);

            /// Assign new Sepia Values using algorithm
            image[i][j].rgbtBlue = BlSep;
            image[i][j].rgbtGreen = GrSep;
            image[i][j].rgbtRed = ReSep;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
// swap the left and the right...
    int left = 0;
    int right = width - 1;

    for (int i = 0; i < height; i++)
    {
        do
        {

            RGBTRIPLE temp = image[i][left];
            image[i][left] = image[i][right];
            image[i][right] = temp;

            right--;
            left++;
        }
        while (left != right && right > left);

        left = 0;
        right = width - 1;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

// Make Copy of Image for transformation
    RGBTRIPLE Cimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Cimage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

// Transform Pixels
            int BlRSum = 0;
            int ReRSum = 0;
            int GrRSum = 0;
            int Den = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if (i + row < 0 || j + col < 0 || i + row >= height || j + col >= width)
                    {

                    }
                    else
                    {
                        BlRSum += Cimage[i + row][j + col].rgbtBlue;
                        ReRSum += Cimage[i + row][j + col].rgbtRed;
                        GrRSum += Cimage[i + row][j + col].rgbtGreen;
                        Den++;
                    }
                }
            }

            image[i][j].rgbtBlue = round(BlRSum / (float) Den);
            image[i][j].rgbtGreen = round(GrRSum / (float) Den);
            image[i][j].rgbtRed = round(ReRSum / (float) Den);

        }
    }
    return;
}

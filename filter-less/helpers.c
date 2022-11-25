#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // go through rows
    for (int i = 0; i <= height; i++)
    {
        // go through collums
        for (int j = 0; j <= width; j++)
        {
            float grey = 0;

            // take the average of RGB
            grey = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)) / 3.0;

            // round and assign
            image[i][j].rgbtBlue = round(grey);
            image[i][j].rgbtGreen = round(grey);
            image[i][j].rgbtRed = round(grey);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // go through rows
    for (int i = 0; i < height; i++)
    {
        // go through colllums
        for (int j = 0; j < width; j++)
        {

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // calc sepia Value, make it 255 if >255
            float sepiaRed = ((.393 * red) + (.769 * green) + (.189 * blue));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            float sepiaGreen = ((.349 * red) + (.686 * green) + (.168 * blue));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            float sepiaBlue = ((.272 * red) + (.534 * green) + (.131 * blue));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // round and assign new values
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;

    // go through rows
    for (int i = 0; i < height; i++)
    {
        // go through colllums
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = buffer;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    // make a copy
    for (int i = 0; i < height; i++)
    {

        // loop through collums j
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // loop though rows i
    for (int i = 0; i < height; i++)
    {

        // loop through collums j
        for (int j = 0; j < width; j++)
        {
            float div = 0.0;
            int reddiv = 0;
            int greendiv = 0;
            int bluediv = 0;

            // 1
            if (i > 0 && j > 0)
            {
                div++;
                reddiv = reddiv + copy[i - 1][j - 1].rgbtRed;
                greendiv = greendiv + copy[i - 1][j - 1].rgbtGreen;
                bluediv = bluediv + copy[i - 1][j - 1].rgbtBlue;
            }
            // 2
            if (i > 0)
            {
                div++;
                reddiv = reddiv + copy[i - 1][j].rgbtRed;
                greendiv = greendiv + copy[i - 1][j].rgbtGreen;
                bluediv = bluediv + copy[i - 1][j].rgbtBlue;
            }
            // 3
            if (i > 0 && j < width - 1)
            {
                div++;
                reddiv = reddiv + copy[i - 1][j + 1].rgbtRed;
                greendiv = greendiv + copy[i - 1][j + 1].rgbtGreen;
                bluediv = bluediv + copy[i - 1][j + 1].rgbtBlue;
            }
            // 4
            if (j > 0)
            {
                div++;
                reddiv = reddiv + copy[i][j - 1].rgbtRed;
                greendiv = greendiv + copy[i][j - 1].rgbtGreen;
                bluediv = bluediv + copy[i][j - 1].rgbtBlue;
            }
            // 5
            if (1 == 1)
            {
                div++;
                reddiv = reddiv + copy[i][j].rgbtRed;
                greendiv = greendiv + copy[i][j].rgbtGreen;
                bluediv = bluediv + copy[i][j].rgbtBlue;
            }
            // 6
            if (j < width - 1)
            {
                div++;
                reddiv = reddiv + copy[i][j + 1].rgbtRed;
                greendiv = greendiv + copy[i][j + 1].rgbtGreen;
                bluediv = bluediv + copy[i][j + 1].rgbtBlue;
            }
            // 7
            if (i < height - 1 && j > 0)
            {
                div++;
                reddiv = reddiv + copy[i + 1][j - 1].rgbtRed;
                greendiv = greendiv + copy[i + 1][j - 1].rgbtGreen;
                bluediv = bluediv + copy[i + 1][j - 1].rgbtBlue;
            }
            // 8
            if (i < height - 1)
            {
                div++;
                reddiv = reddiv + copy[i + 1][j].rgbtRed;
                greendiv = greendiv + copy[i + 1][j].rgbtGreen;
                bluediv = bluediv + copy[i + 1][j].rgbtBlue;
            }
            // 9 
            if (i < height - 1 && j < width - 1)
            {
                div++;
                reddiv = reddiv + copy[i + 1][j + 1].rgbtRed;
                greendiv = greendiv + copy[i + 1][j + 1].rgbtGreen;
                bluediv = bluediv + copy[i + 1][j + 1].rgbtBlue;
            }

            image[i][j].rgbtRed = round(reddiv / div);
            image[i][j].rgbtGreen = round(greendiv / div);
            image[i][j].rgbtBlue = round(bluediv / div);
        }
    }

    return;
}

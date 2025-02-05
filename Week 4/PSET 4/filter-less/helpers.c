#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int sourceBlue;
    int sourceGreen;
    int sourceRed;
    float resultGray;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sourceBlue = image[i][j].rgbtBlue;
            sourceGreen = image[i][j].rgbtGreen;
            sourceRed = image[i][j].rgbtRed;

            resultGray = round((sourceBlue + sourceGreen + sourceRed) / 3.0);

            image[i][j].rgbtBlue = resultGray;
            image[i][j].rgbtGreen = resultGray;
            image[i][j].rgbtRed = resultGray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalBlue, originalGreen, originalRed;
    float sepiaBlue, sepiaGreen, sepiaRed;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;
            originalRed = image[i][j].rgbtRed;

            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE sourcepixel[width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sourcepixel[j] = image[i][j];
        }

        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = sourcepixel[width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = sourcepixel[width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = sourcepixel[width - j - 1].rgbtRed;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blurBlue = 0;
            float blurGreen = 0;
            float blurRed = 0;
            int totalpixels = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    if (!(i + m < 0 || i + m >= height || j + n < 0 || j + n >= width))
                    {
                        blurBlue += copy[i + m][j + n].rgbtBlue;
                        blurGreen += copy[i + m][j + n].rgbtGreen;
                        blurRed += copy[i + m][j + n].rgbtRed;
                        totalpixels++;
                    }

                    else
                    {
                        continue;
                    }
                }
            }

            image[i][j].rgbtBlue = (int) round(blurBlue / totalpixels);
            image[i][j].rgbtGreen = (int) round(blurGreen / totalpixels);
            image[i][j].rgbtRed = (int) round(blurRed / totalpixels);
        }
    }
}

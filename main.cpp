#include <iostream>
#include <PPM.hpp>
#include <fstream>
#include <sstream>
#include <random>
#include "PerlinNoise.hpp"

int main()
{
    int width = 512;
    int height = 512;
    PPM image = PPM(width, height, "out.ppm");
    PerlinNoise pn;
    PerlinNoise::setSeed(10);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double x_p = (double)y/((double)width) * 1.5;
            double y_p = (double)x/((double)height) * 1.5;
            int rgb[3];
            double n = PerlinNoise::PerlinNoise_3D(x_p * 10, y_p * 10, 0.8);
            if (n * 255 < 10)
            {
                rgb [0] = 35;
                rgb [1] = 132;
                rgb [2] = 235;
            }
            else
            if (n * 255 > 10 && n * 255 < 70)
            {
                rgb [0] = 252;
                rgb [1] = 213;
                rgb [2] = 0;
            }
            else
            if (n * 255 > 70)
            {
                rgb [0] = 13;
                rgb [1] = 164;
                rgb [2] = 13;
            }
            image.drawPixel(x, y, rgb);
        }
    }
    image.writeImage();
}
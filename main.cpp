#include <iostream>
#include <PPM.hpp>
#include <fstream>
#include <sstream>
#include <random>
int main()
{
    int width = 256;
    int height = 256;
    PPM image = PPM(width, height, "out.ppm");
    float heights [width] [height];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int z = 0; z < width; z++)
            {
                int c = 0;
                int rgb [] = {c, c, c};
                image.drawPixel(x, y, rgb);
            }
        }
    }
    image.writeImage();
}
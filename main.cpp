#include <iostream>
#include <PPM.hpp>
#include <fstream>
#include <sstream>
#include <random>
#include "PerlinNoise.hpp"

int main()
{
    int width = 256;
    int height = 256;
    PPM image = PPM(width, height, "out.ppm");
    float heights [width] [height];
    PerlinNoise noise = PerlinNoise(11);
      
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double j = (double)y/((double)width);
			double i = (double)x/((double)height);
			float n = noise.interpolateNoise3d(10 * i, 10 * j, 0.8);
			n = 20 * noise.interpolateNoise3d(i, j, 0.8);
			n = n - floor(n);

            int rgb [] = {n * 255, n * 255, n * 255};
            image.drawPixel(x, y, rgb);
        }
    }

    image.writeImage();
}
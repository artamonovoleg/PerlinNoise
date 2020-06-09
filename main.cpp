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
    PerlinNoise noise;
      
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            float y_p = (float) y / (float) width;
			float x_p = (float) x / (float) height;

            float n = noise.interpolateNoise3d(20 * x_p, 20 * y_p, 0.8);
            n = n - floor(n);
            int rgb [] = {n * 255, n * 255, n * 255};
            image.drawPixel(x, y, rgb);
        }
    }

    image.writeImage();
}
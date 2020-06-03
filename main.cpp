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


        for (int x = 0; x < width; x++)
        {
        //     float c = noise.noise1d(x);
        //     // if (c < -1.0f && c > 1.0f)
        //         std::cout << c << std::endl;
            float n = noise.perlinNoise1d(x);
            int c =  (fabs(n)) * 255;
            if (c >= 254 && c > 0)
            {
                // std::cout << c << std::endl;
            }
            else
            {
                int rgb [] = {c, c, c};
                image.drawPixel(x, c, rgb);
            }
            
            
        }
    
    
    // for (int y = 0; y < height; y++)
    // {
    //     for (int x = 0; x < width; x++)
    //     {
    //         for (int z = 0; z < width; z++)
    //         {
    //             int c =  (noise.noise1d(i) + 1) * 255;
    //             int rgb [] = {c, c, c};
    //             image.drawPixel(x, y, rgb);
    //         }
    //     }
    // }
    image.writeImage();
}
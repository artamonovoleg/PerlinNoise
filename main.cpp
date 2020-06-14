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
    pn.setSeed(15);
    pn.setScale(width);
    int n = 1;
    while(n != 0)
    {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int rgb[3];
                double n = pn.fracNoise3D(x * 10, y * 10, 0.8);
                if (n * 255 < 10) {
                    rgb[0] = 35;
                    rgb[1] = 132;
                    rgb[2] = 235;
                } else if (n * 255 > 10 && n * 255 < 70) {
                    rgb[0] = 252;
                    rgb[1] = 213;
                    rgb[2] = 0;
                } else if (n * 255 > 70) {
                    rgb[0] = 13;
                    rgb[1] = 164;
                    rgb[2] = 13;
                }
                image.drawPixel(x, y, rgb);
            }
        }
        image.writeImage();
        std::cin >> n;
        pn.setSeed(n);
    }
}
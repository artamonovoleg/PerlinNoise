#include <iostream>
#include <PPM.hpp>
#include <ctime>
#include "PerlinNoise.hpp"

void drawWorld(int * rgb, double n)
{
    if (n * 255 < 10)
    {
        rgb[0] = 35;
        rgb[1] = 132;
        rgb[2] = 235;
    }
    else
    if (n * 255 > 10 && n * 255 < 70)
    {
        rgb[0] = 252;
        rgb[1] = 213;
        rgb[2] = 0;
    }
    else
    if (n * 255 >= 70 && n * 255 < 190)
    {
        rgb[0] = 13;
        rgb[1] = 164;
        rgb[2] = 13;
    }
    else
    if (n * 255 >= 190 && n * 255 < 253)
    {
        rgb [0] = 128;
        rgb [1] = 128;
        rgb [2] = 128;
    }
    else
    if (n * 255 >= 253)
    {
        rgb [0] = 255;
        rgb [1] = 255;
        rgb [2] = 255;
    }
};

void render(PPM image, int * pos)
{
    PerlinNoise pn;
    pn.setSeed(15);
    pn.setScale(image.getWidth() / 2);
    int rgb [3];
    for (int y = 0; y < image.getHeight(); y++)
    {
        for (int x = 0; x < image.getWidth(); x++)
        {
            double n = pn.fracNoise3D((x + pos [0]) * 10, (y + pos [1]) * 10, 0.8);
            drawWorld(rgb, n);
            image.drawPixel(x, y, rgb);
        }
    }
    image.writeImage();
}
int main()
{
    int width = 512;
    int height = 512;
    PPM image = PPM(width, height, "out.ppm");
    int pos[2] = {0, 0};
    for (int i = 0;;i++)
    {
        render(image, pos);
        pos [0] += 5;
        pos [1] += 5;
    }
}
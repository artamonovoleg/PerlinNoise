#include <iostream>
#include <PPM.hpp>
#include <random>

void drawOctave (int size, int quad_size, PPM image)
{
    std::mt19937 gen;
    float color = gen() % 256;
    for (int y = 0; y < size; y ++)
    {
        for (int x = 0; x < size; x ++)
        {
            if(x % quad_size == 0 && y % quad_size == 0)
                color = gen() % 256;
            else
            if(y != 0 && x % quad_size == 0)
                color = image.getPixel(x, y - 1);
            else
            if(x != 0)
                color = image.getPixel(x - 1, y);
                image.setPixel(x, y, color);
        }
    }
}

int main()
{
    int size = 1024;
    PPM image = PPM(size);
    int quad_size = 1;
    float pc = -1.0f;
    drawOctave(size, 16, image);
    
    
    image.createImage("first.ppm");
    return 0;
}
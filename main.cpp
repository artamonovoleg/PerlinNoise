#include <iostream>
#include <PPM.hpp>
#include <random>
void drawOctave(int size, int ppc, PPM image)
{
    std::mt19937 gen;
    float color = gen() % 256;
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            // if(x % ppc == 0 || y % ppc == 0)
            // if(x % ppc == 0 )
            //     color = gen() % 256;
            if(x > size / 2 && y < size / 2)
                color = 255.0f;
            if(x < size / 2)
                color = 0.0f;
            image.setPixel(x, y, color);
        }
    }
    ppc *= 2;
}
int main()
{
    int size = 1024;
    PPM image = PPM(size);
    int ppc = 64;
    // for (int i = size; i != 16; i /=2)
    // {
        drawOctave(size, ppc, image);
    // }
    image.createImage("first.ppm");
    return 0;
}
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
            if(x % ppc == 0 || y % ppc == 0)
                    color = gen();
            if(ppc == 4)
                image.setPixel(x, y, color);
            else
            {
                color = (image.getPixel(x, y) + color) / 2; 
                image.setPixel(x, y, color);
            }
        }
    }
    ppc *= 2;
}
int main()
{
    int size = 1024;
    PPM image = PPM(size);
    int ppc = 1;
    for (int i = size; i != 8; i /=2)
    {
        drawOctave(1024, ppc, image);
    }
    image.createImage();
    return 0;
}
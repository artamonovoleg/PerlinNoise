#include <iostream>
#include <PPM.hpp>
#include <random>

void drawOctave(int *octave, int octave_size)
{
    std::mt19937 gen;
    int color;
    for(int y = 0; y < octave_size; y++)
    {
        for(int x = 0; x < octave_size; x++)
        {
            color = gen() % 256;
            octave [x + y * octave_size] = color;
        }
    }
}
void addOctave(int *octave, int octave_size, PPM image)
{
    for(int y = 0; y < image.getSize(); y++)
    {
        for(int x = 0; x < image.getSize(); x++)
        {
            int tempX = (x * octave_size) / image.getSize();
            int tempY = (y * octave_size) / image.getSize();
            image.setPixel(x, y, (image.getPixel(x, y) + octave[tempX + tempY * octave_size]) / 2);
        }
    }
}
int main()
{
    int size = 512;
    PPM image = PPM(size);
    for(int i = 1024; i != 8; i /=2)
    {
        int octave [i * i];
        drawOctave(octave, i);
        addOctave(octave, i, image);
    }
    
    image.createImage("first.ppm");
    return 0;
}
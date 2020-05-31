#include <iostream>

class PPM
{
    private:
        const char * filename;
        int m_width;
        int m_height;
        int * r;
        int * g;
        int * b;
        const int maxColorValue = 255;
    public:
        PPM(int width, int height, const char * name);
        void drawPixel(int x, int y, int * rgb);
        void writeImage();
};
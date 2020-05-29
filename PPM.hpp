#include <iostream>

class PPM
{
    private:
        const char * filename = "output.ppm";
        int m_image_size;
        unsigned char * m_image;
        const int maxColorComponentValue = 255;
        FILE * fp;
    public:
        PPM(int image_size);
        PPM(int image_size, unsigned char * image);
        void createImage();
        void setPixel(int x, int y, float color);
};
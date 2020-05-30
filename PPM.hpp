#include <iostream>

class PPM
{
    private:
        const char * filename;
        int m_image_size;
        unsigned char * m_image;
        const int maxColorComponentValue = 255;
        FILE * fp;
    public:
        PPM(int image_size);
        PPM(int image_size, unsigned char * image);
        void createImage(const char * name);
        void setPixel(int x, int y, int color);
        int getPixel(int x, int y);
        int getSize() { return m_image_size;};
};
#include "PPM.hpp"

PPM::PPM(int image_size) : m_image_size(image_size)
{
    m_image = new unsigned char [m_image_size * m_image_size];
};
PPM::PPM(int image_size, unsigned char * image) : m_image_size(image_size), m_image(image){};

void PPM::createImage()
{
    fp = fopen(filename, "wb");
    fprintf(fp, "P5\n %s\n %d\n %d\n %d\n", "#ok", m_image_size, m_image_size, maxColorComponentValue);
    fwrite(m_image, sizeof(unsigned char) * m_image_size * m_image_size, 1, fp);
    fclose(fp);
}
void PPM::setPixel(int x, int y, float color)
{
    m_image[x + y * m_image_size] += color;
}
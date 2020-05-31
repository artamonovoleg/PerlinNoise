#include "PPM.hpp"
#include <fstream>
#include <sstream>

PPM::PPM(int width, int height, const char * name) : m_width(width), m_height(height), filename(name)
{
    r = new int [m_width * m_height];
    g = new int [m_width * m_height];
    b = new int [m_width * m_height];
}

void PPM::drawPixel(int x, int y, int * rgb)
{
    r[x + y * m_width] = rgb [0];
    g[x + y * m_width] = rgb [1];
    b[x + y * m_width] = rgb [2];
}

void PPM::writeImage()
{
    std::ofstream inp("out.ppm", std::ios::out | std::ios::binary);
    if (inp.is_open()) 
    {
        inp << "P6\n";
        inp << m_width;
        inp << " ";
        inp << m_height << "\n";
        inp << 255 << "\n";
        char aux;
        for(int i = 0; i < m_width * m_height; i++)
        {
                aux = (char) r [i];
                inp.write(&aux, 1);
                aux = (char) g [i];
                inp.write(&aux, 1);
                aux = (char) b [i];
                inp.write(&aux, 1);
        }
    }

    inp.close();
}
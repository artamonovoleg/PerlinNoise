//
// Created by kaygalle on 24.05.2020.
//

#include <iostream>
#include <random>
#include <algorithm>
#include "PerlinNoise.hpp"
#include <math.h>

std::vector <int> PerlinNoise::p = { 151,160,137,91,90,15,                 // Hash lookup table as defined by Ken Perlin.  This is a randomly
    131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,    // arranged array of all numbers from 0-255 inclusive.
    190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
    88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
    77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
    102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
    135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
    5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
    223,183,170,213,119,248,152, 2, 44,154,163,70,221,153,101,155,167, 43,172,9,
    129,22,39,253, 19,98,108,110,79,113,224,232,178,185,112,104,218,246,97,228,
    251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
    49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
    138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
};
void PerlinNoise::setSeed(int seed)
{
    std::shuffle (p.begin(), p.end(), std::default_random_engine(seed));
}
PerlinNoise::PerlinNoise()
{

}


float PerlinNoise::lerp(float v0, float v1, float t)
{
    return ( 1.0f - t ) * v0 + t * v1;
}



int PerlinNoise::dotProduct()
{
    return 0;
}

void PerlinNoise::print()
{

}

float PerlinNoise::noise1d(int x)
{
    x = (x<<13) ^ x;
    return ( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0); 
}


double PerlinNoise::smoothNoise1d(float x)
{
     return noise1d(x)/2  +  noise1d(x-1)/4  +  noise1d(x+1)/4;
}

double PerlinNoise::interpolatedNoise1d(float x)
{
    float integerX = floor(x);
    float fractX = x - integerX;
    float v1 = smoothNoise1d(integerX);
    float v2 = smoothNoise1d(integerX + 1);
    return (lerp(v1, v2, fractX ));
}

double PerlinNoise::perlinNoise1d(float x)
{
    double total = 0;
    float p = m_persistence;
    int n = m_octaves - 1;
    for (int i = 0; i < n; i++)
    {
        float frequency = powf(2,i);
        float amplitude = powf(p, i);
        total += interpolatedNoise1d(x * frequency) * amplitude;
    }
    return (total);
}

float PerlinNoise::noise2d(int x, int y)
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    return ( 1.0f - ( (n * (n * n * 15731 + 789221)
     + 1376312589) & 0x7fffffff) / 1073741824.0);  
}

double PerlinNoise::smoothNoise2d(float x, float y)
{
    float corners = ( noise2d(x-1, y-1)+noise2d(x+1, y-1)
    + noise2d(x-1, y+1) + noise2d(x+1, y+1) ) / 16;
    float sides =  ( noise2d(x-1, y)  +noise2d(x+1, y)  +noise2d(x, y-1)  +noise2d(x, y+1) ) /  8;
    float center = noise2d(x, y) / 4;
    return corners + sides + center;
}

double PerlinNoise::interpolatedNoise2d(float x, float y)
{
    float integer_X    = int(x);
    float fractional_X = x - integer_X;
    float integer_Y    = int(y);
    float fractional_Y = y - integer_Y;
    float v1 = smoothNoise2d(integer_X,     integer_Y);
    float v2 = smoothNoise2d(integer_X + 1, integer_Y);
    float v3 = smoothNoise2d(integer_X,     integer_Y + 1);
    float v4 = smoothNoise2d(integer_X + 1, integer_Y + 1);
    float i1 = lerp(v1 , v2 , fractional_X);
    float i2 = lerp(v3 , v4 , fractional_X);
    return lerp(i1 , i2 , fractional_Y);
}

double PerlinNoise::perlinNoise2d(float x, float y)
{
    double total = 0;
    float p = m_persistence;
    int n = m_octaves - 1;
    for (int i = 0; i < n; i++)
    {
        float frequency = powf(2,i);
        float amplitude = powf(p, i);
        total += interpolatedNoise2d(x * frequency, y * frequency) * amplitude;
    }
    return total;
}

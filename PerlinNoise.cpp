//
// Created by kaygalle on 24.05.2020.
//

#include <iostream>
#include <random>
#include "PerlinNoise.hpp"
#include <math.h>

PerlinNoise::PerlinNoise()
{
    //std::mt19937_64 gen(m_seed);
}


float PerlinNoise::lerp(float v0, float v1, float t)
{
    return ( 1.0f - t ) * v0 + t * v1;
}



int PerlinNoise::dotProduct()
{
    return 0;
}

void PerlinNoise::setSeed(int seed)
{
    m_seed = seed;
    std::mt19937_64 gen(m_seed);
    std::cout << float(float(gen() % 10) / 10)  << std::endl;
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
//
// Created by kaygalle on 24.05.2020.
//

#include <iostream>
#include <random>
#include "PerlinNoise.hpp"
#include <math.h>

PerlinNoise::PerlinNoise()
{
    std::mt19937_64 gen(m_seed);
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

double PerlinNoise::noise1d(int x)
{
    x = (x<<13) ^ x;
    return ( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0); 
}


double PerlinNoise::smoothNoise1d(int x)
{
     return noise1d(x)/2  +  noise1d(x-1)/4  +  noise1d(x+1)/4;
}
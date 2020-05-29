//
// Created by kaygalle on 24.05.2020.
//

#include <iostream>
#include <random>
#include "PerlinNoise.hpp"


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

float PerlinNoise::getNoise(unsigned int x)
{
}

float PerlinNoise::getPerlinNoise(float x, float y)
{

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
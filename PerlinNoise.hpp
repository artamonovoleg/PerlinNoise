//
// Created by kaygalle on 24.05.2020.
//
#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

#include <vector>
#include <algorithm>
#include <random>

struct vec3
{
    int x;
    int y;
    int z;
};
class PerlinNoise
{
    private:
        static vec3 grad3 [12];
        static std::vector <int> p;
        static int fastfloor(double x);
        static double dot_product(vec3 g, double x, double y, double z);
        static double lerp (double a, double b, double t);
        static double fade(double t);
    public:
        PerlinNoise();
        static void setSeed(int seed);
        static double PerlinNoise_3D(double x, double y, double z);
};



#endif //MINECRAFT_PERLINNOISE_HPP

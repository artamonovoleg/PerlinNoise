//
// Created by kaygalle on 24.05.2020.
//

#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

class PerlinNoise
{
    private:
        unsigned int m_seed = 133;
        int m_octaves = 8;
        float m_persistence = .5f;
    public:
        PerlinNoise();

        float getNoise(unsigned int x);
        float lerp(float v0, float v1, float t);
        float getPerlinNoise(float x, float y);
        int dotProduct();

        void setOctaves(int amount) { m_octaves = amount; };
        void setSeed(int seed);
        float noise1d(int x);
        double smoothNoise1d(float x);
        double interpolatedNoise1d(float x);
        double noise2d(double x, double y);
        double perlinNoise1d(float x);
        void print();
};



#endif //MINECRAFT_PERLINNOISE_HPP

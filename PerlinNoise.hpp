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
        static std::vector <int> p;
    public:
        PerlinNoise();
        float getNoise(unsigned int x);
        float lerp(float v0, float v1, float t);
        float getPerlinNoise(float x, float y);
        float fade(double t);
        float grad(int hash, double x, double y, double z);
        void setSeed(int seed);
        void setPerm();
        double interpolateNoise3d(double x, double y, double z);
};



#endif //MINECRAFT_PERLINNOISE_HPP

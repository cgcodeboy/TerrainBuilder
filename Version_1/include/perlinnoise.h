#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <math.h>

class PerlinNoise
{
public:
    static PerlinNoise* getInstance();

    static void setPersistence(float persistence);

    static void setNumOfOctaves(int num);

    float getNoiseValue(float x,float y);

private:
    PerlinNoise();
    PerlinNoise(PerlinNoise &noise);
    PerlinNoise& operator=(PerlinNoise& noise);

    float interpolatedNoise(float x,float y);

    float smoothedNoise(int x,int y);

    float cosine_Interpolate(float x,float y,float z);

    float noise(int x,int y);

    static PerlinNoise* _noise;

    static float _persistence;
    static int _octaves;
};

#endif // PERLINNOISE_H

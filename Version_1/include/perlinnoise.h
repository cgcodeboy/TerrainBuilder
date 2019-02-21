#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <math.h>
#include <QDebug>

/**
 * @brief The PerlinNoise class
 *
 * This class is used to generate the perlin noise.
 *
 * Input: persistence and octaves
 *
 * Output: perlin noise value
 */


class PerlinNoise
{
public:
    PerlinNoise();

    void set(double persistence, double frequency, double amplitude, int octaves, int randomseed);

    void setPersistence(float persistence);

    void setFrequency(float frequency);

    void setAmplitude(float amplitude);

    void setOctaves(int octaves);

    void setRandomSeed(int randomseed);

    float getNoiseValue(float x,float y);

private:
    PerlinNoise(PerlinNoise &noise);
    PerlinNoise& operator=(PerlinNoise& noise);

    float smoothedNoise(int x,int y);

    float total(float i, float j);

    float getValue(float x, float y);

    float interpolate(float x, float y, float a);

    float noise(int x, int y);

    float _persistence;
    float _frequency;
    float _amplitude;
    int _randomseed;
    int _octaves;
};

#endif // PERLINNOISE_H

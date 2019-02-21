#include "include/perlinnoise.h"

PerlinNoise::PerlinNoise()
{

}

void PerlinNoise::set(double persistence, double frequency, double amplitude, int octaves, int randomseed)
{
    _persistence = persistence;
    _frequency = frequency;
    _amplitude  = amplitude;
    _octaves = octaves;
    _randomseed = 2 + randomseed * randomseed;
}

void PerlinNoise::setPersistence(float persistence)
{
    _persistence = persistence;
}

void PerlinNoise::setOctaves(int octaves)
{
    _octaves = octaves;
}

void PerlinNoise::setRandomSeed(int randomseed)
{
    _randomseed = randomseed;
}

void PerlinNoise::setFrequency(float frequency)
{
    _frequency = frequency;
}

void PerlinNoise::setAmplitude(float amplitude)
{
    _amplitude = amplitude;
}

float PerlinNoise::getNoiseValue(float x, float y)
{
    qDebug()<<total(x,y);
    return _amplitude * total(x, y);
}

float PerlinNoise::noise(int x, int y)
{
    int n = x + y * 57;
    n = (n<<13) ^ n;
    return ( 1.0 - ( (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}

float PerlinNoise::total(float i, float j)
{
    float t = 0.0f;
    float amplitude = 1;
    float freq = _frequency;

    for(int k = 0; k < _octaves; k++)
    {
        t += getValue(j * freq + _randomseed, i * freq + _randomseed) * _amplitude;
        amplitude *= _persistence;
        freq *= 2;
    }

    return t;
}

float PerlinNoise::getValue(float x, float y)
{
    int Xint = (int)x;
    int Yint = (int)y;
    float Xfrac = x - Xint;
    float Yfrac = y - Yint;

    //noise values
    float n01 = noise(Xint-1, Yint-1);
    float n02 = noise(Xint+1, Yint-1);
    float n03 = noise(Xint-1, Yint+1);
    float n04 = noise(Xint+1, Yint+1);
    float n05 = noise(Xint-1, Yint);
    float n06 = noise(Xint+1, Yint);
    float n07 = noise(Xint, Yint-1);
    float n08 = noise(Xint, Yint+1);
    float n09 = noise(Xint, Yint);

    float n12 = noise(Xint+2, Yint-1);
    float n14 = noise(Xint+2, Yint+1);
    float n16 = noise(Xint+2, Yint);

    float n23 = noise(Xint-1, Yint+2);
    float n24 = noise(Xint+1, Yint+2);
    float n28 = noise(Xint, Yint+2);

    float n34 = noise(Xint+2, Yint+2);

    //find the noise values of the four corners
    float x0y0 = 0.0625*(n01+n02+n03+n04) + 0.125*(n05+n06+n07+n08) + 0.25*(n09);
    float x1y0 = 0.0625*(n07+n12+n08+n14) + 0.125*(n09+n16+n02+n04) + 0.25*(n06);
    float x0y1 = 0.0625*(n05+n06+n23+n24) + 0.125*(n03+n04+n09+n28) + 0.25*(n08);
    float x1y1 = 0.0625*(n09+n16+n28+n34) + 0.125*(n08+n14+n06+n24) + 0.25*(n04);

    //interpolate between those values according to the x and y fractions
    float v1 = interpolate(x0y0, x1y0, Xfrac); //interpolate in x direction (y)
    float v2 = interpolate(x0y1, x1y1, Xfrac); //interpolate in x direction (y+1)
    float fin = interpolate(v1, v2, Yfrac);  //interpolate in y direction

    return fin;
}

float PerlinNoise::interpolate(float x, float y, float a)
{
    double negA = 1.0 - a;
    double negASqr = negA * negA;
    double fac1 = 3.0 * (negASqr) - 2.0 * (negASqr * negA);
    double aSqr = a * a;
    double fac2 = 3.0 * aSqr - 2.0 * (aSqr * a);

    return x * fac1 + y * fac2;
}

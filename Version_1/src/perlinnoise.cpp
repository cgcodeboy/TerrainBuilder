#include "include/perlinnoise.h"

PerlinNoise* PerlinNoise::_noise = 0;

float PerlinNoise::_persistence = 0.5;

int PerlinNoise::_octaves = 4;

PerlinNoise::PerlinNoise()
{

}


PerlinNoise *PerlinNoise::getInstance()
{
    if(_noise == 0)
        _noise = new PerlinNoise;
    return _noise;
}

void PerlinNoise::setPersistence(float persistence)
{
    PerlinNoise::_persistence = persistence;
}

void PerlinNoise::setNumOfOctaves(int num)
{
    PerlinNoise::_octaves = num;
}

float PerlinNoise::getNoiseValue(float x, float y)
{
    float total = 0;
    float p = _persistence;
    int n = _octaves;
    for(int i=0; i<n; i++){
        float frequency = powf(2,i);
        float amplitude = powf(p,i);
        total = total + interpolatedNoise(x * frequency, y * frequency) * amplitude;
    }
    return total;
}

float PerlinNoise::interpolatedNoise(float x, float y)
{
    int integer_X = int(x);
    float  fractional_X = x - integer_X;
    int integer_Y = int(y);
    float fractional_Y = y - integer_Y;
    float v1 = smoothedNoise(integer_X, integer_Y);
    float v2 = smoothedNoise(integer_X + 1, integer_Y);
    float v3 = smoothedNoise(integer_X, integer_Y + 1);
    float v4 = smoothedNoise(integer_X + 1, integer_Y + 1);
    float i1 = cosine_Interpolate(v1, v2, fractional_X);
    float i2 = cosine_Interpolate(v3, v4, fractional_X);
    return cosine_Interpolate(i1, i2, fractional_Y);
}

float PerlinNoise::smoothedNoise(int x, int y)
{
    double corners = ( noise(x-1, y-1)+noise(x+1, y-1)+noise(x-1, y+1)+noise(x+1, y+1) ) / 16;
    double sides = ( noise(x-1, y) +noise(x+1, y) +noise(x, y-1) +noise(x, y+1) ) / 8;
    double center = noise(x, y) / 4;
    return corners + sides + center;
}

float PerlinNoise::cosine_Interpolate(float a, float b, float x)
{
    float ft = x * 3.1415927;
    float f = (1 - cos(ft)) * 0.5;
    return a*(1-f) + b*f;
}

float PerlinNoise::noise(int x, int y)
{
    int n = x + y * 57;
    n = (n<<13) ^ n;
    return ( 1.0 - ( (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}

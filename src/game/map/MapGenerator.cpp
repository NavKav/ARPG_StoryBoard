//
// Created by navid on 11/06/2022.
//
#include <unistd.h>
#include <synchapi.h>
#include "MapGenerator.h"

using namespace std;

MapGenerator::MapGenerator(unsigned int seed) :
_seed(seed),
_perlinNoise(_seed)
{
    srand(_seed);
    _currentMap = GROUND;
}

void MapGenerator::display() {
    //for debugging purpose
}

void MapGenerator::setCurrentMap(unsigned int cm) {
    _currentMap = cm % 3;
}

Uint MapGenerator::operator()(unsigned int x, unsigned int y) {
        return getBlock(x, y);
}

bool MapGenerator::sameTile(unsigned int x, unsigned int y, unsigned int d) {
    switch (d) {
        case 1:
            if (getBlock(x - 1,y + 1) != getBlock(x, y))
                return false;
            return true;
        case 2:
            if ( getBlock(x, y + 1) != getBlock(x, y))
                return false;
            return true;
        case 3:
            if (getBlock(x + 1,y + 1) != getBlock(x, y))
                return false;
            return true;
        case 4:
            if (getBlock(x + 1, y) != getBlock(x, y))
                return false;
            return true;
        case 5:
            if (getBlock(x + 1,y - 1) != getBlock(x, y))
                return false;
            return true;
        case 6:
            if (getBlock(x,y - 1) != getBlock(x, y))
                return false;
            return true;
        case 7:
            if (getBlock(x - 1, y - 1) != getBlock(x, y))
                return false;
            return true;
        default :
            if (getBlock(x - 1, y) != getBlock(x, y))
                return false;
            return true;
    }
}

Uint MapGenerator::getBlock(int x, int y){
    float noiseHeight = computeNoiseHeight(x, y);
    if (_currentMap == GROUND) {
        return getGroundBlock(x, y, noiseHeight);
    } else if (_currentMap == LIQUID) {
        return getLiquidBlock(x, y, noiseHeight);
    } else { //_currentMap == ASPECT
        return getAspectBlock(x, y, noiseHeight);
    }
}

/* Default :
 * scale  = 100
 * persistence= 0.5
 * lacunarity = 2
 * octave = 5
 * amplitude = 1
 * frequency = 1
 * */
float MapGenerator::computeNoiseHeight(int x, int y) {
    float scale = 100, persistence= 0.5, lacunarity = 2;
    int octave = 5;
    double tmp;

    float amplitude = 1;
    float frequency = 1.5;
    float noiseHeight = 0;
    for (unsigned int aux = 0; aux < octave; aux++) {
        double sx = x / scale * frequency /*+ offset[aux].first*/;
        double sy = y / scale * frequency /*+ offset[aux].second*/;
        tmp = _perlinNoise.noise(sx, sy) * 2 - 1;
        noiseHeight += tmp * amplitude;

        amplitude *= persistence;
        frequency *= lacunarity;
    }

    return noiseHeight;
}

Uint MapGenerator::getGroundBlock(int x, int y, float noiseHeight) {
    if (noiseHeight < -0.1)
    {
        return 80;
    }
    else if (noiseHeight < -0.07)
    {
        return 80;
    }
    else if (noiseHeight < 0.4)
    {
        return 81;
    }
    else if (noiseHeight < 0.8)
    {
        return 83;
    }
    else if (noiseHeight < 0.9)
    {
        return 83;
    }
    else
    {
        return 83;
    }
}

Uint MapGenerator::getLiquidBlock(int x, int y, float noiseHeight) {
    if (noiseHeight < -0.1)
    {
        return 66;
    }
    else
    {
        return 143;
    }
}

Uint MapGenerator::getAspectBlock(int x, int y, float noiseHeight) {
    if (getGroundBlock(x, y, noiseHeight) == 81 && (int)(noiseHeight*100) % 2) {
        return 67;
    }
    return 0;
}

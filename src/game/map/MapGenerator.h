//
// Created by navid on 11/06/2022.
//

#ifndef ARPG_STORYBOARD_MAPGENERATOR_H
#define ARPG_STORYBOARD_MAPGENERATOR_H

#include <iostream>
#include <stdlib.h>
#include <utility>
#include "PerlinNoise.h"

#define GROUND 0
#define LIQUID 1
#define ASPECT 2

typedef unsigned int Uint;

class MapGenerator {
public:
    MapGenerator(){};
    MapGenerator(unsigned int seed);
    ~MapGenerator(){};
    void generate() const;
    void display(); /* debug */
    Uint operator()(unsigned int x, unsigned int y);
    bool sameTile(unsigned int x, unsigned int y, unsigned int d);
    void setCurrentMap(unsigned int cm);
    Uint getBlock(int x, int y);

private:
    float computeNoiseHeight(int x, int y);
    Uint getGroundBlock(int x, int y, float noiseHeight);
    Uint getLiquidBlock(int x, int y, float noiseHeight);
    Uint getAspectBlock(int x, int y, float noiseHeight);

    PerlinNoise _perlinNoise;

    unsigned int _seed;
    Uint _currentMap;
};


#endif //ARPG_STORYBOARD_MAPGENERATOR_H

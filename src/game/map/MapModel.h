//
// Created by navid on 11/06/2022.
//

#ifndef ARPG_STORYBOARD_MAPMODEL_H
#define ARPG_STORYBOARD_MAPMODEL_H

#include <iostream>
#include <cstdlib>
#include <utility>
#include "PerlinNoise.h"

#define GROUND 0
#define LIQUID 1
#define ASPECT 2

typedef unsigned int Uint;

class MapModel {
public:
    MapModel(){};
    MapModel(unsigned int seed);
    ~MapModel(){};
    void generate() const;
    void display(); /* debug */
    std::string operator()(unsigned int x, unsigned int y);
    bool sameTile(unsigned int x, unsigned int y, unsigned int d);
    void setCurrentMap(unsigned int cm);
    std::string getBlock(int x, int y);

private:
    float computeNoiseHeight(int x, int y);
    std::string getGroundBlock(int x, int y, float noiseHeight);
    std::string getLiquidBlock(int x, int y, float noiseHeight);
    std::string getAspectBlock(int x, int y, float noiseHeight);

    PerlinNoise _perlinNoise;

    unsigned int _seed;
    Uint _currentMap;
};

enum GroundBlockId {
    PLAIN,
    DESERT
};

enum LiquidBlockId {
    OCEAN,
    SEA
};

enum AspectBlockId {
    GRASS
};

#endif //ARPG_STORYBOARD_MAPMODEL_H

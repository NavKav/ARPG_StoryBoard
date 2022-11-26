//
// Created by navid on 11/06/2022.
//

#ifndef ARPG_STORYBOARD_MAPGENERATOR_H
#define ARPG_STORYBOARD_MAPGENERATOR_H

#include <iostream>
#include <stdlib.h>
#include <utility>
#include "game/map/PerlinNoise.h"

#define GROUND 1
#define LIQUID 2
#define MOUNT 3

typedef unsigned int Uint;

class MapGenerator {
public:
    MapGenerator(){};
    MapGenerator(unsigned int X, unsigned int Y, unsigned int seed);
    ~MapGenerator();
    void generate() const;
    void blank();
    void display(); /* debug */
    Uint& operator()(unsigned int x, unsigned int y);
    bool sameTile(unsigned int x, unsigned int y, unsigned int d);
    void setCurrentMap(unsigned int cm);
    unsigned int getY() const;
    unsigned int getX() const;

private:
    void blockFromPerlin(double i, double j, float noiseHeight) const;

    unsigned int _X = 1, _Y = 1;

private:
    unsigned int _seed;
    Uint trashBlock = 695;
    Uint** _mapGround;
    Uint** _mapLiquid;
    Uint** _currentMap;
};


#endif //ARPG_STORYBOARD_MAPGENERATOR_H

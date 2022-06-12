//
// Created by navid on 11/06/2022.
//

#ifndef ARPG_STORYBOARD_MAPGENERATOR_H
#define ARPG_STORYBOARD_MAPGENERATOR_H

#include <iostream>
#include <stdlib.h>


class MapGenerator {
public:
    MapGenerator(unsigned int X, unsigned int Y, unsigned int seed);
    ~MapGenerator();
    void generate();
    void blank();
    void display();
private:
    unsigned int _X, _Y;
    unsigned int _seed;
    unsigned int** _map;
};


#endif //ARPG_STORYBOARD_MAPGENERATOR_H

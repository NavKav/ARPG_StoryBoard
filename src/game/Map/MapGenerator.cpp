//
// Created by navid on 11/06/2022.
//

#include "game/Map/MapGenerator.h"

using namespace std;

MapGenerator::MapGenerator(unsigned int X, unsigned int Y, unsigned int seed) :
_X(X),
_Y(Y),
_seed(seed)
{
    _map = new unsigned int*[_X];
    for (unsigned int i = 0; i < _X; i++) {
        _map[i] = new unsigned int[_Y];
    }

}

MapGenerator::~MapGenerator() {
    for (unsigned int i = 0; i < _X; i++) {
        delete _map[i];
    }
    delete _map;
}

void MapGenerator::generate() {
    srand(_seed);
    rand();
    _map[1][1] = 0;
}

void MapGenerator::blank() {
    for (unsigned int i = 0; i < _X; i++) {
        for (unsigned int j = 0; j < _Y; j++) {
            _map[i][j] = 0;
        }
    }
}

void MapGenerator::display() {
    for (unsigned int i = 0; i < _X; i++) {
        for (unsigned int j = 0; j < _Y; j++) {
            cout << _map[i][j];
        }
        cout << endl;
    }
}
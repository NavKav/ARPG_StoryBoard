//
// Created by navid on 11/06/2022.
//

#include "game/map/MapGenerator.h"

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

    blank();
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

unsigned int& MapGenerator::operator()(unsigned int x, unsigned int y) {
    if (x <_X && y <_Y) {
        return _map[x][y];
    }
    return _map[0][0];
}

bool MapGenerator::sameTile(unsigned int x, unsigned int y, unsigned int d) {
    switch (d) {
        case 1:
            if (x <= 0 || y <= 0 || _map[x - 1][y - 1] != _map[x][y])
                return false;
            return true;
        case 2:
            if (y <= 0 || _map[x][y - 1] != _map[x][y])
                return false;
            return true;
        case 3:
            if (x >= _X - 1 || y <= 0 || _map[x + 1][y - 1] != _map[x][y])
                return false;
            return true;
        case 4:
            if (x >= _X - 1 || _map[x + 1][y] != _map[x][y])
                return false;
            return true;
        case 5:
            if (x >= _X - 1 || y >= _Y - 1 || _map[x + 1][y + 1] != _map[x][y])
                return false;
            return true;
        case 6:
            if (y >= _Y - 1 || _map[x][y + 1] != _map[x][y])
                return false;
            return true;
        case 7:
            if (x <= 0 || y >= _Y - 1 || _map[x - 1][y + 1] != _map[x][y])
                return false;
            return true;
        default :
            if (x <= 0 || _map[x - 1][y] != _map[x][y])
                return false;
            return true;
    }
}
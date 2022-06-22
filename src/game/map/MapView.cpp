//
// Created by navid on 18/06/2022.
//

#include "game/map/MapView.h"

using namespace std;

MapView::MapView(Window& window, MapGenerator& mapGenerator) :
_window(window),
_mapGenerator(mapGenerator)
{
}

void MapView::display(unsigned int x, unsigned int y, unsigned int w, unsigned int h) {
    _window.open("floor", "floor.jpg");
    for (unsigned int i = x; i < x + w; i++) {
        for (unsigned int j = y; j < y + h; j++) {
            drawLeftUp(i, j);
            drawRightUp(i, j);
            drawBottomLeft(i, j);
            drawBottomRight(i, j);
        }
    }
    _window.close("floor");
}


void MapView::drawLeftUp(unsigned int x, unsigned int y) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int n = _mapGenerator(x ,y);
    X0 += n * 64;
    unsigned int A = X0, B = Y0;
    unsigned int X = x * 32, Y = y * 32;
    if (_mapGenerator.sameTile(x, y, 2)
        && _mapGenerator.sameTile(x, y, 8)) {
        if (_mapGenerator.sameTile(x, y, 1)) {
            A += 32; B += 32 + 32;
        } else {
            A += 32; B += 0;
        }
    } else if (!_mapGenerator.sameTile(x, y, 2)
               && _mapGenerator.sameTile(x, y, 8)) {
        A += 32; B += 32;
    } else if (_mapGenerator.sameTile(x, y, 2)
               && !_mapGenerator.sameTile(x, y, 8)) {
        A += 0; B += 32 + 32;
    } else {
        A += 0; B += 32;
    }
    _window.drawPartIMG("floor", X, Y, A, B, 16, 16);
}

void MapView::drawRightUp(unsigned int x, unsigned int y) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int n = _mapGenerator(x ,y);
    X0 += n * 64;
    unsigned int A = X0, B = Y0;
    unsigned int X = x * 32 + 16, Y = y * 32;
    if (_mapGenerator.sameTile(x, y, 2)
        && _mapGenerator.sameTile(x, y, 4)) {
        if (_mapGenerator.sameTile(x, y, 3)) {
            A += 16; B += 64;
        } else {
            A += 32 + 16; B += 0;
        }
    } else if (!_mapGenerator.sameTile(x, y, 2)
               && _mapGenerator.sameTile(x, y, 4)) {
        A += 16; B += 32;
    } else if (_mapGenerator.sameTile(x, y, 2)
               && !_mapGenerator.sameTile(x, y, 4)) {
        A += 32 + 16; B += 64;
    } else {
        A += 32 + 16; B += 32;
    }
    _window.drawPartIMG("floor", X, Y, A, B, 16, 16);
}

void MapView::drawBottomLeft(unsigned int x, unsigned int y) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int n = _mapGenerator(x ,y);
    X0 += n * 64;
    unsigned int A = X0, B = Y0;
    unsigned int X = x * 32, Y = y * 32 + 16;
    if (_mapGenerator.sameTile(x, y, 6)
        && _mapGenerator.sameTile(x, y, 8)) {
        if (_mapGenerator.sameTile(x, y, 7)) {
            A += 32; B += 32 + 16;
        } else {
            A += 32; B += 16;
        }
    } else if (!_mapGenerator.sameTile(x, y, 6)
               && _mapGenerator.sameTile(x, y, 8)) {
        A += 32; B += 64 + 16;
    } else if (_mapGenerator.sameTile(x, y, 6)
               && !_mapGenerator.sameTile(x, y, 8)) {
        A += 0; B += 32 + 16;
    } else {
        A += 0; B += 64 + 16;
    }
    _window.drawPartIMG("floor", X, Y, A, B, 16, 16);
}

void MapView::drawBottomRight(unsigned int x, unsigned int y) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int n = _mapGenerator(x ,y);
    X0 += n * 64;
    unsigned int A = X0, B = Y0;
    unsigned int X = x * 32 + 16, Y = y * 32 + 16;
    if (_mapGenerator.sameTile(x, y, 4)
        && _mapGenerator.sameTile(x, y, 6)) {
        if (_mapGenerator.sameTile(x, y, 5)) {
            A += 16; B += 32 + 16;
        } else {
            A += 32 + 16; B += 16;
        }
    } else if (!_mapGenerator.sameTile(x, y, 4)
               && _mapGenerator.sameTile(x, y, 6)) {
        A += 32 + 16; B += 32 + 16;
    } else if (_mapGenerator.sameTile(x, y, 4)
               && !_mapGenerator.sameTile(x, y, 6)) {
        A += 16; B += 64 + 16;
    } else {
        A += 32 + 16; B += 64 + 16;
    }
    _window.drawPartIMG("floor", X, Y, A, B, 16, 16);
}
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
    _window.open("grounds", "grounds.jpg");
    for (unsigned int i = 0; i < w; i++) {
        for (unsigned int j = 0; j < h; j++) {
            drawLeftUp(x + i, y + j, i, j);
            drawRightUp(x + i, y + j, i, j);
            drawBottomLeft(x + i, y + j, i, j);
            drawBottomRight(x + i, y + j, i, j);
        }
    }
    _window.close("grounds");
}


void MapView::drawLeftUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int f , s;
    string file;
    getCaseView(f, s, file, x, y);
    X0 += f * 64;
    Y0 += s * 96;
    unsigned int A = X0, B = Y0;
    unsigned int X = a * 32, Y = b * 32;
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
    _window.drawPartIMG(file, X, Y, A, B, 16, 16);
}

void MapView::drawRightUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int f , s;
    string file;
    getCaseView(f, s, file, x, y);
    X0 += f * 64;
    Y0 += s * 96;
    unsigned int A = X0, B = Y0;
    unsigned int X = a * 32 + 16, Y = b * 32;
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
    _window.drawPartIMG(file, X, Y, A, B, 16, 16);
}

void MapView::drawBottomLeft(unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int f , s;
    string file;
    getCaseView(f, s, file, x, y);
    X0 += f * 64;
    Y0 += s * 96;
    unsigned int A = X0, B = Y0;
    unsigned int X = a * 32, Y = b * 32 + 16;
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
    _window.drawPartIMG(file, X, Y, A, B, 16, 16);
}

void MapView::drawBottomRight(unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int f , s; // first, second
    string file;
    getCaseView(f, s, file, x, y);
    X0 += f * 64;
    Y0 += s * 96;
    unsigned int A = X0, B = Y0;
    unsigned int X = a * 32 + 16, Y = b * 32 + 16;
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
    _window.drawPartIMG(file, X, Y, A, B, 16, 16);
}

void MapView::getCaseView(unsigned int& f, unsigned int& s, string& file,unsigned int& x, unsigned int& y) {
    unsigned int c = _mapGenerator(x, y);
    f = c % 6;
    s = c / 6;
    file = "grounds";
}
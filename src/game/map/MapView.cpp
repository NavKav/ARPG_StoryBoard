//
// Created by navid on 18/06/2022.
//

#include "MapView.h"

using namespace std;

MapView::MapView(Window& window, MapModel& mapGenerator) :
_window(window),
_mapGenerator(mapGenerator)
{
    _X = (int)window.getX()/BLOCK_SIZE;
    _Y = (int)window.getY()/BLOCK_SIZE;

    _drawBlock = new bool*[_X + 1];
    for (unsigned int i = 0; i < _X + 1; i++)
        _drawBlock[i] = new bool[_Y + 1];

    setDrawBlockValue(true);
}

void MapView::setDrawBlockValue(bool v) {
    for (unsigned int i = 0; i < _X + 1; i++) {
        for (unsigned int j = 0; j < _Y + 1; j++) {
            _drawBlock[i][j] = v;
        }
    }
}

MapView::~MapView() {
    for (unsigned int i = 0; i < _X + 1; i++) {
        delete[] _drawBlock[i];
    }
    delete[] _drawBlock;
}

void MapView::displayGround(int x, int y) {
    _floorName = "ground";
    _mapGenerator.setCurrentMap(GROUND);
    display(x, y);
}

void MapView::displayLiquid(int x, int y) {
    _floorName = "liquid";
    _mapGenerator.setCurrentMap(LIQUID);
    display(x, y);
}

void MapView::display(int x, int y) {
    _window.open(_floorName, _floorName + ".jpg");
    for (int i = 0; i < _X + 1; i++) {
        for (int j = 0; j < _Y + 1; j++) {
            if (_drawBlock[i][j]) {
                if (_mapGenerator(x + i, y - j) != 143) {
                    drawLeftUp(x + i, y - j, i, j);
                    drawRightUp(x + i, y - j, i, j);
                    drawBottomLeft(x + i, y - j, i, j);
                    drawBottomRight(x + i, y - j, i, j);
                }
            }
            /*_window.changeFont("arial", 9);
            _window.changeColor(0, 0, 0);
            _window.writeText(i * BLOCK_SIZE, j * BLOCK_SIZE, to_string(x + i) + "," + to_string(y - j));*/
        }
    }
    _window.close(_floorName);
}


void MapView::drawLeftUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
    unsigned int X0 = 0, Y0 = 0;
    unsigned int f , s;
    string file;
    getCaseView(f, s, file, x, y);
    X0 += f * 64;
    Y0 += s * 96;
    unsigned int A = X0, B = Y0;
    int X = a * 32, Y = b * 32;
    X -= _XShift; Y -= _YShift;
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
    int X = a * 32 + 16, Y = b * 32;
    X -= _XShift; Y -= _YShift;
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
    int X = a * 32, Y = b * 32 + 16;
    X -= _XShift; Y -= _YShift;
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
    int X = a * 32 + 16, Y = b * 32 + 16;
    X -= _XShift; Y -= _YShift;
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
    file = _floorName;
}

void MapView::displayFromCoordinate(double x, double y) {
    _XShift = BLOCK_SIZE * CORRECT_SHIFT_X(modf(x, NULL)) + (_X % 2 ? BLOCK_SIZE / 2 : 0);
    _YShift = BLOCK_SIZE * CORRECT_SHIFT_Y(modf(y, NULL)) + (_Y % 2 ? BLOCK_SIZE / 2 : 0);

    int xCenter, yCenter;
    cornerFromCenter(x, y, xCenter, yCenter);
    setDrawBlockValue(true);
    displayAll(xCenter - (x < 0 && modf(x, NULL) != 0), yCenter + (y > 0 && modf(y, NULL) != 0));
}

void MapView::shiftMap(double newX,double newY,double aBlock,double bBlock) {
    _window.drawOn(BACKGROUND);
    if (aBlock == 0 && bBlock == 0) return;

    setDrawBlockValue();
    _sX += aBlock * BLOCK_SIZE, _sY += bBlock * BLOCK_SIZE;
    _window.shift(_sX,_sY);
    _sX = modf(_sX, nullptr);
    _sY = modf(_sY, nullptr);

    _XShift = BLOCK_SIZE * CORRECT_SHIFT_X(modf(newX, NULL)) + (_X % 2 ? BLOCK_SIZE / 2 : 0);
    _YShift = BLOCK_SIZE * CORRECT_SHIFT_Y(modf(newY, NULL)) + (_Y % 2 ? BLOCK_SIZE / 2 : 0);

    int a = 0, b = 0, c = 0, d = 0;
    if (bBlock > 0) {
        a = 0;
        b = 0;
        c = _X ;
        d = (int)bBlock + 1;
    } else if (bBlock < 0) {
        a = 0;
        b = _Y + (int)bBlock - 1;
        c = _X;
        d = _Y;
    }
    changeDrawBlockValue(a, b, c,  d);

    if (aBlock > 0) {
        a = 0;
        b = 0;
        c = (int)aBlock + 1;
        d = _Y;
    } else if (aBlock < 0) {
        a = _X + (int)aBlock - 1;
        b = 0;
        c = _X;
        d = _Y;
    }
    changeDrawBlockValue(a, b, c,  d);

    int xCenter, yCenter;
    cornerFromCenter(newX, newY, xCenter, yCenter);
    displayAll(xCenter - (newX < 0 && modf(newX, NULL) != 0), yCenter + (newY > 0 && modf(newY, NULL) != 0));
}

void MapView::shiftMap(double newX, double newY, Velocity v) {
    if (ABS(v.x()) >= _X || ABS(v.y()) >= _Y) {
        displayFromCoordinate(newX, newY);
    }
    else {
        shiftMap(newX, newY, -v.x(), v.y());
    }
}

void MapView::displayAll(int x, int y) {
    displayGround(x, y);
    displayLiquid(x, y);
    //displayAspect(x, y);
}

void MapView::cornerFromCenter(double x, double y, int& a, int& b) {
    a = (int)x - _X/2 - _X%2;
    b = (int)y + _Y/2 + _Y%2;

    if (_XShift >= BLOCK_SIZE) {
        _XShift = _XShift%BLOCK_SIZE;
        a ++;
    }
    if (_YShift >= BLOCK_SIZE) {
        _YShift = _YShift%BLOCK_SIZE;
        b --;
    }
    if (_XShift <= -BLOCK_SIZE) {
        _XShift = _XShift%BLOCK_SIZE;
        a --;
    }
    if (_YShift <= -BLOCK_SIZE) {
        _YShift = _YShift%BLOCK_SIZE;
        b ++;
    }
}

void MapView::changeDrawBlockValue(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    for (unsigned int i = a; i <= c; i++) {
        for (unsigned int j = b; j <= d; j++) {
            _drawBlock[i][j] = true;
        }
    }
}

void MapView::displayAspect(int x, int y) {
    _floorName = "aspect";
    _mapGenerator.setCurrentMap(ASPECT);
    display(x, y);
}


/*
void MapView::shiftMap(double newX, double newY, double aCase, double bCase) {
    _window.shift((int)(aCase * BLOCK_SIZE), (int)(bCase * BLOCK_SIZE));

    if (aCase > 0) {
        _XShift = BLOCK_SIZE * modf(newX, NULL);
        _YShift = BLOCK_SIZE * modf(newY, NULL);
        displayAll((int)newX - halve(_X), (int)newY - halve(_Y), (int)aCase + 1, _Y + 1);
    } else if (aCase < 0) {
        _XShift = BLOCK_SIZE * (-(_X + (int)aCase) + modf(newX, NULL));
        _YShift = BLOCK_SIZE * modf(newY, NULL);
        displayAll((int)(newX + aCase) + halve(_X), (int)(newY + bCase) - halve(_Y), -(int)aCase + 1, _Y + 1);
    }
    if (bCase > 0) {
        _XShift = BLOCK_SIZE * modf(newX, NULL);
        _YShift = BLOCK_SIZE * modf(newY, NULL);
        displayAll((int)newX - halve(_X), (int)newY - halve(_Y), _X + 1, (int)bCase + 1);
    } else if (bCase < 0) {
        _XShift = BLOCK_SIZE * modf(newX, NULL);
        _YShift = BLOCK_SIZE * (-(_Y + (int)bCase) + modf(newY, NULL));
        displayAll((int)(newX + aCase) - halve(_X), (int)(newY + bCase) + halve(_Y), _X + 1, -(int)bCase + 1);
    }
}
*/
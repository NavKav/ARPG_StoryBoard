//
// Created by navid on 18/06/2022.
//

#ifndef ARPG_STORYBOARD_MAPVIEW_H
#define ARPG_STORYBOARD_MAPVIEW_H

#include "MapModel.h"
#include "core/Window.h"
#include "util/Pair.h"

#define BLOCK_SIZE 32 // size in pixel of a block in game
#define CORRECT_SHIFT_X(x) (x < 0 ? 1+x : x)
#define CORRECT_SHIFT_Y(x) (x > 0 ? 1-x : -x)
#define ABS(x) (x>0 ? x : -x)

typedef unsigned int Uint;

class MapView {
public :
    MapView(Window& window, MapModel& mapGenerator);
    void displayGround(int x, int y);
    void displayLiquid(int x, int y);
    void displayAspect(int x, int y);
    void displayAll(int x, int y);
    void displayFromCoordinate(double x, double y);
    void shiftMap(double newX,double newY,Velocity speed);
    ~MapView();
private :

    MapModel& _mapGenerator;
    Window& _window;
    string _floorName = "ground";

    int _XShift = 0, _YShift = 0;
    int _X, _Y;

    bool** _drawBlock = nullptr;
    double _sX = 0, _sY = 0;

    void display(int x, int y);
    void shiftMap(double newX,double newY,double aBlock,double bBlock);
    void drawBottomLeft(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void drawBottomRight(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void drawLeftUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void drawRightUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void getCaseView(unsigned int& f, unsigned int& s, string& file,unsigned int& x, unsigned int& y);
    void setDrawBlockValue(bool v = false);
    void changeDrawBlockValue(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    void cornerFromCenter(double x, double y, int& a, int& b);
};

double roundUp(double& x);

#endif //ARPG_STORYBOARD_MAPVIEW_H

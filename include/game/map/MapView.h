//
// Created by navid on 18/06/2022.
//

#ifndef ARPG_STORYBOARD_MAPVIEW_H
#define ARPG_STORYBOARD_MAPVIEW_H

#include "game/map/MapGenerator.h"
#include "core/Window.h"

class MapView {
public :
    MapView(Window& window, MapGenerator& mapGenerator);
    void displayGround(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
    void displayLiquid(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
private :

    MapGenerator& _mapGenerator;
    Window& _window;
    string _floorName = "ground";

    void displayFloor(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
    void drawBottomLeft(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void drawBottomRight(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void drawLeftUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void drawRightUp(unsigned int x, unsigned int y, unsigned int a, unsigned int b);
    void getCaseView(unsigned int& f, unsigned int& s, string& file,unsigned int& x, unsigned int& y);

};


#endif //ARPG_STORYBOARD_MAPVIEW_H

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
    void display(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
private :
    MapGenerator& _mapGenerator;
    Window& _window;

    void drawBottomLeft(unsigned int x, unsigned int y);
    void drawBottomRight(unsigned int x, unsigned int y);
    void drawLeftUp(unsigned int x, unsigned int y);
    void drawRightUp(unsigned int x, unsigned int y);
};


#endif //ARPG_STORYBOARD_MAPVIEW_H

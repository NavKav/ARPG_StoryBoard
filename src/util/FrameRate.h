//
// Created by navid on 27/10/2022.
//

#ifndef ARPG_STORYBOARD_FRAMERATE_H
#define ARPG_STORYBOARD_FRAMERATE_H

#include <sys/time.h>
#include <iostream>
#include "core/Window.h"

#define GAP 5


class FrameRate {
public :
    FrameRate();
    void display(Window& window);
private :
    time_t _currentTime = time(NULL);
    struct timeval _tp;
    int _previousValue = 0;
};


#endif //ARPG_STORYBOARD_FRAMERATE_H

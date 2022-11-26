//
// Created by navid on 27/10/2022.
//

#ifndef ARPG_STORYBOARD_FRAMERATE_H
#define ARPG_STORYBOARD_FRAMERATE_H

#include <sys/time.h>
#include <iostream>

class FrameRate {
public :
    FrameRate();
    void display();
private :
    time_t _currentTime = time(NULL);
    struct timeval _tp;
};


#endif //ARPG_STORYBOARD_FRAMERATE_H

//
// Created by navid on 27/10/2022.
//

#include "FrameRate.h"

using namespace std;

FrameRate::FrameRate() {
    gettimeofday(&_tp, NULL);
    _currentTime = _tp.tv_sec * 1000 + _tp.tv_usec / 1000;
}

void FrameRate::display(Window& window) {
    gettimeofday(&_tp, NULL);
    time_t t = _tp.tv_sec * 1000 + _tp.tv_usec / 1000;

    int newValue = int(1000. / double(t - _currentTime));

    if (newValue > _previousValue - GAP && newValue < _previousValue + GAP) {
        newValue = _previousValue;
    }
        window.drawOn(DEFAULT);
        window.changeColor(255, 255, 255);
        window.changeFont("arial", 20);
        window.writeText(0, 0 , to_string(newValue) + " fps");

    _currentTime = t;
    _previousValue = newValue;
}

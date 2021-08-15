#include <stdio.h>
#include <memory>
#include <windows.h>

#include "Window.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("Dice Game", 0, 0);
    window.drawIMG(0, 0, "fond.bmp");
//    cout <<
    window.drawIMG(600, 300, "start_button.bmp");
    window.drawIMG(600, 425, "option_button.bmp");
    window.drawIMG(600, 550, "exit_button.bmp");
    window.refresh();

    Sleep(2000);
    return 0;
}
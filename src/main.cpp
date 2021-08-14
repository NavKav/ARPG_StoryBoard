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
    window.refresh();

    Sleep(1000);
    return 0;
}
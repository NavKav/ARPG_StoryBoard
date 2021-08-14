#include <stdio.h>
#include <memory>
#include <windows.h>

#include "Window.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("Dice Game", 1000, 1000);
    window.drawIMG(0, 0, "fond.bmp");
    window.refresh();

    Sleep(2000);
    return 0;
}
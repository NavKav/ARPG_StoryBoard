#include <stdio.h>
#include <memory>
#include <windows.h>

#include "Window.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("test", 1000, 700);
    window.drawIMG(0, 0, "fond.png");
    window.refresh();

    Sleep(1000);
    return 0;
}

#include "Window.h"
#include "Player.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("Dice Game", 700, 700);
    window.drawIMG(0, 0, "fond.bmp");
    window.refresh();

    Player player(&window);
    player.start();
    return 0;

}
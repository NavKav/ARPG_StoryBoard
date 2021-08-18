
#include "Window.h"
#include "Player.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("Dice Game", 700, 700);
    window.drawIMG(0, 0, "fond.bmp");
    window.drawIMG(600, 300, "start_button.bmp");
    window.drawIMG(600, 425, "option_button.bmp");
    window.drawIMG(600, 550, "exit_button.bmp");
    window.refresh();

    Player player(&window);
    player.start();
    return 0;

}
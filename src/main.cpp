
#include "core/Window.h"
#include "core/Player.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 700, 700);
    window.drawIMG(0, 0, "fond.bmp");
    window.drawIMG(0, 0, "start_button.bmp");
    window.drawIMG(250, 0, "option_button.bmp");
    window.drawIMG(500, 0, "exit_button.bmp");
    window.refresh();

    Player p(nullptr);
    p.start();
    return 0;

}
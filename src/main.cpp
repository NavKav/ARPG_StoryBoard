
#include "Window.h"
#include "WindowContent.h"
#include "Player.h"
#include "MenuContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 700, 700);
    window.drawIMG(0, 0, "fond.bmp");
    window.refresh();

    MenuContent menuContent(&window);

    Player player(&menuContent);
    player.start();
    return 0;

}
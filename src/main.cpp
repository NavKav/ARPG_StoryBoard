#include "core/Window.h"
#include "core/Player.h"
#include "game/menu/MenuWindowContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 32 * 30, 32 * 30);
    window.drawIMG(0, 0, "fond.bmp");
    window.refresh();

    MenuWindowContent menuWindowContent = MenuWindowContent();

    Player p(window, reinterpret_cast<WindowContent *>(&menuWindowContent));
    p.start();

    return 0;

}
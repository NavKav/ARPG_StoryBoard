#include "core/Window.h"
#include "core/Player.h"
#include "game/GameWindowContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 32 * 22, 32 * 22);
    window.drawIMG(0, 0, "fond.bmp");
    window.changeFont("arial", 290);
    window.writeText("salut", 0, 0);
    window.refresh();

    GameWindowContent gameWindowContent = GameWindowContent();

    Player p(window, reinterpret_cast<WindowContent *>(&gameWindowContent));
    p.start();
    return 0;

}
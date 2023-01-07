#include "core/Window.h"
#include "game/menu/MenuWindowContent.h"
#include "game/GameWindowContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 32 * 22, 32 * 23);
    window.changeColor(0, 0, 0);
    window.writeText(0, 0, "salut");

    //Player p(window, new MenuWindowContent());
    //Player p(window, new OptionWindowContent());
    //Player p(window, new GameWindowContent());
    Player p(window, nullptr);
    p.start();

    return 0;

}
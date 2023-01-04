#include "core/Window.h"
#include "game/menu/MenuWindowContent.h"
#include "game/GameWindowContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 22 * 22, 41 * 22);
    window.refresh();

    //Player p(window, new MenuWindowContent());
    Player p(window, new OptionWindowContent());
    //Player p(window, new GameWindowContent());
    p.start();

    return 0;

}
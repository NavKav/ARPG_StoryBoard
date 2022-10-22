#include "core/Window.h"
#include "core/Player.h"
#include "game/menu/MenuWindowContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 32 * 30, 32 * 30);
    window.refresh();

    //Player p(window, new MenuWindowContent());
    Player p(window, new OptionWindowContent());
    p.start();

    return 0;

}
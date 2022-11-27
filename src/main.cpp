#include "core/Window.h"
#include "game/menu/MenuWindowContent.h"
#include "game/GameWindowContent.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 32 * 36, 32 * 23);
    window.drawOn(BACKGROUND);
    window.drawIMG(0,0,"fond.bmp");
    window.changeColor(0, 0, 0); // 255,255,255 = noir
    window.changeFont("arial", 50); // police arial, taille 50 pixels de hauteur
    window.writeText(0, 0, "Fullscreen"); // écrit "Fullscreen" aux coordonnées (x,y) avec la couleur/police/taille sélectionnée
    window.refresh();
    //Player p(window, new MenuWindowContent());
    //Player p(window, new OptionWindowContent());
    //Player p(window, new GameWindowContent());
    Player p(window, nullptr);
    p.start();

    return 0;

}
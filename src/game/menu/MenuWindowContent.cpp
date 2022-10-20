//
// Created by navid on 30/09/2022.
//

#include "game/menu/MenuWindowContent.h"

void MenuWindowContent::process(Player& player, Window& window) {
    bool truc = false;
    // images must be 250*70, if you want to change the dimensions, change the width and length parameters respectively
    // - 125 is width/2 to make the buttons centered
    MenuButton menuHitboxQuit(0.5*window.getX() - 125, 0.7*window.getY(), 250, 70, "/menu/Quit.png"),
    menuHitboxOption(0.5*window.getX() - 125, 0.6*window.getY(), 250, 70, "/menu/Option.png"),
    menuHitboxStart(0.5*window.getX() - 125, 0.5*window.getY(), 250, 70, "/menu/Start.png");

    if (player[SDLK_LEFTCLICK].pressed && menuHitboxQuit.isInside(player[SDLK_LEFTCLICK].mouseX,player[SDLK_LEFTCLICK].mouseY)) {
        std::cout << "quit"  << std::endl;
    }
    if (player[SDLK_LEFTCLICK].pressed && menuHitboxOption.isInside(player[SDLK_LEFTCLICK].mouseX,player[SDLK_LEFTCLICK].mouseY)) {
        std::cout << "option"  << std::endl;
    }
    if (player[SDLK_LEFTCLICK].pressed && menuHitboxStart.isInside(player[SDLK_LEFTCLICK].mouseX,player[SDLK_LEFTCLICK].mouseY)) {
        std::cout << "start"  << std::endl;
    }

    if (truc == false) {
        menuHitboxStart.display(window);
        menuHitboxOption.display(window);
        menuHitboxQuit.display(window);
        window.refresh();
        truc = true;
    }
}
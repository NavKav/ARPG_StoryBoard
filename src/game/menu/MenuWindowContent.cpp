//
// Created by navid on 30/09/2022.
//

#include "game/menu/MenuWindowContent.h"

void MenuWindowContent::process(Player& player, Window& window) {
    bool truc = false;
    MenuButton menuHitboxQuit(1, 500, 250, 70, "/menu/Quit.png"),
    menuHitboxOption(5, 600, 250, 70, "/menu/Option.png"),
    menuHitboxStart(450, 580, 250, 70, "/menu/Start.png");

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
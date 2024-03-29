//
// Created by navid on 30/09/2022.
//

#include "MenuWindowContent.h"

void MenuWindowContent::process(Player& player, Window& window) {
    bool firstTime = false;
    // images must be 250*70, if you want to change the dimensions, change the width and length parameters respectively
    // - 125 is width/2 to make the buttons centered
    MenuButton menuHitboxQuit(0.5*window.getX() - 125, 0.7*window.getY(), 250, 70, "image/menu/Quit.png"),
    menuHitboxOption(0.5*window.getX() - 125, 0.6*window.getY(), 250, 70, "image/menu/Option.png"),
    menuHitboxStart(0.5*window.getX() - 125, 0.5*window.getY(), 250, 70, "image/menu/Start.png");

    if (player[SDL_SCANCODE_LEFTCLICK].pressed && menuHitboxQuit.isInside(player[SDL_SCANCODE_LEFTCLICK].mouseX,player[SDL_SCANCODE_LEFTCLICK].mouseY)) {
        player.stop();
    }
    if (player[SDL_SCANCODE_LEFTCLICK].pressed && menuHitboxOption.isInside(player[SDL_SCANCODE_LEFTCLICK].mouseX,player[SDL_SCANCODE_LEFTCLICK].mouseY)) {
        player.setWindowContent(new OptionWindowContent());
    }
    if (player[SDL_SCANCODE_LEFTCLICK].pressed && menuHitboxStart.isInside(player[SDL_SCANCODE_LEFTCLICK].mouseX,player[SDL_SCANCODE_LEFTCLICK].mouseY)) {
        player.setWindowContent(new GameWindowContent());
    }

    if (firstTime == false) {
        window.scaleIMG(0, 0, window.getX(), window.getY(), "image/fond.bmp");
        menuHitboxStart.display(window);
        menuHitboxOption.display(window);
        menuHitboxQuit.display(window);
        window.refresh();
        firstTime = true;
    }
}
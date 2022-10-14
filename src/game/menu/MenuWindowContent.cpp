//
// Created by navid on 30/09/2022.
//

#include "game/menu/MenuWindowContent.h"

void MenuWindowContent::process(Player& player, Window& window) {
    bool truc = false;
    int quit_x = 1, quit_y = 500, dim_quit_x = 250, dim_quit_y = 70;
    int option_x = 5, option_y = 600, dim_option_x = 250, dim_option_y = 55;
    int start_x = 450, start_y = 580, dim_start_x =252, dim_start_y = 114;
/*
    if (player[SDLK_LEFTCLICK].pressed) {
        std::cout << player[SDLK_LEFTCLICK].mouseX << " " << player[SDLK_LEFTCLICK].mouseY << std::endl;
    }*/



    if (player[SDLK_LEFTCLICK].pressed && player[SDLK_LEFTCLICK].mouseX >= quit_x && player[SDLK_LEFTCLICK].mouseX <= quit_x + dim_quit_x
        && player[SDLK_LEFTCLICK].mouseY >= quit_y && player[SDLK_LEFTCLICK].mouseY <= quit_y + dim_quit_y) {
        std::cout << "quit"  << std::endl;
    }
    if (player[SDLK_LEFTCLICK].pressed && player[SDLK_LEFTCLICK].mouseX >= option_x && player[SDLK_LEFTCLICK].mouseX <= option_x + dim_option_x
        && player[SDLK_LEFTCLICK].mouseY >= option_y && player[SDLK_LEFTCLICK].mouseY <= option_y + dim_option_y) {
        std::cout << "option"  << std::endl;
    }
    if (player[SDLK_LEFTCLICK].pressed && player[SDLK_LEFTCLICK].mouseX >= start_x && player[SDLK_LEFTCLICK].mouseX <= start_x + dim_start_x
        && player[SDLK_LEFTCLICK].mouseY >= start_y && player[SDLK_LEFTCLICK].mouseY <= start_y + dim_start_y) {
        std::cout << "start"  << std::endl;
    }

    if (truc == false) {
        window.drawIMG(start_x, start_y, "menu/start.png");
        window.drawIMG(option_x, option_y, "menu/option.png");
        window.drawIMG(quit_x, quit_y, "menu/quit.png");
        window.refresh();
        truc = true;
    }
}
//
// Created by navid on 11/06/2022.
//

#include "GameWindowContent.h"

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {
    _game.process(player, window);
}
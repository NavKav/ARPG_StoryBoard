//
// Created by navid on 26/01/2023.
//

#include "HeroModel.h"

HeroModel::HeroModel(Player &player) :
_player(player)
{
    _health = 0;
    _maxHealth = 0;
    _name = "Hero";
    _movementSpeed = 1.18;
    _x = 0, _y = 0;
}


/**

 * @warning must stay thread-safe
 */
void HeroModel::play() {
    if (_player[SDL_SCANCODE_UP].pressed) {
        _decision.set(MOVE_UP);
    }
    if (_player[SDL_SCANCODE_DOWN].pressed) {
        _decision.set(MOVE_DOWN);
    }
    if (_player[SDL_SCANCODE_LEFT].pressed) {
        _decision.set(MOVE_LEFT);
    }
    if (_player[SDL_SCANCODE_RIGHT].pressed){
        _decision.set(MOVE_RIGHT);
    }
    if (_player[SDL_SCANCODE_SPACE].pressed){
        _decision.set(DO_NOTHING);
    }
}

HeroModel::HeroModel(Player& player, double x, double y) :
HeroModel(player)
{
    _x = x;
    _y = y;
}

bool HeroModel::isHero() {
    return true;
}

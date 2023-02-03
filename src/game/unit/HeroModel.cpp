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
    _movementSpeed = 0.18;
    _x = 0, _y = 0;
}

UnitModel::UnitDecision HeroModel::play() {
    if (_player[SDL_SCANCODE_UP].pressed) {
        return MOVE_UP;
    }
    if (_player[SDL_SCANCODE_DOWN].pressed) {
        return MOVE_DOWN;
    }
    if (_player[SDL_SCANCODE_LEFT].pressed) {
        return MOVE_LEFT;
    }
    if (_player[SDL_SCANCODE_RIGHT].pressed){
        return MOVE_RIGHT;
    }
    if (_player[SDL_SCANCODE_SPACE].pressed){
        return DO_NOTHING;
    }
    return DO_NOTHING;
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

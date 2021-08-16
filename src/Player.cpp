//
// Created by navid on 15/08/2021.
//

#include "Player.h"

Player::Player() {
}

void Player::start() {
    while(_boolLoop) {
        SDL_Event input;
        while(SDL_PollEvent(&input)) {
            takeInput(input);
        }
    }
}

void Player::stop() {
    _boolLoop = false;
}

Player::~Player() {
}

bool Player::isPressed(SDL_KeyCode key) {
    return _inputArr[key].pressed;
}

void Player::takeInput(const SDL_Event &event) {
    static int a = 0,b = 0;
    if (event.type == SDL_QUIT) {
        stop();
    }
    if (event.type == SDL_KEYDOWN) {
        _inputArr[event.key.keysym.sym] = {true, 0, 0};
    } else if (event.type == SDL_KEYUP) {
        _inputArr[event.key.keysym.sym] = {false, 0, 0};
    }
    if (_inputArr[SDLK_ESCAPE].pressed) {
        stop();
    }
}

void Player::getMousePosition(int& x, int& y) {
    SDL_GetMouseState(&x, &y);
}
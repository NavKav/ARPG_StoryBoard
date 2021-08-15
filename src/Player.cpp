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
            manageInput();
        }
    }
}

void Player::stop() {
    _boolLoop = false;
}

Player::~Player() {
}

void Player::manageInput() {
    if (_inputArr[SDLK_ESCAPE].pressed) {
        stop();
    }
    if (_inputArr[SDLK_a].pressed) {
    }
}

void Player::takeInput(const SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        stop();
    }
    if (event.type == SDL_KEYDOWN) {
        _inputArr[event.key.keysym.sym] = {true, 0, 0};
    } else if (event.type == SDL_KEYUP) {
        _inputArr[event.key.keysym.sym] = {false, 0, 0};
    }
}
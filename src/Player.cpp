//
// Created by navid on 15/08/2021.
//

#include "Player.h"

Player::Player(WindowContent* windowContent) : _windowContent(windowContent)
{
}

void Player::start() {
    while(_boolLoop) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            Input input = takeInput(event);
            send(input);
        }
    }
}

void Player::stop() {
    _boolLoop = false;
}

void Player::send(const Input& input) {
    if (_windowContent) {
        _windowContent->receive(input);
    }
}

Player::~Player() {
}


Input Player::takeInput(const SDL_Event &event) {
    Input input = {SDLK_UNKNOWN, 0, 0};

    if (event.type == SDL_QUIT) {
        stop();
    }
    if (event.type == SDL_KEYDOWN) {
        input.key = static_cast<SDL_KeyCode>(event.key.keysym.sym);
        input.u = time(nullptr);
        _numberKeyDown++;
    } else if (event.type == SDL_KEYUP) {
        input.key = static_cast<SDL_KeyCode>(event.key.keysym.sym);
        input.v = time(nullptr);
    }
    if (event.key.keysym.sym == SDLK_ESCAPE) {
        stop();
    }
}

void Player::getMousePosition(int& x, int& y) {
    SDL_GetMouseState(&x, &y);
}

bool Player::keyDown() {
    return !(_numberKeyDown == 0);
}
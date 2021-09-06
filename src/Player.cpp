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
    if (_windowContent != nullptr && (input.u != 0 || input.v != 0)) {
        _windowContent->receive(input);
    }
}

Player::~Player() {
}


Input Player::takeInput(const SDL_Event &event) {
    static std::set<SDL_KeyCode> pressedKeys;
    static std::set<Uint8> pressedButtons;
    Input input;

    if (event.type == SDL_KEYDOWN) {
        if (!pressedKeys.count(static_cast<SDL_KeyCode>(event.key.keysym.sym))) {
            input.key = static_cast<SDL_KeyCode>(event.key.keysym.sym);
            input.u = time(nullptr);
            _numberKeyDown++;
            pressedKeys.insert(static_cast<SDL_KeyCode>(event.key.keysym.sym));
        }
    } else if (event.type == SDL_KEYUP) {
        input.key = static_cast<SDL_KeyCode>(event.key.keysym.sym);
        input.v = time(nullptr);
        pressedKeys.erase(static_cast<SDL_KeyCode>(event.key.keysym.sym));

    } else if (event.type == SDL_MOUSEBUTTONDOWN ) {
        if (!pressedButtons.count(event.button.button)) {
            input.isMouseEvent = true;
            input.button = event.button.button;
            input.u = time(nullptr);
        }
    } else if (event.type == SDL_MOUSEBUTTONUP ) {
        input.isMouseEvent = true;
        input.button = event.button.button;
        input.v = time(nullptr);
        pressedButtons.erase(event.button.button);
    }

    if (event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT ) {
        stop();
    }
    return input;
}

bool Player::keyDown() {
    return !(_numberKeyDown == 0);
}
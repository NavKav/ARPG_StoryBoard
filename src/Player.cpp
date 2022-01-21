//
// Created by navid on 15/08/2021.
//

#include "Player.h"

Player::Player(WindowContent* windowContent) : _windowContent(windowContent)
{
}

void Player::start() {
    while(_boolLoop) {
        SDL_Event input;
        while(SDL_PollEvent(&input)) {
            takeInput(input);
            std::cout << (*this)[SDLK_a].pressed << std::endl;
        }
    }
}

void Player::stop() {
    _boolLoop = false;
}


Player::~Player() {
}

bool Player::keyDown() {
    return !(_numberKeyDown == 0);
}

void Player::takeInput(const SDL_Event &event) {
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        stop();
    }
    //std::cout << "(Player) received : " + event.key.keysym.scancode << std::endl;
    if (event.type == SDL_KEYDOWN) {
        std::cout << "une touche est enfoncée\n";
        _inputArr[event.key.keysym.sym] = {true, 0, 0};
    } else if (event.type == SDL_KEYUP) {
        std::cout << "une touche est relâchée\n";
        _inputArr[event.key.keysym.sym] = {false, 0, 0};
    } else if (event.type == SDL_MOUSEBUTTONDOWN) {
        std::cout << "une touche de la souris est enfoncée\n";
        _inputArr[event.key.keysym.sym] = {false, 0, 0};
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        std::cout << "une touche de la souris est relâchée\n";
        _inputArr[event.key.keysym.sym] = {false, 0, 0};
    }
}

Input Player::operator[](unsigned int i) {
    return _inputArr[i];
}

void Player::getMousePosition(int& x, int& y) {
    SDL_GetMouseState(&x, &y);
}

/*
void Player::start() {
    while(_boolLoop) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            Input input = takeInput(event);
            send(input);
        }

    }
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
            SDL_GetMouseState(reinterpret_cast<int *>(&(input.x)), reinterpret_cast<int *>(&(input.y)));
            input.u = time(nullptr);
        }
    } else if (event.type == SDL_MOUSEBUTTONUP ) {
        input.isMouseEvent = true;
        input.button = event.button.button;
        SDL_GetMouseState(reinterpret_cast<int *>(&(input.x)), reinterpret_cast<int *>(&(input.y)));
        input.v = time(nullptr);
        pressedButtons.erase(event.button.button);
    }

    if (event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT ) {
        stop();
    }
    return input;
}
*/
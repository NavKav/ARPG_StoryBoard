//
// Created by navid on 13/05/2021.
//

#include <iostream>

#include "Window.h"
#include <windows.h>

using namespace std;

Window::Window(const string &windowName, unsigned int sizeX, unsigned int sizeY) {
    SDL_Init(SDL_INIT_VIDEO);
    _actualWindow = SDL_CreateWindow(windowName.c_str(),
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     (int) sizeX, (int) sizeY, 0);
    if (_actualWindow == nullptr) {
        std::cout << "Window::Window() :" << SDL_GetError()
                  << std::endl;
    }
    _renderer = SDL_CreateRenderer(_actualWindow, -1, SDL_RENDERER_SOFTWARE);
    _surface = SDL_GetWindowSurface(_actualWindow);
    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    _background = SDL_ConvertSurface(_surface, _surface->format, 0);
    SDL_SetRenderTarget(_renderer,_texture);
}

Window::~Window() {
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_actualWindow);

    SDL_Quit();
}

void Window::setTitle(const std::string &windowTitle) {
    SDL_SetWindowTitle(_actualWindow, windowTitle.c_str());
}

void Window::drawIMG(int x, int y, const string &name) {
    SDL_Surface* img = IMG_Load(("ressource/image/" + name).c_str());

    if ( img == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;

    SDL_BlitSurface(img,NULL, _surface, &p);
    SDL_FreeSurface(img);
}

void Window::drawBackgroundIMG(int x, int y, const string &name) {
    SDL_Surface* img = IMG_Load(name.c_str());
    SDL_Rect p;
    p.x = x;
    p.y = y;

    SDL_BlitSurface(img,NULL, _background, &p);
    SDL_FreeSurface(img);
}

void Window::refresh() {
    /*SDL_UpdateTexture(_texture, NULL, _surface->pixels, _surface->pitch);
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderPresent(_renderer);
    */SDL_RenderPresent(_renderer);
    Sleep(20);
    drawIMG(0, 0, "fond.png");
}
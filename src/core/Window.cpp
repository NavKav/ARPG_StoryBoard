//
// Created by navid on 13/05/2021.
//
#include "core/requirement.h"
#include "core/Window.h"

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
    //SDL_SetWindowFullscreen(_actualWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
}


Window::~Window() {
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_actualWindow);

    for (auto d : _hashmap) {
        SDL_FreeSurface(d.second);
    }

    SDL_Quit();
}

void Window::setTitle(const std::string &windowTitle) {
    SDL_SetWindowTitle(_actualWindow, windowTitle.c_str());
}

void Window::drawIMG(int x, int y, const string &name) {
    SDL_Surface* img = LOAD(("ressource/image/" + name).c_str());

    if (img == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;

    SDL_BlitSurface(img,NULL, _surface, &p);
    SDL_FreeSurface(img);
}

void Window::drawBackgroundIMG(int x, int y, const string &name) {
    SDL_Surface* img = LOAD(name.c_str());
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
    SDL_RenderPresent(_renderer);*/

    SDL_RenderPresent(_renderer);
    Sleep(20);
}

void Window::clear() {
    SDL_RenderClear(_renderer);
}

void Window::drawPartIMG(unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned int c, unsigned int d, const string &name) {
    SDL_Surface* img = LOAD(("ressource/image/" + name).c_str());

    if (img == NULL) {
        cout << "Window::drawPartIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;

    SDL_Rect r;
    r.x = a;
    r.y = b;
    r.w = c;
    r.h = d;

    SDL_BlitSurface(img,&r, _surface, &p);
    SDL_FreeSurface(img);
}

void Window::open(string name, string file) {
    SDL_Surface* img = LOAD(("ressource/image/" + file).c_str());
    if (img != NULL) {
        _hashmap.insert({name, img});
    } else {
        cout << "Window::open() : " << SDL_GetError() << endl;
    }
}

void Window::close(string name) {
    if (_hashmap.find(name) == _hashmap.end()) {
        cout << "Window::close() : \"" << name << "\" wasn't found" << endl;
        return ;
    }
    _hashmap.erase(name);
}

void Window::drawIMG(const string &name, int x, int y) {
    SDL_Surface* img = _hashmap.at(name);

    if (img == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;

    SDL_BlitSurface(img,NULL, _surface, &p);
}

void Window::drawPartIMG(const string &name, unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    SDL_Surface* img = _hashmap.at(name);

    if (img == NULL) {
        cout << "Window::drawPartIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;

    SDL_Rect r;
    r.x = a;
    r.y = b;
    r.w = c;
    r.h = d;

    SDL_BlitSurface(img,&r, _surface, &p);
}
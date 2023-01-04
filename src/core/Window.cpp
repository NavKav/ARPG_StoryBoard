//
// Created by navid on 13/05/2021.
//
#include "core/requirement.h"
#include "core/Window.h"

using namespace std;

Window::Window(const string &windowName, unsigned int sizeX, unsigned int sizeY) :
_X(sizeX),
_Y(sizeY)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    _actualWindow = SDL_CreateWindow(windowName.c_str(),
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     (int) sizeX, (int) sizeY, 0);
    if (_actualWindow == nullptr) {
        std::cout << "Window::Window() :" << SDL_GetError()
                  << std::endl;
    }
    _renderer = SDL_CreateRenderer(_actualWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    _surface = SDL_GetWindowSurface(_actualWindow);
    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    //SDL_SetRenderTarget(_renderer,_texture);
    //SDL_SetWindowFullscreen(_actualWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
    _font = TTF_OpenFont("ressource/font/arial.ttf", 25);

}


Window::~Window() {
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_actualWindow);

    for (auto d : _hashmap) {
        SDL_DestroyTexture(d.second);
    }

    TTF_CloseFont(_font);

    TTF_Quit();
    SDL_Quit();
}

void Window::setTitle(const std::string &windowTitle) {
    SDL_SetWindowTitle(_actualWindow, windowTitle.c_str());
}

void Window::drawIMG(int x, int y, const string &name) {
    SDL_Texture* texture = IMG_LoadTexture(_renderer, ("ressource/image/" + name).c_str());

    if (texture == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &(p.w), &(p.h));

    SDL_RenderCopy(_renderer, texture, NULL, &p);

    SDL_DestroyTexture(texture);
}

void Window::scaleIMG(int x, int y, int width, int height, const string &name) {
    SDL_Texture * texture = IMG_LoadTexture(_renderer, ("ressource/image/" + name).c_str());

    if (texture == NULL) {
        cout << "Window::drawTexture() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;
    p.w = width;
    p.h = height;

    SDL_RenderCopy(_renderer, texture, NULL, &p);

    SDL_DestroyTexture(texture);
}

void Window::refresh() {
    /*SDL_UpdateTexture(_texture, NULL, _surface->pixels, _surface->pitch);
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderPresent(_renderer);*/

    //_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    //SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderPresent(_renderer);
    Sleep(20);
}

void Window::clear() {
    SDL_Texture * texture = IMG_LoadTexture(_renderer, "ressource/image/clear.bmp");

    if (texture == NULL) {
        cout << "Window::drawTexture() : " << SDL_GetError() << endl;
    }

    SDL_RenderCopy(_renderer, texture, NULL, NULL);

    SDL_DestroyTexture(texture);
}

void Window::drawPartIMG(unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned int c, unsigned int d, const string &name) {
    SDL_Texture* texture = IMG_LoadTexture(_renderer, ("ressource/image/" + name).c_str());

    if (texture == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &(p.w), &(p.h));

    SDL_Rect r;
    r.x = a;
    r.y = b;
    r.w = c;
    r.h = d;

    SDL_RenderCopy(_renderer, texture, &r, &p);

    SDL_DestroyTexture(texture);
}

void Window::open(string name, string file) {
    SDL_Texture* texture = IMG_LoadTexture(_renderer, ( "ressource/image/" + file).c_str());
    if (texture != NULL) {
        _hashmap.insert({name, texture});
    } else {
        cout << "Window::open() : " << SDL_GetError() << endl;
    }
}

void Window::close(string name) {
    if (_hashmap.find(name) == _hashmap.end()) {
        cout << "Window::close() : \"" << name << "\" wasn't found" << endl;
        return ;
    }
    SDL_DestroyTexture(_hashmap.at(name));
    _hashmap.erase(name);
}

void Window::drawIMG(const string &name, int x, int y) {
    SDL_Texture* texture = _hashmap.at(name);

    if (texture == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &(p.w), &(p.h));

    SDL_RenderCopy(_renderer, texture, NULL, &p);
}

void Window::drawPartIMG(const string &name, unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    SDL_Texture* texture = _hashmap.at(name);

    if (texture == NULL) {
        cout << "Window::drawIMG() : " << SDL_GetError() << endl;
    }

    SDL_Rect p;
    p.x = x;
    p.y = y;
    p.w = c;
    p.h = d;

    SDL_Rect r;
    r.x = a;
    r.y = b;
    r.w = c;
    r.h = d;

    SDL_RenderCopy(_renderer, texture, &r, &p);
}

void Window::changeFont(const string& name, unsigned int points) {
    TTF_CloseFont(_font);
    _font = TTF_OpenFont(("ressource/font/" + name + ".ttf").c_str(), points);
}

void Window::changeColor( Uint8 r, Uint8 v, Uint8 b) {
    _color = {r, v, b};
}

void Window::writeText(int x,int y, const string& s) {
    SDL_Surface * text = TTF_RenderText_Solid(_font,s.c_str(), _color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, text);

    SDL_Rect p;
    p.x = x;
    p.y = y;
    p.w = 0;
    p.h = 0;

    SDL_BlitSurface(text,NULL, _surface, &p);
    SDL_RenderCopy(_renderer, texture, NULL, &p);
    SDL_FreeSurface(text);
}

unsigned int Window::getX() const {
    return _X;
}

unsigned int Window::getY() const {
    return _Y;
}

void Window::textSizeOf(std::string s, int& w, int& h) {
    TTF_SizeText(_font, s.c_str(), &w, &h);
}
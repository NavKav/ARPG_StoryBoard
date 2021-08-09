//
// Created by navid on 13/05/2021.
//

#ifndef PROJECTTT_WINDOW_H
#define PROJECTTT_WINDOW_H

#include <memory>
#include <iostream>

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

typedef std::string string;

class Window {
public :
    Window(const string &windowName, unsigned int sizeX, unsigned int sizeY);
    void setTitle(const string &windowTitle);
    void drawIMG(int x, int y, const string &name);
    void drawBackgroundIMG(int x, int y, const string &name);
    void refresh();
    Window() = delete;
    ~Window();
private :
    SDL_Window *_actualWindow;
    SDL_Renderer *_renderer;
    SDL_Surface *_surface;
    SDL_Surface *_background;
    SDL_Texture *_texture;

};


#endif //PROJECTTT_WINDOW_H

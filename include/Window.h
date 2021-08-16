//
// Created by navid on 13/05/2021.
//

#ifndef PROJECTTT_WINDOW_H
#define PROJECTTT_WINDOW_H

#include <memory>
#include <iostream>

#include <SDL2/SDL.h>
#include <thread>

#ifdef SDL_IMAGE_H_
#include "SDL2/SDL_image.h"
#define LOAD IMG_Load
#else
#define LOAD SDL_LoadBMP
#endif


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
    void start();
    void stop();
    void setBoolThread(bool boolThread);
private :
    SDL_Window *_actualWindow;
    SDL_Renderer *_renderer;
    SDL_Surface *_surface;
    SDL_Surface *_background;
    SDL_Texture *_texture;

    std::thread _thread;
    bool _boolThread = true;


};


#endif //PROJECTTT_WINDOW_H

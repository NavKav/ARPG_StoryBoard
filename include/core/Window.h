//
// Created by navid on 13/05/2021.
//

#ifndef PROJECTTT_WINDOW_H
#define PROJECTTT_WINDOW_H

#include <unordered_map>
#include "requirement.h"


typedef std::string string;
typedef std:: unordered_map<string, SDL_Surface*> hashmap;

class Window {
public :
    Window(const string &windowName, unsigned int sizeX, unsigned int sizeY);
    void setTitle(const string &windowTitle);
    void drawIMG(int x, int y, const string &name);
    void drawIMG(const string &name, int x, int y);
    void drawBackgroundIMG(int x, int y, const string &name);
    void drawPartIMG(unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned int c, unsigned int d, const string &name);
    void drawPartIMG(const string &name, unsigned int x, unsigned int y, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    void refresh();
    Window() = delete;
    ~Window();
    void clear();
    void close(string name);
    void open(string name, string file);

private :
    SDL_Window *_actualWindow;
    SDL_Renderer *_renderer;
    SDL_Surface *_surface;
    SDL_Texture *_texture;

    hashmap _hashmap = hashmap();

};


#endif //PROJECTTT_WINDOW_H

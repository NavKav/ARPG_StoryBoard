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
    void writeText(const string& s, unsigned x,unsigned y);
    void changeFont(const string& name, unsigned int points);
    void changeColor( Uint8 r, Uint8 v, Uint8 b);

private :
    SDL_Window *_actualWindow;
    SDL_Renderer *_renderer;
    SDL_Surface *_surface;
    SDL_Texture *_texture;

    TTF_Font * _font;
    SDL_Color _color = { 255, 255, 255 };

    hashmap _hashmap = hashmap();

};


#endif //PROJECTTT_WINDOW_H

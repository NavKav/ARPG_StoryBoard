#include "Window.h"
#include "WindowContent.h"
#include "Player.h"
#include <thread>
#include "ConcurrentRunnerBase.h"

#undef main

using namespace std;

void f(Window& window) {
    window.drawIMG(600, 300, "start_button.bmp");
    Sleep(500);
    window.drawIMG(650, 300, "start_button.bmp");
    Sleep(500);
    window.drawIMG(680, 300, "start_button.bmp");

}
void g(Window& window) {
    window.drawIMG(600, 425, "option_button.bmp");
    Sleep(500);
    window.drawIMG(650, 425, "option_button.bmp");
    Sleep(500);
    window.drawIMG(680, 425, "option_button.bmp");

}
void h(Window& window) {
    window.drawIMG(600, 550, "exit_button.bmp");
    Sleep(500);
    window.drawIMG(650, 550, "exit_button.bmp");
    Sleep(500);
    window.drawIMG(680, 550, "exit_button.bmp");
}

int main( int argc, char *argv[] )
{
    Window window("Dice Game", 1000, 700);
    window.drawIMG(0, 0, "fond.bmp");
    window.drawIMG(600, 300, "start_button.bmp");
    window.drawIMG(600, 425, "option_button.bmp");
    window.drawIMG(600, 550, "exit_button.bmp");
    window.refresh();

    Player player(nullptr);

    player.start();


    return 0;

}
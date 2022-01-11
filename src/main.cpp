
#include <atomic>
#include "Window.h"
#include "WindowContent.h"
#include "Player.h"
#include "ConcurrentRunnerBase.h"

#undef main

// test2
using namespace std;

void f(Window* w, const std::string& s, int x) {
    for (int i = 0; i < 100; i++ ) {
        w->drawIMG(x, i, s);
        w->refresh();
    }
}

void g(Window* w) {
    int x = 350, y = 350;
    for (int i = 0; i < 100; i++ ) {
        w->drawIMG(x, y, "balle.png");
        w->refresh();
        x += (i%4 == 0) - 2*(i%4 == 2);
        y += (i%4 == 1) - 2*(i%4 == 3);
    }
}

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 700, 700);
    window.drawIMG(0, 0, "fond.bmp");
    window.drawIMG(0, 0, "start_button.bmp");
    window.drawIMG(250, 0, "option_button.bmp");
    window.drawIMG(500, 0, "exit_button.bmp");
    window.refresh();

        ConcurrentRunner runner{[&]() { f(&window,"start_button.bmp", 0); },
                                [&]() { f(&window,"option_button.bmp", 250); },
                                [&]() { f(&window,"option_button.bmp", 300); },
                                [&]() { f(&window,"option_button.bmp", 350); },
                                [&]() { f(&window,"option_button.bmp", 400); },
                                [&]() { f(&window,"option_button.bmp", 450); },
                                [&]() { f(&window,"option_button.bmp", 550); },
                                [&]() { f(&window,"option_button.bmp", 650); },
                                [&]() { f(&window,"exit_button.bmp", 500); },
                                [&]() { g(&window);}};
    runner.run();
    std::cout << "end" << std::endl;

    return 0;

}
#include "core/Window.h"
#include "game/menu/MenuWindowContent.h"
#include "game/context/GameWindowContent.h"

#undef main

using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
using namespace std::filesystem;
/**
std::string path = "ressource/index/unit";
    for (const auto & entry : directory_iterator(path))
        std::cout << entry.path() << std::endl;

    return 0;
 */

int main( int argc, char *argv[] )
{
    Window window("ARPG_StoryBoard", 32 * 40, 32 * 24);

    //Player p(window, new MenuWindowContent());
    //Player p(window, new OptionWindowContent());
    Player p(window, new GameWindowContent());
    //Player p(window, nullptr);
    p.start();

    return 0;
}
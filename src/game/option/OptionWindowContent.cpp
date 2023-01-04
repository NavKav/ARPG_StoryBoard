//
// Created by Navid on 21/10/2022.
//

#include "game/option/OptionWindowContent.h"

void OptionWindowContent::process(Player& player, Window& window) {
    window.drawIMG(0, 0, "fond.bmp");
    WindowFrame generalFrame(5,window);

    generalFrame.display();

    OptionLineMultiChoice optionLineMultiChoice("Languages", window);
    generalFrame.insert((OptionLine*)&optionLineMultiChoice);
    optionLineMultiChoice.insert("English");
    optionLineMultiChoice.insert("French");

    OptionLineToCheck fullscreen("Fullscreen",window);
    generalFrame.insert((OptionLine*)&fullscreen);

    generalFrame.display();
    window.refresh();
}

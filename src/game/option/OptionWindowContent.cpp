//
// Created by Navid on 21/10/2022.
//

#include "OptionWindowContent.h"

void OptionWindowContent::process(Player& player, Window& window) {
    window.drawOn(BACKGROUND);
    window.drawIMG(0, 0, "fond.bmp");
    WindowFrame generalFrame(window);

    OptionLineMultiChoice optionLineMultiChoice("Languages", window);
    generalFrame.insert((OptionLine*)&optionLineMultiChoice);
    optionLineMultiChoice.insert("English");
    optionLineMultiChoice.insert("French");
    optionLineMultiChoice.insert("Un nom de langue tres long");
    optionLineMultiChoice.insert("Russian");

    OptionLineToCheck fullscreen("Fullscreen",window);
    generalFrame.insert((OptionLine*)&fullscreen);

    OptionLineToCheck particles("Particles",window);
    generalFrame.insert((OptionLine*)&particles);

    OptionLineMultiChoice screenSize("Screen size", window);
    generalFrame.insert((OptionLine*)&screenSize);
    screenSize.insert("1920 x 1200");
    screenSize.insert("1920 x 1080");
    screenSize.insert("1366 x 768");
    screenSize.insert("640 x 480");

    OptionLineToCheck parallax("Parallax",window);
    generalFrame.insert((OptionLine*)&parallax);
    OptionLineToCheck a("Shadder1",window);
    generalFrame.insert((OptionLine*)&a);
    OptionLineToCheck b("Shadder2",window);
    generalFrame.insert((OptionLine*)&b);
    OptionLineToCheck c("Shadder3",window);
    generalFrame.insert((OptionLine*)&c);

    generalFrame.display();
    window.refresh();
}

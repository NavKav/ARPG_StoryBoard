//
// Created by navid on 21/02/2024.
//

#ifndef ARPG_STORYBOARD_BLOCKIDTONAME_H
#define ARPG_STORYBOARD_BLOCKIDTONAME_H

#include <iostream>

typedef unsigned int Uint;

std::string groundIdtoName(Uint id) {
    switch (id) {
        case 1 :
            return "block0";
        default :
            return "";
    }
}

std::string liquidIdtoName(Uint id) {

}

std::string aspectIdtoName(Uint id) {

}

#endif //ARPG_STORYBOARD_BLOCKIDTONAME_H

//
// Created by navid on 14/07/2023.
//

#ifndef ARPG_STORYBOARD_UNITINDEX_H
#define ARPG_STORYBOARD_UNITINDEX_H

#include <iostream>
#include <filesystem>
#include <string>
#include <deque>
#include <fstream>
#include <set>
#include "util/json.hpp"

#define UNIT_PATH "ressource/index/unit"

class UnitIndex {
private :
    class UnitTemplate {
    public :
        std::string name;
    };

public :
    UnitIndex();
    ~UnitIndex();

    // Iterator strictly needed to use foreach
    using const_iterator=typename std::deque<UnitTemplate>::const_iterator;
    const_iterator begin() { return _dequeTemplate.begin(); }
    const_iterator end() { return _dequeTemplate.end(); }

private:
    void createTemplate(const std::string& path);
    static std::string getCurrentDir(std::string p) ;
    bool loadTemplate(nlohmann::json& data);

    std::deque<UnitTemplate> _dequeTemplate;
    UnitTemplate _auxTemplate;
};


#endif //ARPG_STORYBOARD_UNITINDEX_H

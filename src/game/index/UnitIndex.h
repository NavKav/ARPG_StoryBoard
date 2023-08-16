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
#include "core/Window.h"

#define UNIT_PATH "ressource/index/unit"

class UnitIndex {
public :
    class UnitTemplate {
    public :
        unsigned int _id;
        std::string _name;
        unsigned int _maxHealth;
        double _movementSpeed;
        std::string _icon;
    };

    typedef const UnitTemplate constUnitTemplate;

    UnitIndex() = delete;
    explicit UnitIndex(Window& window);
    ~UnitIndex();
    const UnitTemplate& get(const std::string& name) const;

    // Iterator strictly needed to use foreach
    using const_iterator=typename std::deque<UnitTemplate>::const_iterator;
    const_iterator begin() { return _dequeTemplate.begin(); }
    const_iterator end() { return _dequeTemplate.end(); }

private:
    void createTemplate(const std::string& path);
    static std::string getCurrentDir(const std::string& p) ;
    bool loadTemplate(nlohmann::json& data, const std::string& path);

    std::deque<UnitTemplate> _dequeTemplate;

    nlohmann::json auxJson;

    UnitTemplate _auxTemplate;
    unsigned int _auxId;

    Window& _window;
};


#endif //ARPG_STORYBOARD_UNITINDEX_H

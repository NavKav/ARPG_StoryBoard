//
// Created by navid on 14/07/2023.
//

#include "UnitIndex.h"

using namespace std::filesystem;
using namespace std;
using json = nlohmann::json;

UnitIndex::UnitIndex(Window &window) :
_window(window)
{
    _auxId = 0;
    for (const auto& dirEntry : directory_iterator("ressource/index/unit")) {
        createTemplate(dirEntry.path().string());
    }
}

UnitIndex::~UnitIndex() {
    for (auto& t : _dequeTemplate) {
        if (_window.exists(t._icon))
            _window.close(t._icon);
    }
}

std::string UnitIndex::getCurrentDir(const std::string& p) {
    auto const pos = p.find_last_of("/\\");
    return p.substr(pos + 1);
}

void UnitIndex::createTemplate(const std::string& path) {
    ifstream properties(path + "/properties.json");
    if (!properties.is_open()) {
        cerr << "UnitIndex::createTemplate() : Can't open property file of " + getCurrentDir(path) << endl;
        return;
    }

    try {
        auxJson = json::parse(properties);
    } catch (json::exception& e) {
        cout << "UnitIndex::createTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
    }

   if (loadTemplate(auxJson, path)) {
       _auxTemplate._id = _auxId;
       _auxId ++;
       _dequeTemplate.push_front(_auxTemplate);
   } else {
       cout << "UnitIndex::createTemplate() : Can't create unit at " << path << endl;
   }
}

const UnitIndex::UnitTemplate& UnitIndex::get(const std::string& name) const {
    for (auto& t : _dequeTemplate) {
        if (t._name == name)
            return t;
    }
    cout << "UnitIndex::get() : Couldn't find unit name " << name << '\n';
    return _dequeTemplate.front();
}

bool UnitIndex::loadTemplate(json& data, const std::string& path) {

    try {
        _auxTemplate._name = data.at("name");
    } catch (json::exception& e) {
        cout << "UnitIndex::loadTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }

    try {
        _auxTemplate._movementSpeed = data.at("movement speed");
    } catch (json::exception& e) {
        cout << "UnitIndex::loadTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }

    try {
        _auxTemplate._maxHealth = data.at("max health");
    } catch (json::exception& e) {
        cout << "UnitIndex::loadTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }

    try {
        _auxTemplate._icon = data.at("icon");
    } catch (json::exception& e) {
        cout << "UnitIndex::loadTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }
    string auxString = "icon" + to_string(_auxId);
    _window.open(auxString,
                 "../index/unit/" + getCurrentDir(path) + "/" + _auxTemplate._icon);
    _auxTemplate._icon = auxString;

    return true;
}

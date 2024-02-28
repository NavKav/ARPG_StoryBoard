//
// Created by navid on 22/08/2023.
//

#include "BlockIndex.h"

using namespace std;
using namespace std::filesystem;
using json = nlohmann::json;

BlockIndex::BlockIndex() {
    _auxId = 0;
    for (const auto& dirEntry : directory_iterator("ressource/index/block")) {
        createTemplate(dirEntry.path().string());
    }
}

const BlockIndex::BlockTemplate &BlockIndex::get(const string &name) const {
    for (auto& t : _dequeTemplate) {
        if (t._name == name)
            return t;
    }
    cout << "BlockIndex::get() : Couldn't find block name " << name << '\n';
    return _dequeTemplate.front();
}

void BlockIndex::createTemplate(const string &path) {
    ifstream properties(path + "/properties.json");
    if (!properties.is_open()) {
        cerr << "BlockIndex::createTemplate() : Can't open property file in \"" + getCurrentDir(path) << "\" directory" << endl;
        return;
    }

    try {
        auxJson = json::parse(properties);
    } catch (json::exception& e) {
        cout << "BlockIndex::createTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
    }

    if (loadTemplate(auxJson, path)) {
        _auxTemplate._id = _auxId;
        _auxId ++;
        _dequeTemplate.push_front(_auxTemplate);
    } else {
        cout << "BlockIndex::createTemplate() : Can't create unit at " << path << endl;
    }
}

std::string BlockIndex::getCurrentDir(const string &p) {
    auto const pos = p.find_last_of("/\\");
    return p.substr(pos + 1);
}

bool BlockIndex::loadTemplate(json &data, const string &path) {

    try {
        _auxTemplate._name = data.at("name");
    } catch (json::exception& e) {
        cout << "BlockIndex::loadTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }

    try {
        _auxTemplate._icon = data.at("icon");
    } catch (json::exception& e) {
        cout << "BlockIndex::loadTemplate() (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }
    _auxTemplate._icon = "/index/block/" + getCurrentDir(path) + "/" + _auxTemplate._icon;

    return true;
}

const BlockIndex::BlockTemplate &BlockIndex::get(const int id) const {
    for (auto& t : _dequeTemplate) {
        if (t._id == id)
            return t;
    }
    cout << "BlockIndex::get() : Couldn't find block name " << id << '\n';
    return _dequeTemplate.front();
}

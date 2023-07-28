//
// Created by navid on 14/07/2023.
//

#include <iostream>
#include "UnitIndex.h"

using namespace std::filesystem;
using namespace std;
using json = nlohmann::json;

UnitIndex::UnitIndex() {
    for (const auto& dirEntry : directory_iterator("ressource/index/unit")) {
        createTemplate(dirEntry.path().string());
    }
}

UnitIndex::~UnitIndex() {

}

std::string UnitIndex::getCurrentDir(std::string p) {
    auto const pos = p.find_last_of("/\\");
    return p.substr(pos + 1);
}

void UnitIndex::createTemplate(const std::string& path) {
    ifstream properties(path + "/properties.json");
    if (!properties.is_open()) {
        cerr << "UnitIndex::createTemplate : Can't open property file of " + getCurrentDir(path) << endl;
        return;
    }

    json data;

    try {
        data = json::parse(properties);
    } catch (json::exception& e) {
        cout << "UnitIndex::createTemplate (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
    }

   if (loadTemplate(data)) {
       _dequeTemplate.push_front(_auxTemplate);
   }
}

bool UnitIndex::loadTemplate(json& data) {

    try {
        _auxTemplate.name = data.at("name");
    } catch (json::exception& e) {
        cout << "UnitIndex::createTemplate (nlohmann::json) : " << e.what() << "(" << typeid(e).name() << ")" << '\n';
        return false;
    }

    return true;
}


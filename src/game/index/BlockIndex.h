//
// Created by navid on 22/08/2023.
//

#ifndef ARPG_STORYBOARD_BLOCKINDEX_H
#define ARPG_STORYBOARD_BLOCKINDEX_H

#include <iostream>
#include <filesystem>
#include <string>
#include <deque>
#include <fstream>
#include <set>
#include "util/json.hpp"

class BlockIndex {
public :
    class BlockTemplate {
    friend class BlockIndex;
    public:
        const std::string& getIconPath() const {
            return _iconPath;
        }
        const std::string &getName() const {
            return _name;
        }
        const unsigned int &getId() const {
            return _id;
        }
    protected :
        unsigned int _id;
        std::string _name;
        std::string _iconPath;
    };

    typedef const BlockTemplate constBlockTemplate;

    BlockIndex();
    ~BlockIndex() = default;
    const BlockTemplate& get(const std::string& name) const;
    const BlockTemplate& get(const int id) const;

    // Iterator strictly needed to use foreach
    using const_iterator=typename std::deque<BlockTemplate>::const_iterator;
    const_iterator begin() { return _dequeTemplate.begin(); }
    const_iterator end() { return _dequeTemplate.end(); }

private :
    void createTemplate(const std::string& path);
    static std::string getCurrentDir(const std::string& p) ;
    bool loadTemplate(nlohmann::json& data, const std::string& path);

    std::deque<BlockTemplate> _dequeTemplate;

    nlohmann::json auxJson;

    BlockTemplate _auxTemplate;
    unsigned int _auxId;

};


#endif //ARPG_STORYBOARD_BLOCKINDEX_H

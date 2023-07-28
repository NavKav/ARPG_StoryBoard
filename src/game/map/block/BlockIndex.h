//
// Created by navid on 08/03/2023.
//

#ifndef ARPG_STORYBOARD_BLOCKINDEX_H
#define ARPG_STORYBOARD_BLOCKINDEX_H

#define NB_BLOCK_LIQUID 156
#define NB_BLOCK_GROUND 102
#define NB_BLOCK_ASPECT 300

enum Layer {
    LIQUID,
    GROUND,
    ASPECT,
};

class BlockIndex {
public :
    class Block {
    bool walkable() const {return _walkable;};
    private :
        bool _walkable = true;
    };
    BlockIndex();
    ~BlockIndex();
    void set(Layer layer);
    Block& operator[](int i);

private :
    Block* _liquidBlockArray;
    Block* _groundBlockArray;
    Block* _aspectBlockArray;

    Block* _actualBlockArray = nullptr;
};


#endif //ARPG_STORYBOARD_BLOCKINDEX_H

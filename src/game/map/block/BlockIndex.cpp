//
// Created by navid on 08/03/2023.
//

#include "BlockIndex.h"

BlockIndex::BlockIndex() {
    _liquidBlockArray = new Block[NB_BLOCK_LIQUID];
    _groundBlockArray = new Block[NB_BLOCK_GROUND];
    _aspectBlockArray = new Block[NB_BLOCK_ASPECT];

    _actualBlockArray = _liquidBlockArray;
}

BlockIndex::~BlockIndex() {
    delete[] _liquidBlockArray;
    delete[] _groundBlockArray;
    delete[] _aspectBlockArray;
}

void BlockIndex::set(Layer layer) {
    _actualBlockArray = (layer == LIQUID) ? _liquidBlockArray :
                        (layer == GROUND) ? _groundBlockArray :
                                            _aspectBlockArray;
}

BlockIndex::Block &BlockIndex::operator[](int i) {
    return _actualBlockArray[i];
}

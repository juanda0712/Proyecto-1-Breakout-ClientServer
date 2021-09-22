//
// Created by eduardo on 22/9/21.
//

#ifndef CLIENT_BLOCKFACTORY_H
#define CLIENT_BLOCKFACTORY_H

#include "../game/Block.h"

class BlockFactory {
private:
    static void customizeBlock(Block* block, Color in, Color out);
public:
    static Block * commonBlock(float varX, float varY);
    static Block * doubleBlock(float varX, float varY);
    static Block * tripleBlock(float varX, float varY);
    static Block * innerBlock(float varX, float varY);
    static Block * deepBlock(float varX, float varY);
    static Block * surpriseBlock(float varX, float varY);
};


#endif //CLIENT_BLOCKFACTORY_H

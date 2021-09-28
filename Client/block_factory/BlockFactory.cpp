//
// Created by eduardo on 22/9/21.
//

#include "BlockFactory.h"

void BlockFactory::customizeBlock(Block *block, Color in, Color out) {
    block->blockShape.setSize(Vector2f(40.f, 20.f));
    block->blockShape.setOrigin(20.f, 10.f);
    block->blockShape.setPosition(block->getX(), block->getY());
    block->blockShape.setFillColor(in);
    block->blockShape.setOutlineColor(out);
    block->blockShape.setOutlineThickness(2.f);
}

Block* BlockFactory::commonBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 1, 10, false, false, false);
    customizeBlock(block, Color::Green, Color::White);
    return block;
}

Block* BlockFactory::doubleBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 2, 15, false, false, false);
    customizeBlock(block, Color::Cyan, Color::White);
    return block;
}

Block* BlockFactory::tripleBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 3, 20, false, false, false);
    customizeBlock(block, Color::Red, Color::White);
    return block;
}

Block* BlockFactory::innerBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 1, 30, false, false, true);
    customizeBlock(block, Color::White, Color::Yellow);
    return block;
}

Block* BlockFactory::deepBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 1, 0, true, false, false);
    customizeBlock(block, Color::Black, Color::Yellow);
    return block;
}

Block* BlockFactory::surpriseBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 0, 0, false, true, false);
    customizeBlock(block, Color::Yellow, Color::White);
    return block;
}

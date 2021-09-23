//
// Created by eduardo on 21/9/21.
//

#include "Block.h"

Block::Block(float posX, float posY, int lives, int points, bool deep, bool surprise) {
    this->posX = posX;
    this->posY = posY;
    this->lives = lives;
    this->points = points;
    this->deep = deep;
    this->surprise = surprise;
}

float Block::getX() const {
    return this->posX;
}

float Block::getY() const {
    return this->posY;
}

int Block::getPoints() const {
    return this->points;
}

int Block::getLives() const {
    return this->lives;
}

bool Block::getIsDeep() const {
    return this->deep;
}

bool Block::getIsSurprise() const {
    return this->surprise;
}

void Block::getHit() {
    this->lives--;
}
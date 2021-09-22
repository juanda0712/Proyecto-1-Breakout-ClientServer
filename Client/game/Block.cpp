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

float Block::getX() {
    return this->posX;
}

float Block::getY() {
    return this->posY;
}

int Block::getPoints() {
    return this->points;
}
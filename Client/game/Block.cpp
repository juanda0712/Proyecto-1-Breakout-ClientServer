//
// Created by eduardo on 21/9/21.
//

#include "Block.h"

Block::Block(float posX, float posY, int lives, int points, bool deep, bool surprise, bool inner) {
    this->posX = posX;
    this->posY = posY;
    this->lives = lives;
    this->points = points;
    this->deep = deep;
    this->surprise = surprise;
    this->inner = inner;
    this->alive = true;
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

bool Block::getIsInner() const {
    return this->inner;
}

void Block::getHit() {
    this->lives--;
}

bool Block::getIsAlive() const {
    return this->alive;
}

void Block::die() {
    this->alive = false;
}
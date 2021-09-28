#include "GameData.h"

GameData::GameData() {}

void GameData::setLIves(int lives) {
    this->lives = lives;
}

int GameData::getLives() {
    return this->lives;
}

void GameData::setTotalBlocks(int totalBlocks) {
    this->totalBlocks = totalBlocks;
}

int GameData::getTotalBlocks() {
    return this->totalBlocks;
}

void GameData::setBallSpeed(int ballSpeed) {
    this->ballSpeed = ballSpeed;
}

int GameData::getBallSpeed() {
    return this->ballSpeed;
}


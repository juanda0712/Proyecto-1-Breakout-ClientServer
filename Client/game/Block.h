//
// Created by eduardo on 21/9/21.
//

#ifndef CLIENT_BLOCK_H
#define CLIENT_BLOCK_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Block {
private:
    float posX;
    float posY;
    int lives;
    int points;
    bool deep;
    bool surprise;
public:
    RectangleShape blockShape;
    Block(float posX, float posY, int lives, int points, bool deep, bool surprise);
    float getX();
    float getY();
    int getPoints();
};


#endif //CLIENT_BLOCK_H

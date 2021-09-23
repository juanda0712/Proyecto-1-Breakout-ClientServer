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
    bool inner;
    bool alive;
public:
    RectangleShape blockShape;
    Block(float posX, float posY, int lives, int points, bool deep, bool surprise, bool inner);
    float getX() const;
    float getY() const;
    int getPoints() const;
    int getLives() const;
    bool getIsDeep() const;
    bool getIsSurprise() const;
    bool getIsInner() const;
    void getHit();
    bool getIsAlive() const;
    void die();
};


#endif //CLIENT_BLOCK_H

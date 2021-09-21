//
// Created by eduardo on 21/9/21.
//

#ifndef CLIENT_BALL_H
#define CLIENT_BALL_H

#include "SFML/Graphics.hpp"
#include "Bar.h"

using namespace sf;

class Ball {
private:
    CircleShape myBall;
    bool onScreen;
    bool RIGHT;
    bool UP;
    float posX;
    float posY;
public:
    Ball(float x, float y);
    void mover_X();
    void mover_Y(Bar* ptrBar);
    CircleShape getBall();
};


#endif //CLIENT_BALL_H

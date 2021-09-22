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
    float posX;
    float posY;
    float speed;
    void mover_X();
    void mover_Y(Bar* ptrBar);
public:
    Ball(float x, float y, float speed);
    void updateBallMovement(Bar* bar);
    CircleShape getBall();
};


#endif //CLIENT_BALL_H

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
    bool move;
    float speed;
    bool right;
    bool up;
public:
    Ball(float x, float y, float speed);
    void startMoving();
    void ballMovement();
    CircleShape getBall();
};


#endif //CLIENT_BALL_H

//
// Created by eduardo on 21/9/21.
//

#include "Ball.h"

Ball::Ball(float x, float y, float speed) {
    myBall.setRadius(5.f);
    myBall.setOrigin(5.f, 5.f);
    myBall.setPosition(x, y);
    myBall.setFillColor(Color::White);
    myBall.setOutlineThickness(2.f);
    myBall.setOutlineColor(Color::Black);
    this->onScreen = true;
    this->speed = speed;
}

void Ball::mover_X() {
    bool Right = true;
    while (onScreen) {
        while (this->posX < 795 && Right) {
            myBall.move(speed, 0.f);
            if (posX >= 795) {
                Right = false;
            }
        }
        while (this->posX > 0 && !Right) {
            myBall.move(-speed, 0.f);
            if (posX <= 0) {
                Right = true;
            }
        }
    }
}

void Ball::mover_Y(Bar* ptrBar) {
    bool Up = true;
    while (onScreen) {
        while (this->posY > 5 && Up) {
            myBall.move(0.f, -speed);
            if (this->posY <= 5) {
                Up = false;
            }
        }
        while (this->posY < 595 && !Up) {
            myBall.move(0.f, speed);
            if (myBall.getLocalBounds().intersects(ptrBar->getBar().getLocalBounds())) {
                Up = true;
            }
            else if (this->posY >= 600) {
                onScreen = false;
                break;
            }
        }
    }
}

CircleShape Ball::getBall() {
    return this->myBall;
}

void Ball::updateBallMovement(Bar* bar) {
    mover_X();
    mover_Y(bar);
}

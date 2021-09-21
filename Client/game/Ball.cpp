//
// Created by eduardo on 21/9/21.
//

#include "Ball.h"

Ball::Ball(float x, float y) {
    myBall.setRadius(10.f);
    myBall.setOrigin(10.f, 10.f);
    myBall.setPosition(x, y);
    this->RIGHT = true;
    this->UP = true;
    this->onScreen = true;
}

void Ball::mover_X() {
    while (onScreen) {
        while (this->posX < 800 && RIGHT) {
            this->posX += 10;
            if (posX >= 800) {
                this->RIGHT = false;
            }
        }
        while (this->posX > 0 && !RIGHT) {
            this->posX -= 10;
            if (posX <= 0) {
                this->RIGHT = true;
            }
        }
    }
}

void Ball::mover_Y(Bar* ptrBar) {
    while (onScreen) {
        while (this->posY > 0 && UP) {
            this->posY -= 10;
            if (this->posY <= 0) {
                UP = false;
            }
        }
        while (this->posY < 600 && !UP) {
            this->posY += 10;
            if (myBall.getLocalBounds().intersects(ptrBar->getBar().getLocalBounds())) {
                UP = true;
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

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

    this->speed = speed;
    this->move = false;

    this->up = true;
    this->right - true;
}

CircleShape Ball::getBall() {
    return this->myBall;
}

void Ball::startMoving() {
    this->move = true;
}

void Ball::ballMovement() {
    if (this->move) {
        if (myBall.getPosition().x < 800 - myBall.getRadius() && right) {
            myBall.move(speed, 0.f);
            if (myBall.getPosition().x >= 800 - myBall.getRadius()) {
                myBall.setPosition(800.f - myBall.getRadius(), myBall.getPosition().y);
                this->right = false;
            }
        }
        else if (myBall.getPosition().x > 0 + myBall.getRadius() && !right) {
            myBall.move(-speed, 0.f);
            if (myBall.getPosition().x <= 0 + myBall.getRadius()) {
                myBall.setPosition(0.f + myBall.getRadius(), myBall.getPosition().y);
                this->right = true;
            }
        }
        if (myBall.getPosition().y > 0 + myBall.getRadius() && up) {
            myBall.move(0.f, -speed);
            if (myBall.getPosition().y <= 0 + myBall.getRadius()) {
                myBall.setPosition(myBall.getPosition().x, 0.f + myBall.getRadius());
                this->up = false;
            }
        }
        else if (myBall.getPosition().y < 600 - myBall.getRadius() && !up) {
            myBall.move(0.f, speed);
            if (myBall.getPosition().y >= 600 - myBall.getRadius()) {
                myBall.setPosition(myBall.getPosition().x, 600.f - myBall.getRadius());
                this->up = true;
            }
        }
    }
}

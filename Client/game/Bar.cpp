//
// Created by eduardo on 21/9/21.
//

#include "Bar.h"

Bar::Bar() {
    this->barra = new RectangleShape(Vector2f(100, 10));
    barra->setPosition(400, 550);
    barra->setOrigin(50, 10);
    barra->setFillColor(Color::Blue);
    barra->setOutlineColor(Color::Yellow);
    barra->setOutlineThickness(2.f);
    this->angle = 0;
}

void Bar::movement(int dir) {
    if (dir == 0) {
        if (this->barra->getPosition().x <= 0) {
            positionx = 0;
        }
        this->positionx -= 10;
        barra->setPosition(positionx, 550);
    }
    else if (dir == 1) {
        if (this->barra->getPosition().x >= 800) {
            positionx = 800;
        }
        this->positionx += 10;
        barra->setPosition(positionx, 550);
    }
}

void Bar::rot(int dir) {
    if (dir == 0) {
        angle -= 5.f;
    }
    else if (dir == 1) {
        angle += 5.f;
    }
    this->barra->setRotation(angle);
}

RectangleShape *Bar::getBar() {
    return this->barra;
}

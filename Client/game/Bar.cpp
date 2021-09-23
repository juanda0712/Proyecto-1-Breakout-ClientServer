//
// Created by eduardo on 21/9/21.
//

#include "Bar.h"

Bar::Bar() {
    barra.setSize(Vector2f(100, 10));
    barra.setPosition(400, 550);
    barra.setOrigin(50, 10);
    barra.setFillColor(Color::Yellow);
    barra.setOutlineColor(Color::White);
    barra.setOutlineThickness(2.f);
}

void Bar::movement(int dir) {
    if (dir == 0) {
        if (this->barra.getPosition().x <= 50) {
            barra.setPosition(50.f, 550.f);
        }
        barra.move(-7.f, 0.f);
    }
    else if (dir == 1) {
        if (this->barra.getPosition().x >= 750) {
            barra.setPosition(750.f, 550.f);
        }
        barra.move(7.f, 0.f);
    }
}

void Bar::rot(int dir) {
    if (dir == 0) {
        barra.rotate(-3.f);
    }
    else if (dir == 1) {
        barra.rotate(3.f);
    }
}

RectangleShape Bar::getBar() {
    return this->barra;
}

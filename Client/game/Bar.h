//
// Created by eduardo on 21/9/21.
//

#ifndef CLIENT_BAR_H
#define CLIENT_BAR_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Bar {
private:
    RectangleShape* barra;
    float positionx;
    float angle;
public:
    Bar();
    RectangleShape* getBar();
    void movement(int dir);
    void rot(int dir);
};


#endif //CLIENT_BAR_H

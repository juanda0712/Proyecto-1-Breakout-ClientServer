//
// Created by eduardo on 30/9/21.
//

#include "KeyListener.h"

string KeyListener::updateKeyPressed() {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        return "A";
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        return "D";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        return "Left";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        return "Right";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Space)) {
        return "Space";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        return "Esc";
    }
}
//
// Created by eduardo on 20/9/21.
//

#ifndef CLIENT_GAME_H
#define CLIENT_GAME_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "Bar.h"

using namespace sf;

class Game {
private:
    RenderWindow* window;
    Event event;
    Bar gameBar;
public:
    Game();
    bool isOn();
    void update();
    void render();
};


#endif //CLIENT_GAME_H

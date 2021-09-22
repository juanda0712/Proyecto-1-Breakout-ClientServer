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
#include "Ball.h"
#include "Block.h"
#include "../block_factory/BlockFactory.h"
#include <random>

using namespace sf;

class Game {
private:
    RenderWindow* window;
    Event event;
    Bar* gameBar;
    Ball* gameBall;
    Text label_points;
    void initLabel();
    void initBlock();
public:
    int gamePoints;
    Block* blocks[60];
    Game();
    ~Game();
    bool isOn();
    void pollEvent();
    void updateKey();
    void update();
    void updateBalls();
    void updateBlocks();
    void render();
};


#endif //CLIENT_GAME_H

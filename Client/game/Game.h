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
#include <iostream>
#include <random>

using namespace sf;

/**
 * Clase Game:
 *
 * Es la clase de juego principal. Contiene los componentes necesarios para ejecutar el juego.
 * Establece métodos para mostrar objetos en pantalla, actualizar puntajes, actualizar el estado tanto de los bloques,
 * como de la barra y la bola.
 *
 * @author Eduardo Bolívar
 */
class Game {
private:
    RenderWindow* window;
    Event event;
    Bar gameBar;
    Ball* ball;
    Block* blocks[60];
    bool gameOver;
    float ballSpeed;
    int currentBalls;
    int currentPoints;
    int currentLives;
    Font f;
    Text messages;
    Text pointsT;
    void initTexts();
    void initBlock();
public:
    Game();
    ~Game();
    void loseBall();
    void surprise();
    bool isOn();
    void pollEvent();
    void updateKey();
    void updateBalls();
    void updateBlocks();
    void updatePoints(int points);
    void update();
    void render();
};


#endif //CLIENT_GAME_H

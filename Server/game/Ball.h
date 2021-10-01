//
// Created by eduardo on 21/9/21.
//

#ifndef CLIENT_BALL_H
#define CLIENT_BALL_H

#include "SFML/Graphics.hpp"
#include "math.h"
#include "Bar.h"

using namespace sf;

/**
 * Clase Ball:
 *
 * Es la clase a partir de la que se crean las bolas del juego.
 * Provee atributos como la velocidad de la bola, el movimiento, capacidad de moverse a la derecha y
 * hacia arriba, y puntos de profundidad obtenidos de bloques profundos.
 * Provee métodos para el movimiento de la bola, la dirección de la bola, reiniciar la bola, y sumar puntos de profundidad
 *
 * @author Eduardo Bolívar
 */
class Ball {
private:
    CircleShape myBall;
    float speed;
    bool right;
    bool up;
    int deepPower;
public:
    Ball(float x, float y, float speed);
    CircleShape getBall();
    int getDeepPoints();
    void addDeepPoint();
    void removeDeepPoint();
    void setUp(bool newUp);
    void restartBall(float initPosX, float initPosY);
    void startMoving();
    void ballMovement(float initPosX, float initPosY);
    void updateSpeed(float sp);
    bool move;
};


#endif //CLIENT_BALL_H

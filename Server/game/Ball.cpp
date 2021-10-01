//
// Created by eduardo on 21/9/21.
//

#include "Ball.h"

/**
 * Constructor Ball:
 *
 * Establece el radio, el origen, la posición, el grosor, y los colores de la bola.
 * Inicializa las variables de velocidad de la bola, puntos de profundidad, y movimientos.
 * @param x es la posición inicial en X de la bola.
 * @param y es la posición inicial en Y de la bola.
 * @param speed es la velocidad con la que inicia la bola.
 *
 * @author Eduardo Bolívar
 */
Ball::Ball(float x, float y, float speed) {
    myBall.setRadius(5.f);
    myBall.setOrigin(5.f, 5.f);
    myBall.setPosition(x, y - myBall.getRadius());
    myBall.setFillColor(Color::White);
    myBall.setOutlineThickness(2.f);
    myBall.setOutlineColor(Color::Black);

    this->speed = speed;
    Ball::move = false;
    this->deepPower = 0;

    this->up = true;
    this->right = true;
}

/**
 * Método getBall():
 *
 * Brinda el círculo que representa la bola en pantalla.
 * @return Circle de la forma de la bola.
 * @author Eduardo Bolívar
 */
CircleShape Ball::getBall() {
    return this->myBall;
}

/**
 * Método getDeepPoints():
 *
 * Da los puntos de profundidad actuales que tiene la bola.
 * @return los puntos de profundidad.
 * @author Eduardo Bolívar
 */
int Ball::getDeepPoints() {
    return this->deepPower;
}

/**
 * Método addDeepPoint():
 *
 * Suma un punto de profundidad cuando la bola colisiona con un bloque profundo.
 * @author Eduardo Bolívar
 */
void Ball::addDeepPoint() {
    this->deepPower++;
}

/**
 * Método removeDeepPoint():
 *
 * Resta un punto de profundidad cuando la bola colisiona con un bloque interno.
 * @author Eduardo Bolívar
 */
void Ball::removeDeepPoint() {
    this->deepPower--;
}

/**
 * Método setUp():
 *
 * Establece una nueva dirección en el eje Y para la bola.
 * @param newUp es el boolean que indica si la bola va hacia arriba.
 * @author Eduardo Bolívar
 */
void Ball::setUp(bool newUp) {
    this->up = newUp;
}

/**
 * Método restartBall():
 *
 * Reinicia la bola cuando cae por debajo de la pantalla.
 * Se coloca nuevamente sobre la barra.
 * @param initPosX es la posición inicial en X (la de la barra).
 * @param initPosY es la posición inicial en Y (la de la barra).
 *
 * @author Eduardo Bolívar
 */
void Ball::restartBall(float initPosX, float initPosY) {
    myBall.setPosition(initPosX, initPosY);
    this->move = false;
}

/**
 * Método startMoving():
 *
 * Inicia el movimiento de la bola al presionar la tecla Espacio.
 * Establece la variable "move" como verdadera.
 *
 * @author Eduardo Bolívar
 */
void Ball::startMoving() {
    this->move = true;
}

/**
 * Método ballMovement():
 *
 * Realiza el movimiento de la bola alrededor de la pantalla.
 * Detecta si la bola colisiona con los bordes para invertir la dirección del movimiento.
 * Sólo ocurre si la variable "move" es verdadera, sino, la bola sólo se mueve junto con la barra.
 *
 * @param initPosX es la posición en X de la barra.
 * @param initPosY es la posición en Y de la barra.
 *
 * @author Eduardo Bolívar
 */
void Ball::ballMovement(float initPosX, float initPosY) {
    if (this->move) {
        /// Movimiento para el eje horizontal
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
        /// Movimiento para el eje vertical
        if (myBall.getPosition().y > 0 + myBall.getRadius() && up) {
            myBall.move(0.f, -speed);
            if (myBall.getPosition().y <= 0 + myBall.getRadius()) {
                myBall.setPosition(myBall.getPosition().x, 0.f + myBall.getRadius());
                this->up = false;
            }
        }
        else if (myBall.getPosition().y < 600 - myBall.getRadius() && !up) {
            myBall.move(0.f, speed);
        }
    }
    /// Movimiento si no se ha presionado la tecla Espacio.
    else {
        myBall.setPosition(initPosX, initPosY - 15);
    }
}

/**
 * Método updateSpeed():
 *
 * Cambia la velocidad de la bola al tocar una sorpresa.
 * @param sp es la nueva velocidad de la bola.
 * @author Eduardo Bolívar
 */
void Ball::updateSpeed(float sp) {
    this->speed = sp;
}

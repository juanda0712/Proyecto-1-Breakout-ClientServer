//
// Created by eduardo on 21/9/21.
//

#include "Block.h"

/**
 * Constructor Block:
 *
 * Inicializa todos los atributos correspondientes a la clase Block.
 * Los atributos reciben el valor de los parámetros dados para cada tipo de bloque.
 *
 * @param posX es la posición en el eje horizontal que recibe el bloque.
 * @param posY es la posición en el eje vertical que recibe el bloque.
 * @param lives es la cantidad de vidas (golpes que soporta) del bloque.
 * @param points son los puntos que da el bloque al destruirlo.
 * @param deep es un booleano que determina si el bloque es profundo.
 * @param surprise determina si el bloque es sorpresa.
 * @param inner determina si el bloque es interno.
 *
 * @author Eduardo Bolívar
 */
Block::Block(float posX, float posY, int lives, int points, bool deep, bool surprise, bool inner) {
    this->posX = posX;
    this->posY = posY;
    this->lives = lives;
    this->points = points;
    this->deep = deep;
    this->surprise = surprise;
    this->inner = inner;
    this->alive = true;
}

/**
 * Método die():
 *
 * Establece la condición para que el bloque deje de estar vivo.
 *
 * @author Eduardo Bolívar
 */
void Block::die() {
    this->alive = false;
}

/**
 * Método getX():
 *
 * Brinda la posición en el eje X del bloque.
 * @return la posición en X.
 * @author Eduardo Bolívar
 */
float Block::getX() const {
    return this->posX;
}

/**
 * Método getY():
 *
 * Brinda la posición en el eje Y del bloque.
 * @return la posición en Y.
 * @author Eduardo Bolívar
 */
float Block::getY() const {
    return this->posY;
}

/**
 * Método getPoints():
 *
 * Da al jugador los puntos que ofrece el bloque al ser destruido.
 * @return los puntos a sumar al jugador.
 * @author Eduardo Bolívar
 */
int Block::getPoints() const {
    return this->points;
}

/**
 * Método getLives():
 *
 * Brinda las vidas actuales que tiene el bloque.
 * @return la cantidad de vidas restantes del bloque
 * @author Eduardo Bolívar
 */
int Block::getLives() const {
    return this->lives;
}

/**
 * Método getIsDeep():
 *
 * Brinda información sobre si el bloque es de tipo profundo.
 * @return boolean que determina si el bloque es profundo.
 * @author Eduardo Bolívar
 */
bool Block::getIsDeep() const {
    return this->deep;
}

/**
 * Método getIsSurprise():
 *
 * Brinda información sobre si el bloque es de tipo sorpresa.
 * @return boolean que determina si el bloque es sorpresa.
 * @author Eduardo Bolívar
 */
bool Block::getIsSurprise() const {
    return this->surprise;
}

/**
 * Método getIsInner():
 *
 * Brinda información sobre si el bloque es de tipo interno.
 * @return boolean que determina si el bloque es sorpresa.
 * @author Eduardo Bolívar
 */
bool Block::getIsInner() const {
    return this->inner;
}

/**
 * Método getHit():
 *
 * Es invocado cuando el bloque recibe un golpe y le quita una vida.
 * @author Eduardo Bolívar
 */
void Block::getHit() {
    this->lives--;
}

/**
 * Método getIsAlive():
 *
 * Brinda información sobre si el bloque aún tiene vidas restantes.
 * @return boolean que indica si el bloque sigue vivo.
 * @author Eduardo Bolívar
 */
bool Block::getIsAlive() const {
    return this->alive;
}
//
// Created by eduardo on 21/9/21.
//

#ifndef CLIENT_BLOCK_H
#define CLIENT_BLOCK_H

#include "SFML/Graphics.hpp"

using namespace sf;

/**
 * Clase Block:
 *
 * Crea los objetos bloque que aparecen en pantalla y sus características especiales.
 * Provee métodos para obtener los atributos especiales de cada bloque, así como los puntos de brinda y su estado.
 * Provee un objeto Rectangle que sirve para visualizar el objeto en pantalla.
 *
 * @author Eduardo Bolívar
 */
class Block {
private:
    float posX;
    float posY;
    int lives;
    int points;
    bool deep;
    bool surprise;
    bool inner;
    bool alive;
public:
    RectangleShape blockShape;
    Block(float posX, float posY, int lives, int points, bool deep, bool surprise, bool inner);
    float getX() const;
    float getY() const;
    int getPoints() const;
    int getLives() const;
    bool getIsDeep() const;
    bool getIsSurprise() const;
    bool getIsInner() const;
    void getHit();
    bool getIsAlive() const;
    void die();
};


#endif //CLIENT_BLOCK_H

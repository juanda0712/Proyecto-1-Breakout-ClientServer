//
// Created by eduardo on 21/9/21.
//

#ifndef CLIENT_BAR_H
#define CLIENT_BAR_H

#include "SFML/Graphics.hpp"

using namespace sf;

/**
 * Clase Bar:
 *
 * Es la clase a partir de la que se crea la barra del juego.
 * Provee un Rectangle que modela la barra en pantalla.
 * Provee métodos para mover y rotar la barra.
 *
 * @author Eduardo Bolívar
 */
class Bar {
private:
    RectangleShape barra;
public:
    Bar();
    RectangleShape getBar();
    void movement(int dir);
    void rot(int dir);
};


#endif //CLIENT_BAR_H

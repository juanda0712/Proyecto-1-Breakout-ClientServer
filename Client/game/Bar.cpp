//
// Created by eduardo on 21/9/21.
//

#include "Bar.h"

/**
 * Constructor Bar:
 *
 * Establece el tamaño, el color de relleno y de borde, la posición, el origen y el grosor de la barra al comenzar el juego.
 * @author Eduardo Bolívar
 */
Bar::Bar() {
    barra.setSize(Vector2f(100, 10));
    barra.setPosition(400, 550);
    barra.setOrigin(50, 10);
    barra.setFillColor(Color::Yellow);
    barra.setOutlineColor(Color::White);
    barra.setOutlineThickness(2.f);
}

/**
 * Método movement():
 *
 * Realiza el movimiento de la barra por medio de las teclas pulsadas por el jugador desde la clase Game.
 * Mueve la barra a la derecha o izquierda hasta el borde de la pantalla.
 *
 * @param dir es la dirección a la que se dirige la barra.
 * @author Eduardo Bolívar
 */
void Bar::movement(int dir) {
    if (dir == 0) {
        if (this->barra.getPosition().x <= 0 + (barra.getSize().x/2)) {
            barra.setPosition(0.f + (barra.getSize().x/2), 550.f);
        }
        barra.move(-10.f, 0.f);
    }
    else if (dir == 1) {
        if (this->barra.getPosition().x >= 800 - (barra.getSize().x/2)) {
            barra.setPosition(800.f - (barra.getSize().x/2), 550.f);
        }
        barra.move(10.f, 0.f);
    }
}

/**
 * Método rot():
 *
 * Realiza la rotación de la barra sobre su eje, mediante las teclas pulsadas por el jugador.
 * Rota a la izquierda o a la derecha haciendo giros completos.
 *
 * @param dir es la dirección a la que rota la barra.
 * @author Eduardo Bolívar
 */
void Bar::rot(int dir) {
    if (dir == 0) {
        barra.rotate(3.f);
    }
    else if (dir == 1) {
        barra.rotate(-3.f);
    }
}

/**
 * Método getBar():
 *
 * Brinda el objeto dibujable de la barra, que es un rectangle.
 *
 * @return el Rectangle que representa a la barra.
 * @author Eduardo Bolívar
 */
RectangleShape Bar::getBar() {
    return this->barra;
}

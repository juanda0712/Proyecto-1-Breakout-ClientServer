//
// Created by eduardo on 22/9/21.
//

#include "BlockFactory.h"

/**
 * Método customizeBlock():
 *
 * Personaliza los bloques dependiendo de las características gráficas de cada uno.
 * También establece el tamaño, la posición y el origen de cada bloque.
 * @param block es el bloque el cual está modificando.
 * @param in es el color interno del bloque.
 * @param out es el color del borde del bloque.
 *
 * @author Eduardo Bolívar
 */
void BlockFactory::customizeBlock(Block *block, Color in, Color out) {
    block->blockShape.setSize(Vector2f(40.f, 20.f));
    block->blockShape.setOrigin(20.f, 10.f);
    block->blockShape.setPosition(block->getX(), block->getY());
    block->blockShape.setFillColor(in);
    block->blockShape.setOutlineColor(out);
    block->blockShape.setOutlineThickness(2.f);
}

/**
 * Método commonBlock():
 *
 * Crea un nuevo bloque con las características de un bloque común.
 * Estas son:
 *  - Una vida.
 *  - 10 puntos.
 *  - Color verde.
 *
 * @param varX es la posición en X en la que aparece el bloque.
 * @param varY es la posición en Y en la que aparece el bloque.
 * @return el bloque creado.
 *
 * @author Eduardo Bolívar
 */
Block* BlockFactory::commonBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 1, 10, false, false, false);
    customizeBlock(block, Color::Green, Color::White);
    return block;
}

/**
 * Método doubleBlock():
 *
 * Crea un nuevo bloque con las características de un bloque doble.
 * Estas son:
 *  - Dos vidas.
 *  - 15 puntos.
 *  - Color celeste.
 *
 * @param varX es la posición en X en la que aparece el bloque.
 * @param varY es la posición en Y en la que aparece el bloque.
 * @return el bloque creado.
 *
 * @author Eduardo Bolívar
 */
Block* BlockFactory::doubleBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 2, 15, false, false, false);
    customizeBlock(block, Color::Cyan, Color::White);
    return block;
}

/**
 *Método tripleBlock():
 *
 * Crea un nuevo bloque con las características de un bloque triple.
 * Estas son:
 *  - Tres vidas.
 *  - 20 puntos.
 *  - Color rojo.
 *
 * @param varX es la posición en X en la que aparece el bloque.
 * @param varY es la posición en Y en la que aparece el bloque.
 * @return el bloque creado.
 *
 * @author Eduardo Bolívar
 */
Block* BlockFactory::tripleBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 3, 20, false, false, false);
    customizeBlock(block, Color::Red, Color::White);
    return block;
}

/**
 *Método innerBlock():
 *
 * Crea un nuevo bloque con las características de un bloque interno.
 * Estas son:
 *  - Una vida.
 *  - 30 puntos.
 *  - Color blanco.
 *  - Boolean verdadero que indica que es de tipo interno.
 *
 * @param varX es la posición en X en la que aparece el bloque.
 * @param varY es la posición en Y en la que aparece el bloque.
 * @return el bloque creado.
 *
 * @author Eduardo Bolívar
 */
Block* BlockFactory::innerBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 1, 30, false, false, true);
    customizeBlock(block, Color::White, Color::Yellow);
    return block;
}

/**
 *Método deepBlock():
 *
 * Crea un nuevo bloque con las características de un bloque profundo.
 * Estas son:
 *  - Indestructible.
 *  - 0 puntos.
 *  - Color negro.
 *  - Boolean que indica que es profundo.
 *
 * @param varX es la posición en X en la que aparece el bloque.
 * @param varY es la posición en Y en la que aparece el bloque.
 * @return el bloque creado.
 *
 * @author Eduardo Bolívar
 */
Block* BlockFactory::deepBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 1, 0, true, false, false);
    customizeBlock(block, Color::Black, Color::Yellow);
    return block;
}

/**
 *Método surpriseBlock():
 *
 * Crea un nuevo bloque con las características de un bloque sorpresa.
 * Estas son:
 *  - Indestructible.
 *  - 0 puntos.
 *  - Color amarillo.
 *  - Boolean que indica que es de tipo sorpresa.
 *
 * @param varX es la posición en X en la que aparece el bloque.
 * @param varY es la posición en Y en la que aparece el bloque.
 * @return el bloque creado.
 *
 * @author Eduardo Bolívar
 */
Block* BlockFactory::surpriseBlock(float varX, float varY) {
    auto* block = new Block((800.f/15) + varX, 1.f + varY, 0, 0, false, true, false);
    customizeBlock(block, Color::Yellow, Color::White);
    return block;
}

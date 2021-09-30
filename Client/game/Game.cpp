//
// Created by eduardo on 20/9/21.
//

#include "Game.h"

/**
 * Constructor Game:
 *
 * Inicializa la ventana, la bola y variables iniciales.
 * LLama a la función initBlock() que muestra los bloques en pantalla.
 * Llama a la función initText() que muestra el mensaje inicial al jugador.
 *
 * @author Eduardo Bolívar
 */
Game::Game() {
    this->window = new RenderWindow(VideoMode(800, 600), "Crazy Breakout", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
    this->ballSpeed = 5.f;
    this->currentBalls = 1;
    this->currentPoints = 0;
    this->currentLives = 3;
    this->started = false;
    this->gameOver = false;
    this->bar = new Bar();
    this->ball = new Ball(bar->getBar().getPosition().x, bar->getBar().getPosition().y, ballSpeed);
    initBlock();
    initTexts();
}

/**
 * Deconstructor Game:
 *
 * Libera el espacio de memoria ocupado por la ventana principal.
 *
 * @author Eduardo Bolívar
 */
Game::~Game() {
    delete this->window;
}

/**
 * Método initTexts():
 *
 * Muestra los mensajes para el jugador en pantalla.
 * Carga la fuente utilizada para el texto de los mensajes.
 * Establece la fuente, el tamaño de letra, el color, y demás detalles.
 *
 * @author Eduardo Bolívar
 */
void Game::initTexts() {
    /// Texto para el puntaje
    this->font.loadFromFile("../hinted-CelloSans-Regular.ttf");
    this->score.setFont(this->font);
    this->score.setPosition(0, 0);
    this->score.setFillColor(Color::White);
    this->score.setOutlineColor(Color::Magenta);
    this->score.setOutlineThickness(3.0f);
    this->score.setString("Puntaje: " + std::to_string(currentPoints));

    /// Texto para las vidas
    this->lives.setFont(this->font);
    this->lives.setPosition(680, 0);
    this->lives.setFillColor(Color::White);
    this->lives.setOutlineColor(Color::Magenta);
    this->lives.setOutlineThickness(3.0f);
    this->lives.setString("Vidas: " + std::to_string(currentLives));

    /// Texto para los puntos de profundidad
    this->deepPoints.setFont(this->font);
    this->deepPoints.setPosition(320, 0);
    this->deepPoints.setFillColor(Color::White);
    this->deepPoints.setOutlineColor(Color::Magenta);
    this->deepPoints.setOutlineThickness(3.0f);
    this->deepPoints.setString("Profundidad: " + std::to_string(ball->getDeepPoints()));

    /// Texto para el mensaje de inicio
    this->play.setFont(this->font);
    this->play.setPosition(800.f/4, 600.f/3);
    this->play.setFillColor(Color::White);
    this->play.setOutlineColor(Color::Black);
    this->play.setOutlineThickness(5.f);
    this->play.setString("Presiona 'Espacio' para jugar!");

    /// Texto de Game Over
    this->lose.setFont(this->font);
    this->lose.setPosition(800.f/4, 600.f/3);
    this->lose.setFillColor(Color::Black);
    this->lose.setOutlineColor(Color::White);
    this->lose.setOutlineThickness(5.f);
    this->lose.setString("Game over!\nPresiona ESC para salir del juego");
}

/**
 * Método initBlock():
 *
 * Mediante un contador y coordenadas X y Y, establece la posición de los bloques que aparecen en pantalla.
 * El contador determina cuantos bloques van en una fila.
 * Las coordenadas X y Y establecen una posición ordenada y centrada para los bloques.
 * Provee un random que actúa como bandera, para generar al azar los distintos tipos de bloque.
 *
 * @author Eduardo Bolívar
 */
void Game::initBlock() {
    int counter = 0;
    float varX = 0;
    float varY = 0;
    for (auto & b : blocks) {
        int rand_block = 1 + (rand() % 6);
        varX += 50;
        if (counter % 15 == 0) {
            varX = 0;
            varY += 50;
        }
        if (rand_block == 1) {
            b = BlockFactory::commonBlock(varX, varY);
        }
        else if (rand_block == 2) {
            b = BlockFactory::doubleBlock(varX, varY);
        }
        else if (rand_block == 3){
            b = BlockFactory::tripleBlock(varX, varY);
        }
        else if (rand_block == 4){
            b = BlockFactory::deepBlock(varX, varY);
        }
        else if (rand_block == 5){
            b = BlockFactory::innerBlock(varX, varY);
        }
        else {
            b = BlockFactory::surpriseBlock(varX, varY);
        }
        counter++;
    }
}

/**
 * Método surprise():
 *
 * Se encarga de aplicar las sorpresas en el juego, cuando se colisiona con un Bloque Sorpresa.
 * Las sorpresas son:
 *  - Aumento del tamaño de la barra.
 *  - Disminución del tamaño de la barra.
 *  - Aumento de la velocidad de la bola.
 *  - Disminución de la velocidad de la bola.
 *
 * Utiliza un random para decidir cuál sorpresa aplicar en juego.
 *
 * @author Eduardo Bolívar
 */
void Game::surprise() {
    int random = 1 + (rand() % 2);
    if (random == 1) {
        this->ball->updateSpeed(this->ballSpeed + 3.f);
    }
    else if (random == 2) {
        this->ball->updateSpeed(this->ballSpeed - 3.f);
    }
    else {
        this->ball->updateSpeed(this->ballSpeed);
    }
}

/**
 * Método loseBall():
 *
 * Resta una vida al jugador cuando este pierde una bola.
 * Es invocado cuando la bola sale de la pantalla.
 *
 * @author Eduardo Bolívar
 */
void Game::loseBall() {
    this->currentLives--;
}

/**
 * Método isOn():
 *
 * Verifica si la ventana de juego sigue ejecutándose.
 * El método es principalmente para mantener el loop del juego.
 *
 * @author Eduardo Bolívar
 * @return el valor booleano de isOpen() de la ventana.
 */
bool Game::isOn() {
    return this->window->isOpen();
}

/**
 * Método pollEvent():
 *
 * Detecta los posibles eventos que pueden ocurrir a la ventana de juego.
 * El único evento detectable es al momento de cerrar la ventana, para cerrar el juego.
 *
 * @author Eduardo Bolívar
 */
void Game::pollEvent() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == Event::Closed) {
            this->window->close();
            break;
        }
    }
}

/**
 * Método updateKey():
 *
 * Detecta las teclas presionadas durante ejecución del juego.
 * Las posibles teclas que puede detectar son:
 *  - A: para mover la barra a la izquierda.
 *  - D: para mover la barra a la derecha.
 *  - Flecha izquierda y flecha derecha: para rotar la barra.
 *  - Espacio: para iniciar el juego.
 *  - Escape: para cerrar el juego al momento de perder todas las vidas.
 *
 *  @author Eduardo Bolívar
 */
void Game::updateKey() {
    if (!this->gameOver) {
        if (Keyboard::isKeyPressed(Keyboard::A)){
            bar->movement(0);
        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            bar->movement(1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            bar->rot(0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            bar->rot(1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            ball->startMoving();
            this->started = true;
        }
    }
    else {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            this->window->close();
        }
    }
}

/**
 * Método updateBalls():
 *
 * Verifica constantemente la colisión de la bola con la barra de juego o si la bola sale de pantalla para restar una vida.
 * Si se pierde una bola y el jugador tiene más vidas, la bola aparece nuevamente sobre la barra.
 * Actualiza la posición de la bola por toda la ventana.
 *
 * @author Eduardo Bolívar
 */
void Game::updateBalls() {
    if (ball->getBall().getGlobalBounds().intersects(bar->getBar().getGlobalBounds())) {
        ball->setUp(true);
    }
    if (ball->getBall().getPosition().y >= 600 - ball->getBall().getRadius()) {
        loseBall();
        ball->restartBall(bar->getBar().getPosition().x, bar->getBar().getPosition().y);
    }
    ball->ballMovement(bar->getBar().getPosition().x, bar->getBar().getPosition().y);
}

/**
 * Método updateBlocks():
 *
 * Verifica constantemente la colisión entre la bola y algún bloque en pantalla.
 * Si un bloque es destruido, desaparece y suma el puntaje respectivo al jugador.
 * También invoca las características de cada bloque al ocurrir la colisión:
 *  - Si es profundo, dar un punto de profundidad.
 *  - Si es sorpresa, invocar una sorpresa random.
 *
 * @author Eduardo Bolívar
 */
void Game::updateBlocks() {
    for (Block* b : blocks) {
        if (this->ball->getBall().getGlobalBounds().intersects(b->blockShape.getGlobalBounds())) {
            /// Bloques indestructibles:
            /// Revisa la colisión con el bloque profundo.
            if (b->getIsDeep()) {
                ball->addDeepPoint();
                ball->setUp(false);
            }
            /// Revisa la colisión con el bloque sorpresa.
            else if (b->getIsSurprise()) {
                this->surprise();
                ball->setUp(false);
            }
            /// Bloques destructibles:
            else {
                if (b->getIsAlive()) {
                    /// Revisa la colision con el bloque interno.
                    if (b->getIsInner() && ball->getDeepPoints() > 0) {
                        ball->removeDeepPoint();
                        updatePoints(b->getPoints());
                        b->blockShape.setFillColor(Color::Transparent);
                        b->blockShape.setOutlineColor(Color::Transparent);
                        ball->setUp(false);
                    }
                    /// Revisa la colision con los bloques regulares.
                    else {
                        b->getHit();
                        if (b->getLives() <= 0) {
                            b->die();
                            updatePoints(b->getPoints());
                            b->blockShape.setFillColor(Color::Transparent);
                            b->blockShape.setOutlineColor(Color::Transparent);
                        }
                        ball->setUp(false);
                    }
                }
            }
        }
    }
}

/**
 * Método updatePoints():
 *
 * Suma los puntos dados por un bloque respectivo y los muestra en pantalla.
 *
 * @param points es la cantidad de puntos por sumar.
 * @author Eduardo Bolívar
 */
void Game::updatePoints(int points) {
    this->currentPoints += points;
    this->score.setString("Puntaje: " + std::to_string(currentPoints));
}

/**
 * Método updateLives():
 *
 * Actualiza y verifica el número de vidas del jugador para mostrarlas en pantalla.
 * @author Eduardo Bolívar
 */
void Game::updateLives() {
    if (currentLives <= 0) {
        this->gameOver = true;
    }
    this->lives.setString("Vidas: " + std::to_string(currentLives));
}

/**
 * Método updateDeepPoints():
 *
 * Actualiza el número de puntos de profundidad de la bola en pantalla.
 * @author Eduardo Bolívar
 */
void Game::updateDeepPoints() {
    this->deepPoints.setString("Profundidad: " + std::to_string(ball->getDeepPoints()));
}

/**
 * Método update():
 *
 * Constantemente actualiza el juego.
 * Invoca al resto de funciones update y verifica la muerte del jugador.
 * Ocurre en el loop principal del programa.
 *
 * @author Eduardo Bolívar
 */
void Game::update() {
    pollEvent();
    updateKey();
    updateBlocks();
    updateBalls();
    updateLives();
    updateDeepPoints();
}

/**
 * Método render():
 *
 * Muestra lo que hay en pantalla.
 * Resetea lo que hay en pantalla para luego volver a dibujarlo (renderizarlo).
 * Ocurre en el loop principal del programa.
 *
 * @author Eduardo Bolívar
 */
void Game::render() {
    this->window->clear(Color::Black);

    for (Block* b : this->blocks) {
        this->window->draw(b->blockShape);
    }
    if (!started) {
        this->window->draw(play);
    }
    if (gameOver) {
        this->window->draw(lose);
    }
    this->window->draw(ball->getBall());
    this->window->draw(bar->getBar());
    this->window->draw(lives);
    this->window->draw(score);
    this->window->draw(deepPoints);

    this->window->display();
}
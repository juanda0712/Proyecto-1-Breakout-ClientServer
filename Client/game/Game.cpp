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

    this->ball = new Ball(gameBar.getBar().getPosition().x, gameBar.getBar().getPosition().y, 7.f);

    this->currentBalls = 1;
    this->currentPoints = 0;
    this->currentLives = 3;

    this->gameOver = false;

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
    this->f.loadFromFile("../resources/Catalish Huntera.ttf");

    this->pointsT.setFont(this->f);
    this->pointsT.setCharacterSize(1);
    this->pointsT.setString("POINTS: " + std::to_string(currentPoints));
    this->pointsT.setPosition(800.f/15, 600.f - 50);
    this->pointsT.setScale(50,50);
    this->pointsT.setFillColor(Color::White);
    this->pointsT.setOutlineColor(Color::Green);
    this->pointsT.setOutlineThickness(1.f);

    this->messages.setFont(f);
    this->messages.setCharacterSize(1);
    this->messages.setPosition(800.f/2, 600.f/2);
    this->messages.setScale(200, 100);
    this->messages.setOrigin(100, 50);
    this->messages.setFillColor(Color::Yellow);
    this->messages.setOutlineColor(Color::Magenta);
    this->messages.setOutlineThickness(1.f);
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
    int rand_block;
    int counter = 0;
    float varX = 0;
    float varY = 0;
    for (auto & block : blocks) {
        rand_block = 1 + (rand() % 6);
        varX += 50;
        if (counter % 15 == 0) {
            varX = 0;
            varY += 50;
        }
        if (rand_block == 1) {
            block = BlockFactory::commonBlock(varX, varY);
        }
        else if (rand_block == 2) {
            block = BlockFactory::doubleBlock(varX, varY);
        }
        else if (rand_block == 3){
            block = BlockFactory::tripleBlock(varX, varY);
        }
        else if (rand_block == 4){
            block = BlockFactory::innerBlock(varX, varY);
        }
        else if (rand_block == 5){
            block = BlockFactory::deepBlock(varX, varY);
        }
        else {
            block = BlockFactory::surpriseBlock(varX, varY);
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
    int random = 1 + (rand() % 6);
    if (random == 1) {
        gameBar.getBar().setSize(Vector2f(200, 10));
    }
    else if (random == 2) {
        gameBar.getBar().setSize(Vector2f(50, 10));
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
            gameBar.movement(0);
        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            gameBar.movement(1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            gameBar.rot(0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            gameBar.rot(1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            ball->startMoving();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        if (this->gameOver) {
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
    if (ball->getBall().getGlobalBounds().intersects(gameBar.getBar().getGlobalBounds())) {
        ball->setUp(true);
    }
    if (ball->getBall().getPosition().y >= 600 - ball->getBall().getRadius()) {
        loseBall();
        ball->restartBall(gameBar.getBar().getPosition().x, gameBar.getBar().getPosition().y);
    }
    ball->ballMovement(gameBar.getBar().getPosition().x, gameBar.getBar().getPosition().y);
    std::cout << ball->deepPower << std::endl;
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
            if (b->getIsSurprise()) {

            }
            else if (b->getIsAlive()) {
                b->getHit();
                if (b->getIsDeep()) {
                    ball->getDeepPoint();
                }
                if (b->getLives() < 0) {
                    b->die();
                    b->blockShape.setFillColor(Color::Transparent);
                    b->blockShape.setOutlineColor(Color::Transparent);
                }
                ball->changeDirection();
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
    std::cout << "POINTS: " + std::to_string(currentPoints) << std::endl;
    this->pointsT.setString("POINTS: " + std::to_string(currentPoints));
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
    if (currentLives <= 0) {
        this->gameOver = true;
    }
    pollEvent();
    updateKey();
    updateBlocks();
    updateBalls();
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
    this->window->draw(ball->getBall());
    this->window->draw(gameBar.getBar());

    this->window->display();
}

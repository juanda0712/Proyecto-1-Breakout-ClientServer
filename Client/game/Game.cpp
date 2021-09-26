//
// Created by eduardo on 20/9/21.
//

#include "Game.h"

Game::Game() {
    this->window = new RenderWindow(VideoMode(800, 600), "Crazy Breakout", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);

    this->gameBar = new Bar();
    this->gameBall = new Ball(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y, 5.f);

    this->currentPoints = 0;
    this->currentLives = 3;

    this->started = false;
    this->gameOver = false;

    initBlock();
    initTexts();
}

Game::~Game() {
    delete this->window;
    delete gameBar;
    delete gameBall;
    delete *blocks;
}

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

void Game::initBlock() {
    int rand_block;
    int counter = 0;
    float varX = 0;
    float varY = 0;
    for (auto & block : blocks) {
        block = nullptr;
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

void Game::updatePoints(int points) {
    this->currentPoints += points;
    std::cout << "POINTS: " + std::to_string(currentPoints) << std::endl;
    this->pointsT.setString("POINTS: " + std::to_string(currentPoints));
}

void Game::updateBlocks() {
    for (Block* b : blocks) {
        if (this->gameBall->getBall().getGlobalBounds().intersects(b->blockShape.getGlobalBounds())) {
            b->getHit();

            if (b->getLives() == 0) {
                b->blockShape.setFillColor(Color::Transparent);
                updatePoints(b->getPoints());
            }
            if (b->getLives() <= -1) {
                b->die();
            }
            if (b->getIsAlive()) {
                if (gameBall->getUp()) {
                    gameBall->setUp(false);
                }
                else {
                    gameBall->setUp(true);
                }
            }
        }
    }
}

bool Game::isOn() {
    return this->window->isOpen();
}

void Game::pollEvent() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == Event::Closed) {
            this->window->close();
            break;
        }
    }
}

void Game::updateKey() {
    if (!this->gameOver) {
        if (Keyboard::isKeyPressed(Keyboard::A)){
            gameBar->movement(0);
        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            gameBar->movement(1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            gameBar->rot(0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            gameBar->rot(1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            this->started = true;
            gameBall->startMoving();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        if (this->gameOver) {
            this->window->close();
        }
    }
}

void Game::updateBalls() {
    if (gameBall->getBall().getGlobalBounds().intersects(gameBar->getBar().getGlobalBounds())) {
        gameBall->setUp(true);
    }
    if (gameBall->getBall().getPosition().y >= 600 - gameBall->getBall().getRadius()) {
        loseBall();
        gameBall->restartBall(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y);
    }
    gameBall->ballMovement(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y);
}

void Game::loseBall() {
    this->currentLives--;
}

void Game::update() {
    if (currentLives <= 0) {
        this->gameOver = true;
    }
    pollEvent();
    updateKey();
    updateBlocks();
    updateBalls();
}

void Game::render() {
    this->window->clear(Color::Black);

    if (!this->started) {
        this->messages.setString("Press 'Space' to start!");
        this->window->draw(messages);
    }
    if (this->gameOver) {
        this->messages.setString("Game Over!\nTotal points: "+ std::to_string(this->currentPoints) +"\nPress ESC to close.");
        this->window->draw(messages);
    }

    this->window->draw(pointsT);
    for (Block* b : blocks) {
        this->window->draw(b->blockShape);
    }
    this->window->draw(gameBar->getBar());
    this->window->draw(gameBall->getBall());

    this->window->display();
}

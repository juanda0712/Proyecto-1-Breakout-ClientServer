//
// Created by eduardo on 20/9/21.
//

#include "Game.h"

Game::Game() {
    this->window = new RenderWindow(VideoMode(800, 600), "Crazy Breakout", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);

    this->gameBar = new Bar();
    this->gameBall = new Ball(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y, 5.f);

    this->gamePoints = 0;
    this->currentPoints = 0;
    this->currentLives = 3;
    initBlock();
    initLabel();
}

Game::~Game() {
    delete *blocks;
}

void Game::initLabel() {
    this->pointsT.setString("POINTS: " + std::to_string(currentPoints));
    this->pointsT.setPosition(800.f/15, 600.f - 50);
    this->pointsT.setFillColor(Color::Cyan);
    this->pointsT.setOutlineColor(Color::Yellow);
    this->pointsT.setOutlineThickness(2.f);
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
                if (gameBall->getBall().getGlobalBounds().top == b->blockShape.getGlobalBounds().top) {
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
        gameBall->startMoving();
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
        this->window->close();
    }
    pollEvent();
    updateKey();
    updateBlocks();
    updateBalls();
}

void Game::render() {
    this->window->clear(Color::Black);

    this->window->draw(pointsT);
    for (Block* b : blocks) {
        this->window->draw(b->blockShape);
    }
    this->window->draw(gameBar->getBar());
    this->window->draw(gameBall->getBall());

    this->window->display();
}

//
// Created by eduardo on 20/9/21.
//

#include "Game.h"

Game::Game() {
    this->window = new RenderWindow(VideoMode(800, 600), "Crazy Breakout", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);

    this->gameBar = new Bar();
    this->gameBall = new Ball(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y, 4.f);

    this->gamePoints = 0;
    this->currentPoints = 0;
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
    int counter = 0;
    float varX = 0;
    float varY = 0;
    for (auto & block : blocks) {
        varX += 50;
        if (counter % 15 == 0) {
            varX = 0;
            varY += 50;
        }
        if (counter%2==0) {
            block = BlockFactory::commonBlock(varX, varY);
        }
        else if (counter%3==0){
            block = BlockFactory::doubleBlock(varX, varY);
        }
        else if (counter%4==0) {
            block = BlockFactory::tripleBlock(varX, varY);
        }
        else if (counter%5==0) {
            block = BlockFactory::deepBlock(varX, varY);
        }
        else if (counter%6==0) {
            block = BlockFactory::innerBlock(varX, varY);
        }
        else {
            block = BlockFactory::surpriseBlock(varX, varY);
        }
        counter++;
    }
}

void Game::updatePoints(int points) {
    this->currentPoints += points;
    this->pointsT.setString("POINTS: " + std::to_string(currentPoints));
}

void Game::updateBlocks() {
    for (Block* b : blocks) {
        if (this->gameBall->getBall().getGlobalBounds().intersects(b->blockShape.getGlobalBounds())) {
            b->getHit();
            if (b->getLives() == 0) {
                updatePoints(b->getPoints());
                delete b;
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
    gameBall->ballMovement();
}

void Game::update() {;
    pollEvent();
    updateKey();
    //updateBlocks();
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
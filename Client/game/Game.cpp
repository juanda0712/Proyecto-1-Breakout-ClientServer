//
// Created by eduardo on 20/9/21.
//

#include "Game.h"

Game::Game() {
    this->window = new RenderWindow(VideoMode(800, 600), "Crazy Breakout", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);

    this->gameBar = new Bar();
    this->gameBall = new Ball(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y, 10.f);

    this->gamePoints = 0;
    initBlock();
    initLabel();
}

void Game::initLabel() {
    this->label_points.setString("POINTS: " + std::to_string(this->gamePoints));
    this->label_points.setPosition(540.f, 230.f);
    this->label_points.setFillColor(Color::Cyan);
    this->label_points.setOutlineColor(Color::Yellow);
    this->label_points.setOutlineThickness(2.f);
    this->label_points.setCharacterSize(10);
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
        block = new Block((800.f/15) + varX, 1.f + varY, 3, 30, false, false);
        block->blockShape.setSize(Vector2f(40.f, 20.f));
        block->blockShape.setOrigin(20.f, 10.f);
        block->blockShape.setPosition(block->getX(), block->getY());
        block->blockShape.setFillColor(Color::Green);
        block->blockShape.setOutlineColor(Color::White);
        block->blockShape.setOutlineThickness(2.f);

        counter++;
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
}

void Game::updateBalls() {
    gameBall->updateBallMovement(gameBar);
}

void Game::update() {;
    pollEvent();
    updateKey();
}

void Game::render() {
    this->window->clear(Color::Black);

    for (Block* b : blocks) {
        this->window->draw(b->blockShape);
    }
    this->window->draw(gameBar->getBar());
    this->window->draw(gameBall->getBall());

    this->window->display();
}

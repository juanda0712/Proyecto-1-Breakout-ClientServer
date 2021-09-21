//
// Created by eduardo on 20/9/21.
//

#include "Game.h"

Game::Game() {
    this->window = new RenderWindow(VideoMode(800, 600), "Crazy Breakout", Style::Titlebar | Style::Close);
    this->gameBar = new Bar();
    this->gameBall = new Ball(gameBar->getBar().getPosition().x, gameBar->getBar().getPosition().y);
}

bool Game::isOn() {
    return this->window->isOpen();
}

void Game::update() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == Event::Closed) {
            this->window->close();
            break;
        }
        else if (this->event.type == Event::KeyPressed) {
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
    }
}

void Game::render() {
    this->window->clear(Color::Black);

    this->window->draw(gameBar->getBar());
    this->window->draw(gameBall->getBall());

    this->window->display();
}

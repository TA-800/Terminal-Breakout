#include "game.hpp"
#include <stdlib.h>

Game::Game(WINDOW *win)
{
    this->win = win;
    getmaxyx(win, maxY, maxX);

    this->ball = std::make_unique<Ball>(maxY / 2 - 2, maxX / 2 - 2);
    this->paddle = std::make_unique<Paddle>(maxY - 2, maxX / 2 - 2);
}

// Add powerups.
// 1. Add extra balls
// 2. Increase paddle size

Game::~Game()
{
    free(win);
}

void Game::update()
{
}

void Game::render()
{
    ball->render(win);
    paddle->render(win);
}

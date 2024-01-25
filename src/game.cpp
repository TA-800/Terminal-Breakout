#include "game.hpp"
#include "ball.hpp"
#include <stdlib.h>

Game::Game(WINDOW *win)
{
    this->win = win;
    getmaxyx(win, maxY, maxX);

    this->ball = std::make_unique<Ball>(1, 1);
    this->paddle = std::make_unique<Paddle>(2, maxY - 2);
}

// Add powerups.
// 1. Add extra balls
// 2. Increase paddle size

Game::~Game()
{
    free(win);
}

void Game::update(char input)
{
    mvwprintw(win, 4, 5, "Input: %c", input);
    /* ball->update(); */
    paddle->setDirectionOnInput(input);
    paddle->move();
}

void Game::render()
{
    ball->render(win);
    paddle->render(win);
}

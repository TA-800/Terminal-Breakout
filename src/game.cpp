#include "game.hpp"
#include "ball.hpp"
#include <algorithm>
#include <stdlib.h>

Game::Game(WINDOW *win)
{
    this->win = win;
    getmaxyx(win, maxY, maxX);

    this->ball = std::make_unique<Ball>(4, 4);
    this->paddle = std::make_unique<Paddle>(2, maxY - 6, 6);

    // Initialize bricks at random positions
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        int x = rand() % (maxX - 10) + 1;
        int y = rand() % (maxY - 15) + 1;
        int length = 4;
        int height = 2;

        bricks.push_back(std::make_unique<Brick>(x, y, length, height));
    }
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
    ball->move(maxX, maxY, paddle->getX(), paddle->getY(), paddle->getLength());

    for (auto &brick : bricks)
    {
        /* TODO: Pass proper brick position instead of below */
        int brickX = brick->getX();
        int brickY = brick->getY();

        /* TODO: Include length and height of bricks in collision detection */
        if (ball->collidesWith(brickX, brickY))
        {
            /*  TODO: Change direction of ball */
            ball->changeDirectionOnBrickCollision();

            // Remove brick from vector ( iterator invalidation )
            brick->destroy();
        }
    }

    paddle->setDirectionOnInput(input);
    paddle->move(maxX);
}

void Game::render()
{
    ball->render(win);
    paddle->render(win);

    for (auto &brick : bricks)
    {
        if (!brick->isDestroyed())
            brick->render(win);
    }
}

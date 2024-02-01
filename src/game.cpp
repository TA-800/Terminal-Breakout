#include "game.hpp"
#include "ball.hpp"
#include <stdlib.h>

Game::Game(WINDOW *win)
{
    this->win = win;
    getmaxyx(win, maxY, maxX);

    this->ball = std::make_unique<Ball>(4, 4);
    this->paddle = std::make_unique<Paddle>(2, maxY - 6, 6);

    // Initialize bricks at random positions
    srand(time(NULL));

    for (int i = 0; i < 7; i++)
    {
        int x = rand() % (maxX - 10) + 1;
        int y = rand() % (maxY - 15) + 1;
        int length = 4;
        int height = 2;

        bricks.push_back(std::make_unique<Brick>(x, y, length, height));
    }
}

Game::~Game()
{
    free(win);
}

bool Game::update(char input)
{
    bool isBelow = ball->move(maxX, maxY, paddle->getX(), paddle->getY(), paddle->getLength());
    if (isBelow)
    {
        // Game over
        return true;
    }

    for (auto &brick : bricks)
    {
        if (brick->isDestroyed())
            continue;

        if (ball->collidesWithBrick(brick->getX(), brick->getY(), brick->getLength(), brick->getHeight()))
        {
            // Remove brick from vector ( iterator invalidation )
            brick->destroy();

            ball->changeDirectionOnBrickCollision(brick->getX(), brick->getY(), brick->getLength(), brick->getHeight());
        }
    }

    paddle->setDirectionOnInput(input);
    paddle->move(maxX);

    return false;
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

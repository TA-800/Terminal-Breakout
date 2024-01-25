#include "paddle.hpp"
#include <iostream>

Paddle::Paddle(int x, int y, int paddleSize) : position(std::make_unique<Position>(x, y)), m_paddleSize(paddleSize)
{
}

Paddle::~Paddle()
{
}

void Paddle::setDirectionOnInput(char input)
{
    direction = input == 'a' ? -1 : input == 'd' ? 1 : direction;
}

void Paddle::move(int maxX)
{
    if (direction == 1)
    {

        // Don't move if the paddle is at the right edge of the screen
        if (position->m_x + m_paddleSize >= maxX - 1)
            return;

        position->m_x++;
    }
    else if (direction == -1)
    {

        // Don't move if the paddle is at the left edge of the screen
        if (position->m_x <= 1)
            return;

        position->m_x--;
    }
}

void Paddle::render(WINDOW *win)
{
    /* mvwaddch(win, position->m_y, position->m_x, '_'); */
    for (int i = 0; i < m_paddleSize; i++)
    {
        mvwaddch(win, position->m_y, position->m_x + i, '_');
    }
}

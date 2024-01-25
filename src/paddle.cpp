#include "paddle.hpp"

Paddle::Paddle(int x, int y) : position(std::make_unique<Position>(x, y))
{
}

Paddle::~Paddle()
{
}

void Paddle::move(int direction)
{
    if (direction == 1)
    {
        position->m_y++;
    }
    else if (direction == -1)
    {
        position->m_y--;
    }
}

void Paddle::render(WINDOW *win)
{
    mvwaddch(win, position->m_y, position->m_x, '|');
}

#include "paddle.hpp"

Paddle::Paddle(int x, int y) : position(std::make_unique<Position>(x, y))
{
}

Paddle::~Paddle()
{
}

void Paddle::setDirectionOnInput(char input)
{
    direction = input == 'a' ? -1 : input == 'd' ? 1 : direction;
}

void Paddle::move()
{
    if (direction == 1)
    {
        position->m_x++;
    }
    else if (direction == -1)
    {
        position->m_x--;
    }
}

void Paddle::render(WINDOW *win)
{
    mvwaddch(win, position->m_y, position->m_x, '_');
}

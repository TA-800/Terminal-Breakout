#include "brick.hpp"

Brick::~Brick()
{
}

void Brick::render(WINDOW *win)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < height; j++)
        {
            mvwaddch(win, position->m_y + j, position->m_x + i, 'x');
        }
    }
}

const int Brick::getX() const
{
    return position->m_x;
}

const int Brick::getY() const
{
    return position->m_y;
}

void Brick::destroy()
{
    destroyed = true;
}

bool Brick::isDestroyed()
{
    return destroyed;
}

const int Brick::getLength() const
{
    return length;
}

const int Brick::getHeight() const
{
    return height;
}

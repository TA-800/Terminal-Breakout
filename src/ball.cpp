#include "ball.hpp"

Ball::Ball(int x, int y) : position(std::make_unique<Position>(x, y))
{
}

Ball::~Ball()
{
}

void Ball::move(directionIn dir)
{
    position->m_x += direction[dir][0];
    position->m_y += direction[dir][1];
}

void Ball::render(WINDOW *win)
{
    mvwaddch(win, position->m_y, position->m_x, 'o');
}

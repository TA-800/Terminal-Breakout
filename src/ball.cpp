#include "ball.hpp"

Ball::Ball(int x, int y) : position(std::make_unique<Position>(x, y))
{
}

Ball::~Ball()
{
}

void Ball::setSpeed(int speed)
{
    if (speed > MAX_SPEED)
        speed = MAX_SPEED;

    this->speed = speed;
}

void Ball::move(int maxX, int maxY)
{
    // Flip directions if approaching walls
    if (position->m_x >= maxX - 1 && movingInDirection.x == 1)
        movingInDirection.x = -1;

    else if (position->m_x <= 1 && movingInDirection.x == -1)
        movingInDirection.x = 1;

    if (position->m_y >= maxY - 1 && movingInDirection.y == 1)
        movingInDirection.y = -1;

    else if (position->m_y <= 1 && movingInDirection.y == -1)
        movingInDirection.y = 1;

    position->m_x += movingInDirection.x * speed;
    position->m_y += movingInDirection.y * speed;
}

bool Ball::checkCollision()
{
    // Check left wall
    return false;
}

void Ball::render(WINDOW *win)
{
    mvwaddch(win, position->m_y, position->m_x, 'O');
}

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

void Ball::move(int maxX, int maxY, int paddleX, int paddleY, int paddleLength)
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

    // Check paddle collision
    int paddleCollisionResult = checkPaddleCollision(paddleX, paddleY, paddleLength);
    if (paddleCollisionResult != 0)
    {
        movingInDirection.y = -1;
        movingInDirection.x = paddleCollisionResult;
    }

    position->m_x += movingInDirection.x * speed;
    position->m_y += movingInDirection.y * speed;
}

int Ball::checkPaddleCollision(int paddleX, int paddleY, int paddleLength)
{
    if (position->m_y == paddleY)
    {
        if (position->m_x >= paddleX && position->m_x <= paddleX + paddleLength)
        {
            if (position->m_x - paddleX <= paddleLength / 2)
                return -1;
            else
                return 1;
        }
    }

    return 0;
}

void Ball::render(WINDOW *win)
{
    mvwaddch(win, position->m_y, position->m_x, 'O');
}

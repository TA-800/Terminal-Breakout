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

// Flip directions after hitting a brick
void Ball::changeDirectionOnBrickCollision(){};

// Flip directions if approaching walls
void Ball::changeDirectionsOnWallCollision(int maxX, int maxY)
{
    // X axis
    if (position->m_x >= maxX - 1 && movingInDirection.x == 1)
        movingInDirection.x = -1;

    else if (position->m_x <= 1 && movingInDirection.x == -1)
        movingInDirection.x = 1;
    // Y axis
    if (position->m_y >= maxY - 1 && movingInDirection.y == 1)
        movingInDirection.y = -1;

    else if (position->m_y <= 1 && movingInDirection.y == -1)
        movingInDirection.y = 1;
}

// Make ball bounce off paddle to the left if it hits the left side of the paddle and vice versa
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

    // No collision
    return 0;
}

// Constantly move the ball after checking for collisions
void Ball::move(int maxX, int maxY, int paddleX, int paddleY, int paddleLength)
{
    // Check wall collision
    changeDirectionsOnWallCollision(maxX, maxY);

    // Check paddle collision
    int paddleCollisionResult = checkPaddleCollision(paddleX, paddleY, paddleLength);
    if (paddleCollisionResult != 0)
    {
        // Invert y to make it go up on paddle collision
        movingInDirection.y = -1;
        movingInDirection.x = paddleCollisionResult;
    }

    // Move ball
    position->m_x += movingInDirection.x * speed;
    position->m_y += movingInDirection.y * speed;
}

bool Ball::collidesWith(int brickX, int brickY)
{
    bool hasCollided = false;

    // Check if ball is within the bounds of the brick (x + length, y + height)
    if (this->position->m_x >= brickX && this->position->m_x <= brickX + 4)
    {
        if (this->position->m_y >= brickY && this->position->m_y <= brickY + 2)
        {
            hasCollided = true;
        }
    }

    // TODO: if hasCollided, change direction of ball

    return hasCollided;
}

void Ball::render(WINDOW *win)
{
    mvwaddch(win, position->m_y, position->m_x, 'O');
}

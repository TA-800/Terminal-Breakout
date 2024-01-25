#ifndef BALL_HPP
#define BALL_HPP

#define MAX_SPEED 5

#include "position.hpp"
#include <memory>
#include <ncurses/ncurses.h>

enum BallDirection
{
    UP_RIGHT,
    DOWN_RIGHT,
    UP_LEFT,
    DOWN_LEFT
};

class Ball
{
    std::unique_ptr<Position> position;
    struct movingInDirection
    {
        int x;
        int y;
    } movingInDirection = {1, 1};

    int speed = 1;

  public:
    Ball(int x, int y);
    ~Ball();
    void move(int maxX, int maxY);
    bool checkCollision();
    void render(WINDOW *win);

    void setSpeed(int speed);
};

#endif // !BALL_HPP

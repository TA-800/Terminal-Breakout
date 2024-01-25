#ifndef BALL_HPP
#define BALL_HPP

#include "position.hpp"
#include <memory>
#include <ncurses/ncurses.h>

class Ball
{
    std::unique_ptr<Position> position;

    int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    enum directionIn
    {
        up,
        down,
        left,
        right
    };

  public:
    Ball(int x, int y);
    ~Ball();
    void move(directionIn dir);
    void render(WINDOW *win);
};

#endif // !BALL_HPP

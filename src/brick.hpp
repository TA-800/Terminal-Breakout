#ifndef BRICK_HPP
#define BRICK_HPP

#include "position.hpp"
#include <memory>
#include <ncurses/ncurses.h>

class Brick
{
    std::unique_ptr<Position> position;
    int length;
    int height;
    bool destroyed = false;

  public:
    Brick(int x, int y, int length, int height)
        : position(std::make_unique<Position>(x, y)), length(length), height(height)
    {
    }

    ~Brick();

    void render(WINDOW *win);

    const int getX() const;
    const int getY() const;

    void destroy();
    bool isDestroyed();
};

#endif // BRICK_HPP

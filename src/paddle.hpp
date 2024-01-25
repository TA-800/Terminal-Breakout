#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "position.hpp"
#include <memory>
#include <ncurses/ncurses.h>

class Paddle
{
  private:
    std::unique_ptr<Position> position;

  public:
    Paddle(int x, int y);
    ~Paddle();

    void move(int direction);
    void render(WINDOW *win);
};

#endif // PADDLE_HPP

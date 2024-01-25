#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "position.hpp"
#include <memory>
#include <ncurses/ncurses.h>

class Paddle
{
  private:
    std::unique_ptr<Position> position;
    int direction = 0;

  public:
    Paddle(int x, int y);
    ~Paddle();

    void setDirectionOnInput(char direction);
    void move();
    void render(WINDOW *win);
};

#endif // PADDLE_HPP

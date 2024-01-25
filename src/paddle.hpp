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
    int m_paddleSize;

  public:
    Paddle(int x, int y, int paddleSize);
    ~Paddle();

    void setDirectionOnInput(char direction);
    void move(int maxX);
    void render(WINDOW *win);

    int getX()
    {
        return position->m_x;
    }

    int getY()
    {
        return position->m_y;
    }

    int getLength()
    {
        return m_paddleSize;
    }
};

#endif // PADDLE_HPP

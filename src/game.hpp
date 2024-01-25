#ifndef GAME_HPP
#define GAME_HPP

#define HEIGHT 20
#define WIDTH 40

#include "ball.hpp"
#include "paddle.hpp"
#include <ncurses/ncurses.h>

class Game
{

  private:
    WINDOW *win = nullptr;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Paddle> paddle;
    int maxY, maxX;

  public:
    Game(WINDOW *win);
    ~Game();

    void update(char input);
    void render();
};

#endif // GAME_HPP

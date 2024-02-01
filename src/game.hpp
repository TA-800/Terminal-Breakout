#ifndef GAME_HPP
#define GAME_HPP

#include "brick.hpp"
#include <vector>
#define HEIGHT 20
#define WIDTH 40

#include "ball.hpp"
#include "paddle.hpp"
#include <ncurses/ncurses.h>

typedef std::vector<std::unique_ptr<Brick>> BrickVector;

class Game
{

  private:
    WINDOW *win = nullptr;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Paddle> paddle;
    BrickVector bricks;
    int maxY, maxX;

  public:
    Game(WINDOW *win);
    ~Game();

    bool update(char input);
    void render();
};

#endif // GAME_HPP

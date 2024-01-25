#include "game.hpp"
#include <ncurses/ncurses.h>

void initUI()
{
    initscr();
    cbreak();
    noecho();
    refresh();
}

int main()
{
    initUI();

    // Creates a new window with specified dimensions and position
    WINDOW *win = newwin(HEIGHT, WIDTH, 0, 0);
    refresh();

    // Draws the box around the window
    box(win, 0, 0);

    std::unique_ptr<Game> game = std::make_unique<Game>(win);

    game->render();
    wrefresh(win);

    getch();

    endwin();
    return 0;
}

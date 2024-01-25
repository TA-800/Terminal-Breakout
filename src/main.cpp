#include "game.hpp"
#include <ncurses/ncurses.h>
#include <thread>

bool isRunning = true;
char input;

void initUI()
{
    initscr();
    cbreak();
    noecho();
    refresh();
}

// Get input in non-blocking mode in a separate thread
void getInput()
{
    while (isRunning)
    {
        input = wgetch(stdscr);
        if (input == 'q')
        {
            isRunning = false;
        }
    }
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

    // Start a new thread that waits for user input
    std::thread inputThread(getInput);

    game->render();
    wrefresh(win);

    while (isRunning)
    {
        game->update(input);
        game->render();
        wrefresh(win);
        // Sleep for 100 milliseconds, effectively setting a framerate
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Wait for the input thread to finish
    inputThread.join();

    endwin();
    return 0;
}

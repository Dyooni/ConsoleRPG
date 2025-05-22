#include "Renderer.h"

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

void Renderer::SetupTerminal() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void Renderer::ConsoleClear() {
    system("clear");
}

void Renderer::Rendering(Player& player, Background& background) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == player.get_y() && x == player.get_x())
                std::cout << player.get_shape();
            else
                std::cout << background.GetField(x, y);
        }

        if (y > 1 && y < background.Guide_Y() + 2) {
            for (int x = 0; x < background.Guide_X(); x++) {
                std::cout << background.GetGuide(x, y - 2);
            }
        }
        std::cout << std::endl;
    }
}

void Renderer::Rendering(Title& title) {
    for (int y = 0; y < title.Length_Y(); y++) {
        for (int x = 0; x < title.Length_X(); x++) {
            if (y == title.CursorY() && x == title.CursorX())
                std::cout << title.GetCursor();
            else
                std::cout << title.GetTitle(x, y);
        }
        std::cout << std::endl;
    }
}
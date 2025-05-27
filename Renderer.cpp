#include "Renderer.h"

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#include "MonsterSpawner.h"

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

void Renderer::RenderingGuide(Background& background, int y) {
    if (y > 1 && y < background.GuideY() + 2) {
        for (int x = 0; x < background.GuideX(); x++) {
            std::cout << background.GetGuide(x, y - 2);
        }
    }
}

void Renderer::RenderingStatus(Player& player, Background& background, int y) {
    if (y > 1 && y < background.StatusY() + 2) {
        background.PrintStatus(player, y - 2);

        // for (int x = 0; x <= background.StatusX(); x++) {
        //     if (x < background.StatusX())
        //         std::cout << background.GetStatus(x, y - 2);
        //     else {

        //     }
        // }
    }
}

void Renderer::Rendering(Player& player, Background& background, MonsterSpawner& monsterSpawner, int turnState) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == player.Y() && x == player.X())
                std::cout << player.Shape();
            else if (monsterSpawner.CurrentPosition(x, y))
                std::cout << monsterSpawner.GetMonster();
            else
                std::cout << background.GetField(x, y);
        }

        if (turnState == 0) RenderingGuide(background, y);
        else if (turnState == 1) RenderingStatus(player, background, y);
        // if (y > 1 && y < background.GuideY() + 2) {
        //     for (int x = 0; x < background.GuideX(); x++) {
        //         std::cout << background.GetGuide(x, y - 2);
        //     }
        // }
        std::cout << std::endl;
    }
}

void Renderer::Rendering(Player& player, Background& background, int turnState) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == player.Y() && x == player.X())
                std::cout << player.Shape();
            else
                std::cout << background.GetVillage(x, y);
        }

        if (turnState == 0) RenderingGuide(background, y);
        else if (turnState == 1) RenderingStatus(player, background, y);
        // if (y > 1 && y < background.GuideY() + 2) {
        //     for (int x = 0; x < background.GuideX(); x++) {
        //         std::cout << background.GetGuide(x, y - 2);
        //     }
        // }
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

        if (y > 1 && y < title.GuideY()) {
            for (int x = 0; x < title.GuideX(); x++) {
                std::cout << title.GetGuide(x, y - 2);
            }
        }
        std::cout << std::endl;
    }
}
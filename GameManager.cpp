#include "GameManager.h"

#include <unistd.h>

void GameManager::Init() {
    
}

void GameManager::MainTitle() {
    renderer.SetupTerminal();

    while (true) {
        renderer.ConsoleClear();

        if (input.num1()) GameLoop();
        else if (input.num2()) break;

        renderer.Rendering(title);

        usleep(50000);
    }
}

void GameManager::GameLoop() {
    renderer.SetupTerminal();

    while (true) {
        renderer.ConsoleClear();

        if (input.A() && background.GetField(player.get_x() - 1, player.get_y()) != '#') {
            if (background.GetField(player.get_x() - 2, player.get_y()) == '#')
                player.MoveLeft(1);
            else
                player.MoveLeft(2);
        }
        else if (input.D() && background.GetField(player.get_x() + 1, player.get_y()) != '#') {
            if (background.GetField(player.get_x() + 2, player.get_y()) == '#')
                player.MoveRight(1);
            else
                player.MoveRight(2);
        }
        else if (input.W() && background.GetField(player.get_x(), player.get_y() - 1) != '#') player.MoveUp(1);
        else if (input.S() && background.GetField(player.get_x(), player.get_y() + 1) != '#') player.MoveDown(1);

        if (input.Q()) break;

        renderer.Rendering(player, background);
        usleep(50000);
    }
}
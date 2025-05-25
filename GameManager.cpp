#include "GameManager.h"

#include <unistd.h>
#include <iostream> // 임시

void GameManager::Init() {
    
}

void GameManager::MainTitle() {
    renderer.SetupTerminal();

    int cursorY = title.CursorY();

    while (true) {
        renderer.ConsoleClear();

        if (input.Up()) cursorY--;
        else if (input.Down()) cursorY++;

        cursorY = (cursorY + 2) % 2 + 6;
        title.MoveCursor(cursorY);

        if (input.Enter() || input.Space()) {
            if (title.CursorY() == 6) GameLoop();
            else if (title.CursorY() == 7) break;
        }

        renderer.Rendering(title);

        usleep(50000);
    }
}

void GameManager::GameLoop() {
    renderer.SetupTerminal();

    monsterSpawner.SetPosition();

    while (true) {
        renderer.ConsoleClear();

        if (input.Left() && background.GetField(player.get_x() - 1, player.get_y()) != '#') {
            if (background.GetField(player.get_x() - 2, player.get_y()) == '#')
                player.MoveLeft(1);
            else
                player.MoveLeft(1);
        }
        else if (input.Right() && background.GetField(player.get_x() + 1, player.get_y()) != '#') {
            if (background.GetField(player.get_x() + 2, player.get_y()) == '#')
                player.MoveRight(1);
            else
                player.MoveRight(1);
        }
        else if (input.Up() && background.GetField(player.get_x(), player.get_y() - 1) != '#') player.MoveUp(1);
        else if (input.Down() && background.GetField(player.get_x(), player.get_y() + 1) != '#') player.MoveDown(1);

        if (input.Q()) break;

        renderer.Rendering(player, background, monsterSpawner);
        usleep(50000);
    }
}
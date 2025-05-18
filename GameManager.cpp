#include "GameManager.h"
#include "Renderer.h"
#include "Player.h"
#include "Background.h"
#include "InputSystem.h"

#include <unistd.h>

void GameManager::GameLoop() {
    Renderer renderer;
    Player player;
    Background background;
    InputSystem input;

    renderer.SetupTerminal();

    while (true) {
        renderer.ConsoleClear();

        if (input.A() && background.GetBackground(player.get_x() - 1, player.get_y()) != '#') {
            if (background.GetBackground(player.get_x() - 2, player.get_y()) == '#')
                player.MoveLeft(1);
            else
                player.MoveLeft(2);
        }
        else if (input.D() && background.GetBackground(player.get_x() + 1, player.get_y()) != '#') {
            if (background.GetBackground(player.get_x() + 2, player.get_y()) == '#')
                player.MoveRight(1);
            else
                player.MoveRight(2);
        }
        else if (input.W() && background.GetBackground(player.get_x(), player.get_y() - 1) != '#') player.MoveUp(1);
        else if (input.S() && background.GetBackground(player.get_x(), player.get_y() + 1) != '#') player.MoveDown(1);

        if (input.Q()) break;

        renderer.Rendering(player, background);
        usleep(50000);
    }
}
#include "SceneManager.h"

#include <unistd.h>

void SceneManager::MainTitle() {
    int cursorY = title.CursorY();

    while (true) {
        renderer.ConsoleClear();

        if (input.Up()) cursorY--;
        else if (input.Down()) cursorY++;

        cursorY = (cursorY + 2) % 2 + 6;
        title.MoveCursor(cursorY);

        if (input.Enter() || input.Space()) {
            if (title.CursorY() == 6) {
                if (player.CurPlace(0))
                    Village();
                else if (player.CurPlace(1))
                    Field();
            }
            else if (title.CursorY() == 7) exit(-1);
        }

        renderer.Rendering(title);

        usleep(50000);
    }
}

void SceneManager::Village() {
    while (true) {
        renderer.ConsoleClear();

        if (input.Left() && !background.IsWall_Village(player.X() - 1, player.Y()))
            player.MoveLeft();
        else if (input.Right() && !background.IsWall_Village(player.X() + 1, player.Y()))
            player.MoveRight();
        else if (input.Up() && !background.IsWall_Village(player.X(), player.Y() - 1))
            player.MoveUp();
        else if (input.Down() && !background.IsWall_Village(player.X(), player.Y() + 1))
            player.MoveDown();

        if (input.Q()) MainTitle();

        if (background.IsField_Village(player.X(), player.Y())) {
            player.SetPosition(3, HEIGHT / 2);
            player.SetPlace(1);
            Field();
        }

        if (input.S()) turnStatus = (turnStatus + 1) % 2;

        // if (input.D()) player.TakeDamage(200);
        // if (input.E()) player.GainExp(5000);
        // if (input.H()) player.GetHealed(100);

        renderer.Rendering(player, background, turnStatus);
        usleep(50000);
    }
}

void SceneManager::Field() {
    monsterSpawner.SetPosition();

    while (true) {
        renderer.ConsoleClear();

        if (input.Left() && !background.IsWall_Field(player.X() - 1, player.Y()))
            player.MoveLeft();
        else if (input.Right() && !background.IsWall_Field(player.X() + 1, player.Y()))
            player.MoveRight();
        else if (input.Up() && !background.IsWall_Field(player.X(), player.Y() - 1))
            player.MoveUp();
        else if (input.Down() && !background.IsWall_Field(player.X(), player.Y() + 1))
            player.MoveDown();

        if (input.Q()) MainTitle();

        if (background.IsVillage_Field(player.X(), player.Y())) {
            player.SetPosition(WIDTH - 4, HEIGHT / 2);
            player.SetPlace(0);
            Village();
        }

        if (input.S()) turnStatus = (turnStatus + 1) % 2;

        // if (input.D()) player.TakeDamage(200);
        // if (input.E()) player.GainExp(5000);
        // if (input.H()) player.GetHealed(100);

        renderer.Rendering(player, background, monsterSpawner, turnStatus);
        usleep(50000);
    }
}
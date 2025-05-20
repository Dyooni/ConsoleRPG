#pragma once

#include "Renderer.h"
#include "Player.h"
#include "Background.h"
#include "Title.h"
#include "InputSystem.h"

class GameManager {
public:
    void Init();
    void MainTitle();
    void GameLoop();

private:
    Renderer renderer;
    Player player;
    Background background;
    InputSystem input;
    Title title;
};
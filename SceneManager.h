#pragma once

#include "Renderer.h"
#include "Player.h"
#include "MonsterSpawner.h"
#include "Background.h"
#include "Title.h"
#include "InputSystem.h"

class SceneManager {
public:
    void MainTitle();
    void Village();
    void Field();
    void Battle();

private:
    Renderer renderer;
    Player player;
    MonsterSpawner monsterSpawner;
    Background background;
    InputSystem input;
    Title title;

    int turnStatus = 0;
};
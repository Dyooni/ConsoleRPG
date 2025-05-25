#pragma once

#include "Player.h"
#include "MonsterSpawner.h"
#include "Background.h"
#include "Title.h"

class Renderer {
public:
    void SetupTerminal();
    void ConsoleClear();

    void Rendering(Player& player, Background& background, MonsterSpawner& monsterSpawner);
    void Rendering(Title& title);
};
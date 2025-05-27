#pragma once

#include "Player.h"
#include "MonsterSpawner.h"
#include "Background.h"
#include "Title.h"

class Renderer {
public:
    void SetupTerminal();
    void ConsoleClear();

    void Rendering(Player& player, Background& background, MonsterSpawner& monsterSpawner, int turnState);
    void Rendering(Player& player, Background& background, int turnState);
    void Rendering(Title& title);

    void RenderingGuide(Background& background, int y);
    void RenderingStatus(Player& player, Background& background, int y);
};
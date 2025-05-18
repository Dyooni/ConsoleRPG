#pragma once

#include "Player.h"
#include "Background.h"

class Renderer {
public:
    void SetupTerminal();
    void ConsoleClear();

    void Rendering(Player& player, Background& background);
};
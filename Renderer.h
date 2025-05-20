#pragma once

#include "Player.h"
#include "Background.h"
#include "Title.h"

class Renderer {
public:
    void SetupTerminal();
    void ConsoleClear();

    void Rendering(Player& player, Background& background);
    void Rendering(Title& title);
};
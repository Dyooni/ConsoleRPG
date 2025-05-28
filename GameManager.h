#pragma once

#include "Renderer.h"
#include "SceneManager.h"

class GameManager {
public:
    void GameLoop();

private:
    Renderer renderer;
    SceneManager sceneManager;
};
#include "GameManager.h"

#include <unistd.h>

void GameManager::GameLoop() {
    renderer.SetupTerminal();

    sceneManager.MainTitle();
}
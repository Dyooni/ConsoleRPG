#pragma once

#include <iostream>
#include <vector>

#include "Background.h"
#include "Monster.h"

class MonsterSpawner {
public:
    MonsterSpawner();
    ~MonsterSpawner();

    void RandomPosition(int i);
    void SetPosition();

    bool CurrentPosition(int x, int y);

    char GetMonster();

private:
    Monster* monsters;
    const int count = 20;
    int current;
};
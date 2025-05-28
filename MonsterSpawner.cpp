#include "MonsterSpawner.h"

MonsterSpawner::MonsterSpawner() {
    monsters = new Monster[count];
    current = 0;
}

MonsterSpawner::~MonsterSpawner() {
    if (monsters) delete[] monsters;
}

void MonsterSpawner::RandomPosition(int i) {
    int max_x = WIDTH - 2;
    int max_y = HEIGHT - 2;

    int new_x = rand() % max_x + 1;
    int new_y = rand() % max_y + 1;

    Background background;

    if (background.IsWall_Field(new_x, new_y))
        return;

    monsters[i].SetPosision(new_x, new_y);
}

void MonsterSpawner::SetPosition() {
    srand(time(NULL));

    for (int i = 0; i < count; i++)
        RandomPosition(i);
}

bool MonsterSpawner::CurrentPosition(int x, int y) {
    for (int i = 0; i < count; i++) {
        if (x == monsters[i].X() && y == monsters[i].Y()) {
            current = i;
            return true;
        }
    }
    return false;
}

char MonsterSpawner::GetMonster() {
    return monsters[current].Shape();
}
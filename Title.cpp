#include "Title.h"

char Title::GetTitle(int x, int y) const {
    return title[y][x];
}

int Title::Length_X() const {
    return WIDTH + 1;
}

int Title::Length_Y() const {
    return HEIGHT / 2 + 1;
}
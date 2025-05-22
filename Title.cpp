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

char Title::GetCursor() const {
    return cursor.image;
}

int Title::CursorX() const {
    return cursor.x;
}

int Title::CursorY() const {
    return cursor.y;
}

void Title::MoveCursor(int y) {
    cursor.y = y;
}

char Title::GetGuide(int x, int y) {
    return background.GetGuide(x, y);
}

int Title::GuideX() {
    return background.Guide_X();
}

int Title::GuideY() {
    return background.Guide_Y();
}
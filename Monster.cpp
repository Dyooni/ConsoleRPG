#include "Monster.h"

void Monster::SetPosision(int x, int y) {
    this->x = x;
    this->y = y;
}

int Monster::X() const {
    return x;
}

int Monster::Y() const {
    return y;
}

char Monster::Shape() const {
    return shape;
}

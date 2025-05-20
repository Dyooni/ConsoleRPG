#include "Background.h"

char Background::GetField(int x, int y) const {
    return field.image[y][x];
}

char Background::GetGuide(int x, int y) const {
    return guide.image[y][x];
}

int Background::Field_X() const {
    return field.x;
}

int Background::Field_Y() const {
    return field.y;
}

int Background::Guide_X() const {
    return guide.x;
}

int Background::Guide_Y() const {
    return guide.y;
}
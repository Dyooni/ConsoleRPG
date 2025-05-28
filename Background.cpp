#include "Background.h"

#include <iostream>

char Background::GetVillage(int x, int y) const {
    return village.image[y][x];
}

char Background::GetField(int x, int y) const {
    return field.image[y][x];
}

char Background::GetGuide(int x, int y) const {
    return guide.image[y][x];
}

char Background::Wall() const {
    return wall;
}

int Background::VillageX() const {
    return village.x;
}

int Background::VillageY() const {
    return village.y;
}

int Background::FieldX() const {
    return field.x;
}

int Background::FieldY() const {
    return field.y;
}

int Background::GuideX() const {
    return guide.x;
}

int Background::GuideY() const {
    return guide.y;
}

int Background::StatusX() const {
    return status.x;
}

int Background::StatusY() const {
    return status.y;
}

bool Background::IsWall_Village(int x, int y) {
    return GetVillage(x, y) == Wall();
}

bool Background::IsWall_Field(int x, int y) {
    return GetField(x, y) == Wall();
}

bool Background::IsField_Village(int x, int y) {
    if (GetVillage(x, y) == 'f')
        return true;
    else
        return false;
}

bool Background::IsVillage_Field(int x, int y) {
    if (GetField(x, y) == 'v')
        return true;
    else
        return false;
}

void Background::PrintStatus(Player& player, int n) {
    std::cout << status.image[n];

    switch (n)
    {
    case 2:
        std::cout << player.GetLevel();
        break;
    
    case 3:
        std::cout << player.GetCurHp() << " / " << player.GetMaxHp();
        break;
    
    case 4:
        std::cout << player.GetCurMp() << " / " << player.GetMaxMp();
        break;

    case 5:
        std::cout << player.GetCurExp();
        break;

    case 7:
        std::cout << player.GetAttack();
        break;

    case 8:
        std::cout << player.GetDeffence();
        break;
    
    case 9:
        std::cout << player.GetSpeed();
        break;

    default:
        break;
    }
}
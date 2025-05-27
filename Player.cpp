#include "Player.h"
#include "Background.h"

#include <iostream>

Player::Player() {
    x = WIDTH / 2;
    y = HEIGHT / 2;

    curPlace = 0;
}

void Player::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Player::SetPlace(int i) {
    curPlace = i;
}

void Player::MoveLeft() {
    x--;
}

void Player::MoveRight() {
    x++;
}

void Player::MoveUp() {
    y--;
}

void Player::MoveDown() {
    y++;
}

int Player::X() const {
    return x;
}

int Player::Y() const {
    return y;
}

char Player::Shape() const {
    return shape;
}

bool Player::CurPlace(int i) {
    if (curPlace == i)
        return true;
    else
        return false;
}

void Player::GainExp(int exp) {
    unsigned int newExp = curExp + exp;

    while (newExp >= maxExp) {
        newExp -= maxExp;
        LevelUp();
    }
    // if (newExp >= maxExp) {
    //     while (new)
    //     newExp -= maxExp;
    //     LevelUp();
    // }

    curExp = newExp;
}

void Player::TakeDamage(int damage) {
    int newDamage = damage - deffence;

    if (curHp <= newDamage)
        Death();
    else
        curHp -= newDamage;
}

void Player::GetHealed(int hp) {
    unsigned int newHp = curHp + hp;
    curHp = newHp >= maxHp ? maxHp : newHp;
}

void Player::UseMana(int mp) {
    if (curMp <= mp)
        curMp = 0;
    else
        curMp -= mp;
}

void Player::RestoreMana(int mp) {
    unsigned int newMp = curMp + mp;
    curMp = newMp >= maxMp ? maxMp : newMp;
}

void Player::LevelUp() {
    unsigned int newLevel = level + 1;

    if (newLevel >= 99) {
        level = 99;
        curExp = maxExp;
    }
    else {
        maxExp += maxExp / 10;

        maxHp += level * 12;
        curHp = maxHp;

        maxMp += level * 8;
        curMp = maxMp;

        attack += level % 4;
        deffence += level % 3;
        speed += level % 2;

        level++;
    }
}

void Player::Death() {
    exit(-1);
}

unsigned int Player::GetMaxHp() const { return maxHp; }
unsigned int Player::GetCurHp() const { return curHp; }
unsigned int Player::GetMaxMp() const { return maxMp; }
unsigned int Player::GetCurMp() const { return curMp; }

unsigned int Player::GetLevel() const { return level; }
unsigned int Player::GetMaxExp() const { return maxExp; }
unsigned int Player::GetCurExp() const { return curExp; }

unsigned int Player::GetAttack() const { return attack; }
unsigned int Player::GetDeffence() const { return deffence; }
unsigned int Player::GetSpeed() const { return speed; }
#include "Player.h"
#include "Background.h"

Player::Player() {
    x = WIDTH / 2;
    y = HEIGHT / 2;
    shape = 'O';
}

void Player::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Player::MoveLeft(int n) {
    x -= n;
}

void Player::MoveRight(int n) {
    x += n;
}

void Player::MoveUp(int n) {
    y -= n;
}

void Player::MoveDown(int n) {
    y += n;
}

int Player::get_x() const {
    return x;
}

int Player::get_y() const {
    return y;
}

char Player::get_shape() const {
    return shape;
}
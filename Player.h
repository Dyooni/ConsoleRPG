#pragma once

class Player {
public:
    Player();

    void SetPosition(int x, int y);

    void MoveLeft(int n);
    void MoveRight(int n);
    void MoveUp(int n);
    void MoveDown(int n);

    int get_x();
    int get_y();

    char get_shape();

private:
    int x, y;
    char shape;
};
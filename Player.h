#pragma once

class Player {
public:
    Player();

    void SetPosition(int x, int y);

    void MoveLeft(int n);
    void MoveRight(int n);
    void MoveUp(int n);
    void MoveDown(int n);

    int get_x() const;
    int get_y() const;

    char get_shape() const;

private:
    int x, y;
    const char shape = 'O';
};
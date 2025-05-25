#pragma once

class Monster
{
public:
    void SetPosision(int x, int y);

    int X() const;
    int Y() const;

    char Shape() const;

private:
    int x, y;
    const char shape = 'M';
};
#pragma once

#include "Background.h"

class Title {
    struct Cursor {
        char image = '>';
        int x = 11;
        int y = 6;
    };

public:
    char GetTitle(int x, int y) const;
    int Length_X() const;
    int Length_Y() const;

    char GetCursor() const;
    void MoveCursor(int y);
    int CursorX() const;
    int CursorY() const;

private:
    char title[HEIGHT / 2 + 1][WIDTH + 1] = {
        "########################################",
        "#                                      #",
        "#                                      #",
        "#            CONSOLE_RPG               #",
        "#                                      #",
        "#                                      #",
        "#            1. START                  #",
        "#            2. QUIT                   #",
        "#                                      #",
        "#                                      #",
        "########################################"
    };

    Cursor cursor;
};
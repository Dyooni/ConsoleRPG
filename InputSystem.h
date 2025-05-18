#pragma once

class InputSystem {
public:
    int kbhit();
    char getch();

    void Input();

    bool A();
    bool D();
    bool W();
    bool S();
    bool Q();

private:
    char input;
};
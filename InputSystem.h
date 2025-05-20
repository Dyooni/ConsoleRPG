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
    bool num1();
    bool num2();

private:
    char input;
};
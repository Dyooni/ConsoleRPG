#pragma once

class InputSystem {
public:
    int kbhit();
    char getch();

    void Input();

    bool D();
    bool H();
    bool E();
    bool M();
    
    bool S();
    bool Q();
    bool Enter();
    bool Space();
    bool Up();
    bool Down();
    bool Right();
    bool Left();
    
    void InputArrow();

private:
    char input;
};
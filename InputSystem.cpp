#include "InputSystem.h"

#include <unistd.h>

int InputSystem::kbhit() {
    struct timeval tv = { 0, 0 };
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
}

char InputSystem::getch() {
    char c;
    if (read(STDIN_FILENO, &c, 1) < 0) return 0;
    return c;
}

void InputSystem::Input() {
    if (kbhit()) {
        input = getch();
    }
}

bool InputSystem::A() {
    Input();

    if (input == 'a') {
        input = NULL;
        return true;
    }
    else
        return false;
}

bool InputSystem::D() {
    Input();

    if (input == 'd') {
        input = NULL;
        return true;
    }
    else
        return false;
}

bool InputSystem::W() {
    Input();

    if (input == 'w') {
        input = NULL;
        return true;
    }
    else
        return false;
}

bool InputSystem::S() {
    Input();

    if (input == 's') {
        input = NULL;
        return true;
    }
    else
        return false;
}

bool InputSystem::Q() {
    Input();

    if (input == 'q') {
        input = NULL;
        return true;
    }
    else
        return false;
}
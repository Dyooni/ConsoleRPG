#pragma once

const int WIDTH = 40;
const int HEIGHT = 20;

class Background {
public:
    char GetBackground(int x, int y);

private:
    char background[HEIGHT][WIDTH + 1] = {
        "########################################",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "########################################",
    };
};
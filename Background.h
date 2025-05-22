#pragma once

const int WIDTH = 40;
const int HEIGHT = 20;

class Background {
    struct Field {
        char image[HEIGHT][WIDTH + 1] = {
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

        int x = WIDTH;
        int y = HEIGHT;
    };

    struct Guide {
        char image[5][18 + 1] = {
            " KEY GUIDE        ",
            " Move : ARROW KEYS",
            " Select : ENTER   ",
            "          SPACE   ",
            // " A : MOVE LEFT   ",
            // " D : MOVE RIGHT  ",
            // " W : MOVE UP     ",
            // " S : MOVE DOWN   ",
            " Return Title : Q "
        };

        int x = 18;
        int y = 5;
    };

public:
    char GetField(int x, int y) const;
    char GetGuide(int x, int y) const;

    int Field_X() const;
    int Field_Y() const;
    int Guide_X() const;
    int Guide_Y() const;

private:
    Field field;
    Guide guide;
};
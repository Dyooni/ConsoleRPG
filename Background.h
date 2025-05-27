#pragma once

#include "Player.h"

const int WIDTH = 40;
const int HEIGHT = 20;

class Background {
    struct Village {
        char image[HEIGHT][WIDTH + 1] = {
            "########################################",
            "#                                      #",
            "#    #######                           #",
            "#    #STORE#                           #",
            "#    #######                           #",
            "#    #     #                           #",
            "#                                      #",
            "#                                    ###",
            "#                                      f",
            "#                                      f",
            "#                                      f",
            "#                                      f",
            "#                                    ###",
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

    struct Field {
        char image[HEIGHT][WIDTH + 1] = {
            "########################################",
            "#                                      #",
            "#                                      #",
            "#                                      #",
            "#                                      #",
            "#                                      #",
            "#                                      #",
            "##########         ###########         #",
            "v        #         #         #         #",
            "v        #         #         #         #",
            "v        #         #         #         #",
            "v        #         #         #         #",
            "###      #                   #         #",
            "#        #                   #         #",
            "#        #                   #         #",
            "#        #####################         #",
            "#                                      #",
            "#                                      #",
            "#                                      #",
            "########################################",
        };

        int x = WIDTH;
        int y = HEIGHT;
    };

    struct Guide {
        char image[6][18 + 1] = {
            " KEY GUIDE        ",
            " Move   ARROW KEYS",
            " Select ENTER     ",
            "        SPACE     ",
            " Status S         ",
            " Title  Q         "
        };

        int x = 18;
        int y = 6;
    };

    struct Status {
        char image[12][8 + 1] = {
            " STATUS",
            "       ",
            " LEV   ",
            " HP    ",
            " MP    ",
            " EXP   ",
            "       ",
            " ATK   ",
            " DEF   ",
            " SPD   ",
            "       ",
            " Exit  S"
        };

        int x = 8;
        int y = 12;
    };

public:
    char GetVillage(int x, int y) const;
    char GetField(int x, int y) const;
    char GetGuide(int x, int y) const;
    // char GetStatus(int x, int y) const;

    char Wall() const;

    int VillageX() const;
    int VillageY() const;

    int FieldX() const;
    int FieldY() const;

    int GuideX() const;
    int GuideY() const;

    int StatusX() const;
    int StatusY() const;

    void PrintStatus(Player& player, int n);

    bool IsWall_Village(int x, int y);
    bool IsWall_Field(int x, int y);

    bool IsField_Village(int x, int y);
    bool IsVillage_Field(int x, int y);

private:
    Village village;
    Field field;
    Guide guide;
    Status status;

    Player player;

    char wall = '#';
};
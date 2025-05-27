#pragma once

class Player {
public:
    Player();

    void SetPosition(int x, int y);
    void SetPlace(int i);

    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

    int X() const;
    int Y() const;

    char Shape() const;

    bool CurPlace(int i);

    void GainExp(int exp);
    void TakeDamage(int damage);
    void GetHealed(int hp);
    void UseMana(int mp);
    void RestoreMana(int mp);

    void LevelUp();
    void Death();

    unsigned int GetMaxHp() const;
    unsigned int GetCurHp() const;
    unsigned int GetMaxMp() const;
    unsigned int GetCurMp() const;

    unsigned int GetLevel() const;
    unsigned int GetMaxExp() const;
    unsigned int GetCurExp() const;

    unsigned int GetAttack() const;
    unsigned int GetDeffence() const;
    unsigned int GetSpeed() const;

private:
    int x, y;

    int curPlace;
    const char Place[2][8] = {
        "Village",
        "Field"
    };

    const char shape = 'O';

    unsigned int maxHp = 100;
    unsigned int curHp = 100;

    unsigned int maxMp = 50;
    unsigned int curMp = 50;

    unsigned int level = 1;
    unsigned int maxExp = 500;
    unsigned int curExp = 0;

    unsigned int attack = 5;
    unsigned int deffence = 5;
    unsigned int speed = 5;
};
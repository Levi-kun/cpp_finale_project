#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int maxHealth;
    int speed;
    int damage;
    int level;

public:
    Enemy(const std::string& enemyName, const int& maxHealth, const int& speed, const int& damage, const int& level);

    [[nodiscard]] std::string getName() const; // Added const for good practice
    [[nodiscard]] int getHealth() const;
    [[nodiscard]] int getMaxHealth() const;
    [[nodiscard]] int getSpeed() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] int getLevel() const;
};

#endif // ENEMY_H
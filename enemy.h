#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    /*
     * Values are private in order to make sure values don't get changed.
     */
    std::string name;
    int health;
    int maxHealth;
    int speed;
    int damage;
    int level;

public:
    // constructor
    Enemy() : name(""), health(0), maxHealth(0), speed(0), damage(0), level(0) {}

    Enemy(const std::string& enemyName, int maxHealth, int speed, int damage, int level);

    int takeDamage(int damage);                // Takes damage

    [[nodiscard]] std::string getName() const; // gives string Name of the enemy
    [[nodiscard]] int getHealth() const;       // gives int Health of the enemy
    [[nodiscard]] int getMaxHealth() const;    // gives int maxHealth of the enemy
    [[nodiscard]] int getSpeed() const;        // gives int speed of the enemy
    [[nodiscard]] int getDamage() const;       // gives int damage value of the enemy
    [[nodiscard]] int getLevel() const;        // gives int level of the enemy
};

#endif // ENEMY_H
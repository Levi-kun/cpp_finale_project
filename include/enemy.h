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

    int _focus;  // Secret Hidden Property!   Maybe will be used on ai behavior? just leaving this here for now...

public:

    Enemy() : name(""), health(0), maxHealth(0), speed(0), damage(0), level(0) {}

    Enemy(const std::string& enemyName, int maxHealth, int speed, int damage, int level);

    // Set functions -->                      functions that set the properties!!!
    int setHealth(int health);
    int setMaxHealth(int maxHealth);
    int setSpeed(int speed);
    int setDamage(int damage);
    int setLevel(int level);
    int setFocus (int focus);

    //
    int takeDamage(int damage);                // Takes damage

    [[nodiscard]] std::string getName() const; // gives string Name of the enemy
    [[nodiscard]] int getHealth() const;       // gives int Health of the enemy
    [[nodiscard]] int getMaxHealth() const;    // gives int maxHealth of the enemy
    [[nodiscard]] int getSpeed() const;        // gives int speed of the enemy
    [[nodiscard]] int getDamage() const;       // gives int damage value of the enemy
    [[nodiscard]] int getLevel() const;        // gives int level of the enemy
};

#endif // ENEMY_H
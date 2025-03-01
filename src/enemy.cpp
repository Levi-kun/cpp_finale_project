#include "../include/enemy.h"

/*
 *
 * This is how the enemy class works. Apparently I can't just have everything in one file, rather have to
 * Outline it in a header file.
 * The Enemy Class needs 5 inputs in order to work
 *
 * inputs:
 * (name, maxHealth, speed, damage, level)
 * current health or rather just health is derived from maxHealth
 *
 */

Enemy::Enemy(const std::string& enemyName, int maxHealth, int speed, int damage, int level) {
    this->name = enemyName;
    this->maxHealth = maxHealth;
    this->speed = speed;
    this->damage = damage;
    this->health = maxHealth;
    this->level = level;
}

int Enemy::takeDamage(int dmg) {
    this->health -= dmg;
    return this->health;
}

std::string Enemy::getName() const {
    return this->name;
}

int Enemy::getHealth() const {
    return this->health;
}

int Enemy::getMaxHealth() const {
    return this->maxHealth;
}

int Enemy::getSpeed() const {
    return this->speed;
}

int Enemy::getDamage() const {
    return this->damage;
}

int Enemy::getLevel() const {
    return this->level;
}
#include "enemy.h"

Enemy::Enemy(const std::string& enemyName, const int& maxHealth, const int& speed, const int& damage, const int& level) {
    this->name = enemyName;
    this->maxHealth = maxHealth;
    this->speed = speed;
    this->damage = damage;
    this->health = maxHealth; // Initialize health to maxHealth
    this->level = level;
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
#ifndef SPAWNER_H
#define SPAWNER_H

#include <string>
#include <memory>
#include "enemy.h"
#include <map>

struct EnemyAttributes {
    int minAttack;
    int maxAttack;
    int minSpeed;
    int maxSpeed;
    int minHealth;
    int maxHealth;

    EnemyAttributes(int minAtk = 0, int maxAtk = 0, int minSpd = 0, int maxSpd = 0, int minHP = 0, int maxHP = 0) :
        minAttack(minAtk), maxAttack(maxAtk),
        minSpeed(minSpd), maxSpeed(maxSpd),
        minHealth(minHP), maxHealth(maxHP) {}
};

class Spawner {
private:
    std::map<int, EnemyAttributes> difficultyMap; // creates map objects for difficulty level stats... so difficulty 1 monster have blah blah health, blah blah speed, and blah blah damage
public:
    Spawner();
    [[nodiscard]] EnemyAttributes getAttributes (int difficulty) const;
    static Enemy createTrueRandom();
    unsigned long long addDifficultyMap(const std::map<int, EnemyAttributes>& newMap);
    [[nodiscard]] std::unique_ptr<Enemy> spawnByDifficulty(int difficulty, const std::string& name, int focus = 0) const; // focus makes one value stand out more... 0 means nothing happens
};

#endif

#ifndef SPAWNER_H
#define SPAWNER_H

#include <string>
#include <cstdlib>
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
    std::map<int, EnemyAttributes> difficultyMap;
public:
    Spawner();
    EnemyAttributes getAttributes (int difficulty) const;
    static Enemy createTrueRandom(); // create true random
    std::unique_ptr<Enemy> spawnByDifficulty(int difficulty, const std::string& name) const;
};

#endif

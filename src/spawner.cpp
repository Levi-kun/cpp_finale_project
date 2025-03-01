#include "../include/spawner.h"
#include <iostream>
#include <cstdlib>
#include <memory>

// Random number generator within a range
int getRandom(int min, int max) {
    return min + (rand() % (max - min + 1));
}

Spawner::Spawner() {
    difficultyMap[1] = EnemyAttributes(4,15,5,10,20,30);
    difficultyMap[2] = EnemyAttributes(14,25,9,20,29,50);
    difficultyMap[3] = EnemyAttributes(24,50,11,20,25,100);
}

EnemyAttributes Spawner::getAttributes(int difficulty) const {
    auto it = difficultyMap.find(difficulty);
    return (it != difficultyMap.end()) ? it->second : EnemyAttributes();
}

Enemy Spawner::createTrueRandom() {
    const std::string names[4] = {"Goblin", "Skeleton", "Bandit", "Guardsman"};
    const int randomNumber = rand() % 4;
    return Enemy(names[randomNumber], 10, 20, 10, 1);
}

std::unique_ptr<Enemy> Spawner::spawnByDifficulty(int difficulty, const std::string& name) const {
    EnemyAttributes attrs = getAttributes(difficulty);

    return std::make_unique<Enemy>(
        name,
        getRandom(attrs.minHealth, attrs.maxHealth),
        getRandom(attrs.minAttack, attrs.maxAttack),
        getRandom(attrs.minSpeed, attrs.maxSpeed),
        difficulty
    );
}

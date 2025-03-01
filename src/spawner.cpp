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

unsigned long long Spawner::addDifficultyMap(const std::map<int, EnemyAttributes>& newMap) { // We can create our own difficulty Maps!
    for (const auto& [key, value] : newMap) {
        difficultyMap[key] = value;
    }
    return difficultyMap.size();
}



Enemy Spawner::createTrueRandom() {
    const std::string names[5] = {"Goblin", "Skeleton", "Bandit", "Guardsman", "The Old"};
    const int randomNumber = rand() % 5;
    return Enemy(names[randomNumber], getRandom(1,999), getRandom(1,999), getRandom(1,999), getRandom(1,5));
}

std::unique_ptr<Enemy> Spawner::spawnByDifficulty(int difficulty, const std::string& name, int focus) const {
    EnemyAttributes attrs = getAttributes(difficulty);

    std::unique_ptr<Enemy> monster = std::make_unique<Enemy>(
        name,
        getRandom(attrs.minHealth, attrs.maxHealth),
        getRandom(attrs.minAttack, attrs.maxAttack),
        getRandom(attrs.minSpeed, attrs.maxSpeed),
        difficulty
    );
    int increase;
    int decreaseOne;
    int decreaseTwo;
    switch (focus) {
        case 0:
            break;
        case 1:
            increase = (monster->getHealth() * getRandom(10, 30)) / 100;
            monster->setHealth(monster->getHealth() + increase);
            break;
        case 2:
            increase = (monster->getDamage() * getRandom(10, 30)) / 100;
            monster->setDamage(monster->getDamage() + increase);
            break;
        case 3:
            increase = (monster->getSpeed() * getRandom(10, 30)) / 100;
            monster->setSpeed(monster->getSpeed() + increase);
            break;
        case -1:
                increase = (monster->getHealth() * getRandom(10, 50)) / 100;
            decreaseOne = (monster->getDamage() * getRandom(10, 20)) / 100;
            decreaseTwo = (monster->getSpeed() * getRandom(10, 20)) / 100;
                monster->setHealth(monster->getHealth() - increase);
            monster->setDamage(monster->getDamage() - decreaseOne);
            monster->setSpeed(monster->getSpeed() + decreaseTwo);
            break;
        case -2:
                increase = (monster->getDamage() * getRandom(10, 50)) / 100;
            decreaseOne = (monster->getHealth() * getRandom(10, 20)) / 100;
            decreaseTwo = (monster->getSpeed() * getRandom(10, 20)) / 100;
            monster->setHealth(monster->getHealth() - decreaseOne);
                monster->setDamage(monster->getDamage() + increase);
            monster->setSpeed(monster->getSpeed() + decreaseTwo);
            break;
        case -3:
                increase = (monster->getSpeed() * getRandom(10, 50)) / 100;
            decreaseOne = (monster->getHealth() * getRandom(10, 20)) / 100;
            decreaseTwo = (monster->getDamage() * getRandom(10, 20)) / 100;
            monster->setHealth(monster->getHealth() - decreaseOne);
            monster->setDamage(monster->getDamage() - decreaseTwo);
                monster->setSpeed(monster->getSpeed() + increase);
            break;
        default:
            break;

    }

    return monster;
}

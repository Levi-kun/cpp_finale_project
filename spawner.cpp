#include "spawner.h"

Enemy Spawner::createTrueRandom() {
    // Currently gives a random monster but same health speed damage and level.
    // So only the name is random...
    // Plus we have no real control over the outcome of this function so that's why it's called TrueRandom
    static const std::string names[4] = {"Goblin", "Skeleton", "Bandit", "Guardsman"};
    const int randomNumber = rand() % 4;
    Enemy monster(names[randomNumber], 10, 20, 10, 1);
    return monster;
}
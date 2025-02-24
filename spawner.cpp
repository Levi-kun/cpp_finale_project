#include "spawner.h"

Enemy Spawner::createRandom() {
    static const std::string names[4] = {"Goblin", "Skeleton", "Bandit", "Guardsman"};
    const int randomNumber = rand() % 4;
    Enemy monster(names[randomNumber], 10, 20, 10, 1);
    return monster;
}
#include "../include/environment.h"
#include "../include/spawner.h"
#include <memory>
#include <cstdlib>

int getRandom(int min, int max); // Declaration

int Environment::getType() const { return this->type; }
int Environment::getMaxEvents() const { return this->maxEvents; }
int Environment::getDifficulty() const { return this->difficulty; }

Environment::Environment(int type, int maxEvents, int difficulty)
    : type(type), maxEvents(maxEvents), difficulty(difficulty) {
    // Optionally initialize randomEvents if you want predefined instances
    randomEvents[0] = std::make_unique<event>(1, difficulty); // Example event types
    randomEvents[1] = std::make_unique<event>(2, difficulty);
    randomEvents[2] = std::make_unique<event>(3, difficulty);
    randomEvents[3] = std::make_unique<event>(0, difficulty);
    fixedEvent = std::make_unique<event>(4, difficulty);
}

std::string Environment::getName() const {
    std::vector<std::string> nameArray = this->names.getEnemies(this->type);
    return nameArray[getRandom(0, nameArray.size() - 1)];
}

std::unique_ptr<Enemy[]> Environment::getMonsters(int amount) const {
    auto monsters = std::make_unique<Enemy[]>(amount);
    Spawner spawner;
    for (int i = 0; i < amount; ++i) {
        monsters[i] = *spawner.spawnByDifficulty(this->getDifficulty(), this->getName(), 0);
    }
    return monsters;
}

std::unique_ptr<event> Environment::createEvent(int eventType, int enemyCount) const {
    if (eventType == 1 || eventType == 4) { // Assuming 1 and 4 involve monsters
        auto enemies = getMonsters(enemyCount);
        return std::make_unique<event>(eventType, difficulty, 0, std::move(enemies), enemyCount);
    }
    return std::make_unique<event>(eventType, difficulty);
}
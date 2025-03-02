#include "../include/environment.h"
#include "../include/spawner.h"
#include <memory>

int getRandom(int min, int max); // just so the compiler shuts up about what getRandom is... Actual definition is in spawner.cpp

int Environment::getType() const {
  return this->type;
}

int Environment::getMaxEvents() const {
  return this->maxEvents;
}

int Environment::getDifficulty() const {
  return this->difficulty;
}

Environment::Environment(int type, int maxEvents, int difficulty) {
  this->type = type;
  this->maxEvents = maxEvents;
  this->difficulty = difficulty;
}

std::string Environment::getName() const {
  std::vector<std::string> nameArray = this->names.getEnemies(this->type);
  return nameArray[getRandom(0,nameArray.size() - 1)];

}

std::unique_ptr<Enemy[]> Environment::getMonsters(int amount) const {
  auto monsters = std::make_unique<Enemy[]>(amount);
  Spawner spawner;
  for (int i = 0; i < amount; ++i) {
    monsters[i] = *spawner.spawnByDifficulty(this->getDifficulty(), this->getName(), 0);
  }
  return monsters;
}


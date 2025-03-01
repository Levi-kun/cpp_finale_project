#include "../include/environment.h"
#include "../include/spawner.h"
#include <memory>

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

std::unique_ptr<Enemy[]> Environment::getMonsters(int amount) {
  auto monsters = std::make_unique<Enemy[]>(amount);
  for (int i = 0; i < amount; ++i) {
    monsters[i] = Spawner::spawnByDifficulty();
  }
  return monsters; // Transfers ownership to the caller
}

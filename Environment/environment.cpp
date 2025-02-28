#include "environment.h"

int environment::getType() const {
  return this->type;
}

int environment::getMaxEvents() const {
  return this->maxEvents;
}

int environment::getDifficulty() const {
  return this->difficulty;
}
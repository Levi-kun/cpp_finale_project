#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "event.h"
#include "enemy.h"
#include <memory>

class Environment {
private:
    int type;
    int maxEvents;
    int difficulty;
    std::unique_ptr<event> randomEvents[4];
    std::unique_ptr<event> fixedEvent;

public:
    Environment(int type, int maxEvents, int difficulty);
    std::unique_ptr<Enemy[]> getMonsters(int amount);
    [[nodiscard]] int getType() const;
    [[nodiscard]] int getMaxEvents() const;
    [[nodiscard]] int getDifficulty() const;
};

#endif // ENVIRONMENT_H

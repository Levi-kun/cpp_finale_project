#include "../include/event.h"
#include "../include/spawner.h"
#include <vector>
#include <memory>

int event::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
    return difficulty;
}

int event::setRewardsRarity(int rewardRarity) {
    this->rewardsRarity = rewardRarity;
    return rewardRarity;
}

std::unique_ptr<Enemy[]> event::setEnemies(int amount) {
    auto enemiesArray = std::make_unique<Enemy[]>(amount);
    for (int i = 0; i < amount; ++i) {
        enemiesArray[i] = Spawner::createTrueRandom();
    }
    return enemiesArray;
}

int* event::giveRewardsToPlayer() {
    this->rewardsRarity = getRewardsRarity();
    return nullptr;
}

int event::getType() {
    return this->type;
}

int event::getDifficulty() {
    return this->difficulty;
}

int event::getRewardsRarity() {
    return this->rewardsRarity;
}

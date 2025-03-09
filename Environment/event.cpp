#include "../include/event.h"
#include "../include/spawner.h"
#include <memory>
#include <sstream>

event::event(int type, int difficulty, int rewardsRarity, std::unique_ptr<Enemy[]> enemies, int enemyCount)
    : type(type), difficulty(difficulty), rewardsRarity(rewardsRarity), enemies(std::move(enemies)), enemyCount(enemyCount) {
}

int event::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
    return difficulty;
}

int event::setRewardsRarity(int rewardRarity) {
    this->rewardsRarity = rewardRarity;
    return rewardRarity;
}

void event::setEnemies(std::unique_ptr<Enemy[]> enemies, int amount) {
    this->enemies = std::move(enemies);
    this->enemyCount = amount;
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

std::string event::getEnemyNames() const {
    if (!enemies || enemyCount == 0) return "No enemies present.";
    std::ostringstream names;
    for (int i = 0; i < enemyCount; ++i) {
        names << enemies[i].getName();
        if (i < enemyCount - 1) names << " and ";
    }
    return names.str();
}

std::unique_ptr<int> event::giveRewardsToPlayer() {
    // Placeholder: return rarity if set, otherwise nullptr
    if (this->rewardsRarity == 0) return nullptr;
    return std::make_unique<int>(this->rewardsRarity);
}
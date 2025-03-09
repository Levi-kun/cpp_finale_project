#ifndef EVENT_H
#define EVENT_H

#include "../include/spawner.h"
#include <memory>
#include <string>

class event {
private:
    int type;
    int difficulty;
    int rewardsRarity;
    std::unique_ptr<Enemy[]> enemies; // Received from Environment
    int enemyCount;

public:
    event(int type, int difficulty = 0, int rewardsRarity = 0, std::unique_ptr<Enemy[]> enemies = nullptr, int enemyCount = 0);

    // Setters
    int setDifficulty(int difficulty);
    int setRewardsRarity(int rewardRarity);
    void setEnemies(std::unique_ptr<Enemy[]> enemies, int amount); // Grabs enemies from Environment

    // Getters
    int getType();
    int getDifficulty();
    int getRewardsRarity();
    std::string getEnemyNames() const; // New: display enemy names

    std::unique_ptr<int> giveRewardsToPlayer();
};

#endif // EVENT_H
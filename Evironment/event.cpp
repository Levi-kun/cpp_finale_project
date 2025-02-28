#include "event.h"
#include "../spawner.h"
#include <vector>

/*
 * Set Methods
 */

int event::setDifficulty(int difficulty) {
    this->difficulty=difficulty;
    return difficulty;
}
int event::setRewardsRarity(int rewardRarity) {
    this->rewardsRarity=rewardRarity;
    return rewardRarity;
}

#include "Enemy.h"
#include "Spawner.h"

Enemy* event::setEnemies(int amount) {

    Enemy* enemiesArray = new Enemy[amount];

    for (int i = 0; i < amount; ++i) {

        enemiesArray[i] = Spawner::createTrueRandom();
    }

    return enemiesArray;
}
/*
 * Give methods
 */
int *event::giveRewardsToPlayer() {
    this->rewardsRarity=getRewardsRarity();

}

/*
 * Get Methods
 */

int event::getType() {
    return this->type;
}

int event::getDifficulty() {
    return this->difficulty;
}

int event::getRewardsRarity() {
    return this->rewardsRarity;
}




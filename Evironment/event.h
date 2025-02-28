#ifndef EVENT_H
#define EVENT_H
#include "../spawner.h"
#include <vector>


class event {
private:
    int type;
    int difficulty;
    int rewardsRarity;
public:
   event(int type, int difficulty=0, int rewardsRarity=0);

    int setDifficulty(int difficulty);
    int setRewardsRarity(int rewardRarity);
    Enemy * setEnemies(int amount=1);

    int getType();
    int getDifficulty();
    int getRewardsRarity();

    int * giveRewardsToPlayer();

};



#endif //EVENT_H

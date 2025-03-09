#include <iostream>
#include "../include/EnviornmentFactory.h"
using namespace std;

int main() {
    srand(time(nullptr));
    EnvironmentFactory factory;
    auto env = factory.createEnvironment("Forest"); // Type 1, difficulty 1

    // Create an event with 2 monsters
    auto evt = env->createEvent(1, 2); // Type 1 = monster event
    cout << "Event type: " << evt->getType() << endl;
    cout << "Enemies: " << evt->getEnemyNames() << endl;

    // Set a reward rarity (example)
    evt->setRewardsRarity(2);
    std:unique_ptr<int> reward = evt->giveRewardsToPlayer();
    if (reward) {
        cout << "Reward rarity: " << *reward << endl;
    } else {
        cout << "No reward." << endl;
    }

    return 0;
}
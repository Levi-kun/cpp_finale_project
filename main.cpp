#include <iostream>
#include <ctime>
#include "spawner.h"
#include "enemy.h"
using namespace std;

/*
 *
 * My main file so far, not actually anything done here just a some text that says a monster has spawned
 *
 */

int main() {

    srand(time(nullptr));

    Enemy monster = Spawner::createTrueRandom(); // Use Spawner to create a random enemy
    int action;
    cout << "A level " << monster.getLevel() << " " << monster.getName() << " has spawned with the health of " << monster.getHealth() <<"."  << endl;
    cout << "1) Attack";
    cin >> action;

    if (action == 1) {
       cout << monster.takeDamage(5) << " damage" << endl;
    }


    return 0;
}
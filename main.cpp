#include <iostream>
#include "spawner.h"

using namespace std;

/*
 *
 * My main file so far, not actually anything done here just a some text that says a monster has spawned
 *
 */

int main() {

    srand(time(nullptr));

    Enemy monster = Spawner::createTrueRandom(); // Use Spawner to create a random enemy

    cout << "A level " << monster.getLevel() << " " << monster.getName() << " has spawned." << endl;

    return 0;
}
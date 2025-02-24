#include <iostream>
#include "spawner.h"

using namespace std;

int main() {

    srand(time(nullptr));

    Enemy monster = Spawner::createRandom(); // Use Spawner to create a random enemy

    cout << "A level " << monster.getLevel() << " " << monster.getName() << " has spawned." << endl;

    return 0;
}
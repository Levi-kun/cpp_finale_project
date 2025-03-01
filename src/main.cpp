#include <iostream>
#include <ctime>
#include "../include/spawner.h"
#include "../include/enemy.h"
#include "../include/environment.h"
using namespace std;

/*
 *
 * My main file so far, not actually anything done here just a some text that says a monster has spawned
 *
 */

int main() {
    srand(time(nullptr));

    Enemy monster = Spawner::createTrueRandom();
    cout << "A level " << monster.getLevel() << " " << monster.getName() << " has spawned with the health of " << monster.getHealth() << "." << endl;

    int action;
    cout << "1) Attack: ";
    cin >> action;

    if (action == 1) {
        cout << monster.takeDamage(5) << " damage" << endl;
    }

    const Spawner spawner;
    auto specialMonster = spawner.spawnByDifficulty(2, "Orc");
    cout << "A special monster: " << specialMonster->getName() << " with " << specialMonster->getHealth() << " HP." << endl;

    const Environment Plains(1, 3, 1);
    cout << "Max Events: " << Plains.getMaxEvents() << endl;

    return 0;
}

#include <iostream>
#include <ctime>
#include <vector>
#include "../include/spawner.h"
#include "../include/enemy.h"
#include "../include/environment.h"
using namespace std;

/*
 *
 * My main file so far, not actually anything done here just a some text that says a monster has spawned
 *
 */

void printMemoryUsage() {
    std::cout << "Memory used (approx.): " << (sizeof(Enemy) * 10 + sizeof(Environment)) << " bytes\n";
}

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
    auto specialMonster = spawner.spawnByDifficulty(1, "Nino");
    cout << "A special monster: " << specialMonster->getName() << " with " << specialMonster->getHealth() << " HP." << endl;

    const Environment Plains(1, 3, 1);
    cout << "Max Events: " << Plains.getMaxEvents() << endl;
    printMemoryUsage();
    cout << "1) Attack: ";
    cin >> action;

    if (action == 1) {
        cout << specialMonster->takeDamage(5) << " damage" << endl;
    }
    cin >> action;
    return 0;
}

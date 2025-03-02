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

    Environment plains(1,1,1);

    Enemy monster = plains.getMonsters(1)[0];
    cout << monster.getName() << " | " << monster.getHealth() << " HP | " << monster.getDamage() << endl; // gives name of a monster created by the plain's environment.
    while (monster.getHealth() > 0) {
        int action = 0;
        cout << monster.getName() << " | " << monster.getHealth();
        cout << "\n1. to Deal Damage";
        cin >> action;
        switch (action) {
            case 1:
                monster.takeDamage(5);
                break;
            default:
                break;
        }
    }
    return 0;
}

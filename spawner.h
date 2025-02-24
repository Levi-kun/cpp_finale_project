#ifndef SPAWNER_H
#define SPAWNER_H

#include <string>
#include <cstdlib>
#include "enemy.h"

class Spawner {
public:
    static Enemy createTrueRandom();
};

#endif
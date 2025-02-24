#ifndef SPAWNER_H
#define SPAWNER_H

#include <string>  // For std::string
#include <cstdlib> // For rand()
#include "enemy.h" // Include Enemy definition

class Spawner {
public:
    static Enemy createRandom(); // Declaration only
};

#endif // SPAWNER_H
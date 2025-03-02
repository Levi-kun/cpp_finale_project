#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "event.h"
#include "enemy.h"
#include <memory>
#include <string>

struct EnemyNames {
    std::map<int, std::vector<std::string>> biomeEnemies;


    EnemyNames() {
        biomeEnemies[1] = {"Forest Spider", "Entling", "Shadow Wolf", "Wood Serpant", "Wild Boar"};
        biomeEnemies[2] = {"Rock Golem", "Cave Troll", "Stone Serpent", "Snow Beast", "Mountain Wraith"};
        biomeEnemies[3] = {"Bog Lurker", "Swamp Serpent", "Rot Fiend", "Mire Hag", "Plague Rat"};
    }


    void addBiome(int biomeType, const std::vector<std::string>& enemies) {
        biomeEnemies[biomeType] = enemies;
    }

    [[nodiscard]] const std::vector<std::string>& getEnemies(int biomeType) const {
        static const std::vector<std::string> emptyList;
        auto it = biomeEnemies.find(biomeType);
        return (it != biomeEnemies.end()) ? it->second : emptyList;
    }
};


class Environment {
private:
    int type;       // from 0 -> 4
    int maxEvents;
    int difficulty;
    EnemyNames names;
    std::unique_ptr<event> randomEvents[4];
    std::unique_ptr<event> fixedEvent;

public:
    Environment(int type, int maxEvents, int difficulty);
    [[nodiscard]] std::unique_ptr<Enemy[]> getMonsters(int amount) const;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getType() const;
    [[nodiscard]] int getMaxEvents() const;
    [[nodiscard]] int getDifficulty() const;
};

#endif // ENVIRONMENT_H

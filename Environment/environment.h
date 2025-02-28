#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "event.h" //for some reason this does not work


/*
int type = [swamp, ice, mountain]
 */

class environment {
  private:
    int type;
    int maxEvents;
    int difficulty;
    event* randomEvents[4];
    event* fixedEvent;

  public:
    environment(int type, int maxEvents, int difficulty);

    int* addEvent(int* event, int type=0);


    static int* getMonsters();


    [[nodiscard]] int getType() const;
    [[nodiscard]] int getMaxEvents() const;
    [[nodiscard]] int getDifficulty() const;


};



#endif //ENVIRONMENT_H

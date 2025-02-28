//
// Created by Levi Selvage on 2/27/25.
//

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

/*
int type = [swamp, ice, mountain]
 */

class environment {
  private:
    int type;
    int maxEvents;
    int difficulty;
  public:
    environment(int type, int maxEvents, int difficulty);

    static environment createEvironment(int type, int maxEvents, int difficulty);

    static int getMonsters();
    int getType();
    int getMaxEvents();
    int getDifficulty();


};



#endif //ENVIRONMENT_H

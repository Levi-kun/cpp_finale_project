//
// Created by Levi Selvage on 2/27/25.
//

#include "environment.h"

environment Environment::createEvironment(int type, int maxEvents, int difficulty ) {
    return environment(type, maxEvents, difficulty);
}
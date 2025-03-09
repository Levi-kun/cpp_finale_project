#ifndef ENVIRONMENTFACTORY_H
#define ENVIRONMENTFACTORY_H

#include "environment.h"
#include <string>
#include <map>

class EnvironmentFactory {
public:
    EnvironmentFactory(); // Constructor to initialize environment templates
    std::unique_ptr<Environment> createEnvironment(const std::string& typeName) const;

private:
    struct EnvironmentTemplate {
        int type;
        int maxEvents;
        int difficulty;
    };
    std::map<std::string, EnvironmentTemplate> environmentTemplates;
};

#endif
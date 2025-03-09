#include "../include/EnviornmentFactory.h"
#include <stdexcept>

EnvironmentFactory::EnvironmentFactory() {
    // Define some default environment templates
    environmentTemplates["Forest"] = {1, 3, 1};  // type, maxEvents, difficulty
    environmentTemplates["Mountain"] = {2, 5, 2};
    environmentTemplates["Swamp"] = {3, 2, 3};
}

std::unique_ptr<Environment> EnvironmentFactory::createEnvironment(const std::string& typeName) const {
    auto it = environmentTemplates.find(typeName);
    if (it == environmentTemplates.end()) {
        throw std::invalid_argument("Unknown environment type: " + typeName);
    }
    
    const EnvironmentTemplate& tmpl = it->second;
    return std::make_unique<Environment>(tmpl.type, tmpl.maxEvents, tmpl.difficulty);
}
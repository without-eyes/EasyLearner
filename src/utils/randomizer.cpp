#include "../../include/utils/randomizer.h"

Randomizer* Randomizer::instance;

Randomizer::Randomizer() : generator(std::random_device{}()) {

}

Randomizer * Randomizer::getInstance() {
    if (instance == nullptr) {
        instance = new Randomizer();
    }
    return instance;
}

unsigned int Randomizer::getInt(const int max) {
    return std::uniform_int_distribution<>(0, max)(generator);
}

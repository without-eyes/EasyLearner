/**
    * @file: randomizer.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of Randomizer class.
*/

#include "utils/randomizer.h"

Randomizer::Randomizer() : generator(std::random_device{}()) {

}

Randomizer* Randomizer::getInstance() {
    static Randomizer randomizer;
    return &randomizer;
}

unsigned int Randomizer::getInt(const int max) {
    if (max <= 0) return 0;
    return std::uniform_int_distribution<>(0, max)(generator);
}

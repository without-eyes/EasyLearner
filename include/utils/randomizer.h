/**
    * @file: randomizer.h
    * @author: without eyes
    *
    * This file contains Randomizer singleton class that returns
    * random number from 0 to given max number.
*/

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

class Randomizer {
public:
    static Randomizer* getInstance();

    unsigned int getInt(int max);

private:
    Randomizer();

    std::mt19937 generator;
};

#endif //RANDOMIZER_H

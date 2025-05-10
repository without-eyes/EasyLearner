#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <random>


class Randomizer {
public:
    Randomizer& operator=(Randomizer&) = delete;
    Randomizer(const Randomizer&) = delete;

    static Randomizer* getInstance();

    unsigned int getInt(int max);

private:
    static Randomizer* instance;
    std::mt19937 generator;

    Randomizer();
};

#endif //RANDOMIZER_H

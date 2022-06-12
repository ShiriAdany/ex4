//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle
{
public:
    Vampire();

    void applyEncounter(Player &player) const override;

    void printInfo() const override;

    Vampire(const Vampire& other) = default;
    ~Vampire() override = default;
    Vampire& operator=(const Vampire& other) = default;

private:
    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_FORCE =  10;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;
};
#endif //EX4_VAMPIRE_H

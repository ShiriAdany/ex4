//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

class Goblin : public Battle
{
public:
    Goblin();

    void applyEncounter(Player &player) const override;

    Goblin(const Goblin& other) = default;
    ~Goblin() override = default;
    Goblin& operator=(const Goblin& other) = default;

private:
    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_FORCE = 6;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;
};
#endif //EX4_GOBLIN_H

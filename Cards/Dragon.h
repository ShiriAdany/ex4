//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

class Dragon : public Battle
{
public:
    Dragon();

    void applyEncounter(Player &player) override;

    void printInfo() const override;

    Dragon(const Dragon& other) = default;
    ~Dragon() override = default;
    Dragon& operator=(const Dragon& other) = default;

private:

    void printInfo(std::ostream &os) const override;

    static const int DEFAULT_FORCE = 25;
    static const int DEFAULT_LOOT = 1000;
    static const int DEFAULT_DAMAGE = 0;
};
#endif //EX4_DRAGON_H

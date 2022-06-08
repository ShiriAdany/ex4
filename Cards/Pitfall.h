//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:

    Pitfall();

    void applyEncounter(Player& player) override;

    Pitfall(const Pitfall& other) = default;
    ~Pitfall() = default;
    Pitfall& operator=(const Pitfall& other) = default;

private:
    int m_damage;

    static const int DEFAULT_DAMAGE = 10;

};
#endif //EX4_PITFALL_H

//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:

    Pitfall();

    void applyEncounter(Player& player) const override;

    std::string getType() const override;

    Pitfall(const Pitfall& other) = default;
    ~Pitfall() override = default;
    Pitfall& operator=(const Pitfall& other) = default;

private:
    int m_damage;
    void printInfo(std::ostream &os) const override;
    static const int DEFAULT_DAMAGE = 10;

};
#endif //EX4_PITFALL_H

//
// Created by shiri on 19/06/2022.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "Vampire.h"
#include "Dragon.h"
#include "Goblin.h"
#include "../Exception.h"
#include <vector>
#include <memory>
#include <fstream>

class Gang : public Card
{
public:
    Gang(std::ifstream& source, int *lineNumber);

    void applyEncounter(Player& player) const override;

    std::string getType() const override;

    Gang(const Gang& other) = default;
    ~Gang() override = default;
    Gang& operator=(const Gang& other) = default;

private:
    std::vector<std::unique_ptr<Card>> m_gang;
    void printInfo(std::ostream &os) const override;

};
#endif //EX4_GANG_H

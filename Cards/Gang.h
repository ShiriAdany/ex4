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
    //C'tor of Gang class
    Gang(std::ifstream& source, int *lineNumber);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    //Returns the type of the card
    std::string getType() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Gang() override = default;
    Gang(const Gang& other);
    Gang& operator=(const Gang& other);


private:
    std::vector<std::unique_ptr<Card>> m_gang;
    void printInfo(std::ostream &os) const override;
    const std::string TYPE = "Gang";

};
#endif //EX4_GANG_H

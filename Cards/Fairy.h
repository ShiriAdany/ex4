//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card
{
public:
    //C'tor of Fairy class
    Fairy();

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
    Fairy(const Fairy& other) = default;
    ~Fairy() override = default;
    Fairy& operator=(const Fairy& other) = default;


private:
    int m_heal;
    void printInfo(std::ostream &os) const override;
    static const int DEFAULT_HEAL = 10;
    const std::string TYPE = "Fairy";


};
#endif //EX4_FAIRY_H

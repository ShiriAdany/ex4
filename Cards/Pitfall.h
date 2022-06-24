//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:
    //C'tor of Pitfall class
    Pitfall();

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
    Pitfall(const Pitfall& other) = default;
    ~Pitfall() override = default;
    Pitfall& operator=(const Pitfall& other) = default;

private:
    int m_damage;
    void printInfo(std::ostream &os) const override;
    static const int DEFAULT_DAMAGE = 10;
    const std::string TYPE = "Pitfall";


};
#endif //EX4_PITFALL_H

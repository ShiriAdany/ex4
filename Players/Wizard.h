//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"
#include "../utilities.h"


class Wizard : public Player
{
public:
    //C'tor of Wizard class
    Wizard(std::string name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Wizard() override = default;
    Wizard(const Wizard& other) = default;
    Wizard& operator=(const Wizard& other) = default;

    /*
     * Raises the HP of the player according to the given argument, until the maxHP:
     * @param hp - the quantity of HP to raise.
     *
    */
    void heal(int hp) override;

    //Returns the job of the player
    std::string getJob() const override;


private:
    void printInfo(std::ostream &os) const override;
    const std::string JOB = "Wizard";

};


#endif //EX4_WIZARD_H

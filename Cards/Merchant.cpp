//
// Created by shiri on 06/06/2022.
//

#include "Merchant.h"
using std::stoi;
using std::cin;


Merchant::Merchant() : Card(CardType::Merchant) {
}

void Merchant::applyEncounter(Player &player) const{
    Merchant::makeTrade(player);
}


int Merchant::getPlayerChoice(Player &player) {
    std::string input;
    int choice;
    bool endTurn = false;

    do{

        std::getline(cin, input);
        if(input.find_first_not_of("0123456789") == std::string::npos)
        {
            try{
                choice = std::stoi(input);
            }
            catch(...) //cant convert to int- out of range
            {
                choice = Action::Number_Of_Options;
            }
            if(choice >= Action::Number_Of_Options || choice < 0)
            {
                printInvalidInput();
            }
            else{
                endTurn = true;
            }
        }
        else
        {
            printInvalidInput();
        }

    }while(!endTurn);

    return choice;

}


void Merchant::makeTrade(Player &player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,
                                                       player.getName(),
                                                       player.getCoins());
    int choice = Merchant::getPlayerChoice(player);
    int cost =0 ;

    switch(choice){
        case Action::Nothing:
        {
            break;
        }

        case Action::Health_Potion:
        {
            if(player.pay(HEALTH_POTION_COST))
            {
                cost = HEALTH_POTION_COST;
                player.heal(1);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        }

        case Action::Force_Boost:
        {
            if(player.pay(FORCE_BOOST_COST))
            {
                cost = FORCE_BOOST_COST;
                player.buff(1);
            }
            else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        }

        default:
            break;
    }
    printMerchantSummary(std::cout,player.getName(),choice,cost);
}

void Merchant::printInfo(std::ostream &os) const {
    printCardDetails(os,TYPE);
    printEndOfCardDetails(os);
}

std::string Merchant::getType() const {
    return TYPE;
}




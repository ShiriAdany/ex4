//
// Created by shiri on 06/06/2022.
//

#include "Merchant.h"
using std::stoi;

int Merchant::getPlayerChoice(Player &player) {
    string input;
    int choice;

    bool endTurn = false;
    do{
        cin.getline(input, 1);
        choice = stoi(input);
        if(choice >= action::Options || choice < 0)
        {
            printInvalidInput();
        }
        else{
            endTurn = true;
        }
    }while(!endTurn);

    return choice;

}


void Merchant::makeTrade(Player &player) {
    std::ostream stream;
    printMerchantInitialMessageForInteractiveEncounter(stream,Player &player,player.m_coins);
    int choice = getPlayerChoice(player);
    int cost =0 ;

    switch(choice){
        case action::Nothing:
        {
            break;
        }

        case action::Health_Potion:
        {
            if(player.pay(HEALTH_POTION_COST))
            {
                cost = HEALTH_POTION_COST;
                player.heal(1);
            }
            else{
                printMerchantInsufficientCoins(stream);
            }
            break;
        }

        case action::Force_Boost:
        {
            if(player.pay(FORCE_BOOST_COST))
            {
                cost = FORCE_BOOST_COST;
                player.buff(1);
            }
            else{
                printMerchantInsufficientCoins(stream);
            }
            break;
        }
        default:
            break;
    }
    printMerchantSummary(stream,player.m_name,choice,cost);
}


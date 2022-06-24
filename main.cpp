#include <iostream>
#include <string>
#include <fstream>

#include "Mtmchkin.h"
#include "Cards/Gang.h"



int main() {
    try{
        Mtmchkin game("deck.txt");
        while(!game.isGameOver()){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


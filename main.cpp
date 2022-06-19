#include <iostream>
#include <string>

#include "Mtmchkin.h"


int main(int argc, char** argv) {
    try{
        Mtmchkin game(argv[1]);
        while(!game.isGameOver() && game.getNumberOfRounds() < 100){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(...)
    {
        return 0;
    }

    return 0;
}

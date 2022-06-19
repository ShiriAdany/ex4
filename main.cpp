#include <iostream>
#include "Mtmchkin.h"

int main()
{
    Mtmchkin game ("deck.txt");

    while(!game.isGameOver()){
        game.playRound();
    }

    game.printLeaderBoard();

    return 0;
}

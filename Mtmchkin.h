#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string.h>
#include "Exception.h"

#include "Card.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Dragon.h"
#include "Merchant.h"
#include "Pitfall.h"
#include "Barfight.h"
#include "Fairy.h"
#include "Treasure.h"

#include "Rogue.h"
#include "Fighter.h"
#include "Wizard.h"

#include <fstream>
#include <queue>
#include <vector>

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::queue<Card*> m_deck;
    std::queue<Player*>  m_playersQueue;
    int m_numberOfPlayers;

    void initiateDeck(const std::string fileName);
    void initiatePlayers();
    static int getNumberOfPlayers();
    static std::vector<std::string> getPlayerArguments();
    static void printInvalidNumberOfArgumens();
    bool isValidArguments(std::vector<std::string>);
    static bool validName(const std::string& name);

    static int const NUMBER_OF_ARGUMENTS = 2; //player's name and class
};



#endif /* MTMCHKIN_H_ */

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
#include <deque>
#include <vector>
#include <memory>
#include <map>

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string fileName);
    
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

    Mtmchkin(const Mtmchkin&) = delete;
    ~Mtmchkin() = default;
    Mtmchkin& operator=(const Mtmchkin& other) = default;

private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>>  m_playersQueue;
    int m_numberOfPlayers;
    int m_roundCounter;

    void initiateDeck(std::string fileName);
    void initiatePlayers();
    static int getNumberOfPlayers();
    static std::vector<std::string> getPlayerArguments();
    static void printInvalidNumberOfArgumens();
    bool isValidArguments(std::vector<std::string>);
    static bool validName(const std::string& name);
    void playCard(std::unique_ptr<Card> card, std::unique_ptr<Player> player);
    template<class T>
    Card* createInstance();
    Card* mapToConstructor(std::string line);


    static const int  NUMBER_OF_ARGUMENTS = 2; //player's name and class
    static const int MAX_PLAYERS = 6;
    static const int MIN_PLAYERS = 2;

};



#endif /* MTMCHKIN_H_ */

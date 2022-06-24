#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string.h>
#include "Exception.h"
#include "utilities.h"

#include "Cards/Card.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Treasure.h"
#include "Cards/Gang.h"

#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"

#include <fstream>
#include <deque>
#include <vector>
#include <list>
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
    explicit Mtmchkin(const std::string &fileName);
    
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
    Mtmchkin& operator=(const Mtmchkin& other) = delete;

private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_activePlayers;
    int m_numberOfPlayers;
    int m_roundCounter;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;

    //Initiate the deck queue according to the given file
    void initiateDeck(std::string fileName);

    //Initiate the queue of players according to the input from the user- Gets name and job.
    void initiatePlayers();

    //Gets from the user the number of players that are going to play.
    static int getNumberOfPlayers();

    //Gets from the user the name and the job.
    static std::vector<std::string> getPlayerArguments();

    //print to the user an error about invalid players amount inserted.
    static void printInvalidNumberOfArgumens();

    //Checks if the given arguments of the new player are valid.
    bool isValidArguments(std::vector<std::string>);

    //Checks if the name of the player is valid.
    static bool validName(const std::string& name);

    //Apply the card on the given player.
    static void playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player);

    //Add new card to the deck of cards.
    void addCard(std::string cardName, int* lineNumber, std::ifstream& source);


    static const int NUMBER_OF_ARGUMENTS = 2; //player's name and class
    static const int MAX_PLAYERS = 6;
    static const int MIN_PLAYERS = 2;
    static const int MAX_NAME_LEN = 15;
    static const int MIN_CARDS_NUMBER = 5;

};



#endif /* MTMCHKIN_H_ */

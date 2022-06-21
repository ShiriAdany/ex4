//
// Created by shiri on 06/06/2022.
//

#include "Mtmchkin.h"
using std::ifstream;
using std::string;
using std::cin;

Mtmchkin::Mtmchkin(const string &fileName): m_roundCounter(0) {
    printStartGameMessage();
    initiateDeck(fileName);
    m_numberOfPlayers = getNumberOfPlayers();
    initiatePlayers();

}

void Mtmchkin::initiateDeck(const string fileName) {

    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }

    char line[256];
    int lineNumber = 1;
    int numberOfCards = 0;
    while(source.getline(line, sizeof(line)))
    {
        string cardName = line;
        try {

            addCard(cardName,lineNumber,source);
            numberOfCards++;
            lineNumber++;
        }
        catch(...)
        {
            throw;
        }
    }

    if(numberOfCards < MIN_CARDS_NUMBER)
    {
        throw DeckFileInvalidSize();
    }
}

void Mtmchkin::addCard(std::string cardName, int lineNumber, std::ifstream& source)
{
    if(cardName == "Goblin")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Goblin()));
    }
    else if(cardName == "Vampire")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Vampire()));
    }
    else if(cardName == "Dragon")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Dragon()));
    }
    else if(cardName == "Merchant")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Merchant()));
    }
    else if(cardName == "Treasure")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Treasure()));
    }
    else if(cardName == "Pitfall")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Pitfall()));
    }
    else if(cardName == "Barfight")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Barfight()));
    }
    else if(cardName == "Fairy")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Fairy()));
    }
    else if(cardName == "Gang")
    {
        m_deck.push_back(std::unique_ptr<Card>(new Gang(source, &lineNumber)));
    }
    else
    {
        throw DeckFileFormatError(lineNumber);
    }
}

void Mtmchkin::initiatePlayers() {

    std::vector<string> words;
    bool done = false;
    for(int i =0; i<m_numberOfPlayers; i++) {
        printInsertPlayerMessage();
        while(!done)
        {
            words.clear();
            words = getPlayerArguments();
            done = isValidArguments(words);
        }
        done = false;
    }

}

bool Mtmchkin::isValidArguments(std::vector<string> words)
{
    string playerName = words[0];
    string playerClass = words[1];
    std::unique_ptr<Player> newPlayer;

    if (validName(playerName)) {
        try{
            if (playerClass == "Rogue") {
                m_activePlayers.push_back(std::unique_ptr<Player>(new Rogue(playerName)));
            } else if (playerClass == "Fighter") {
                m_activePlayers.push_back(std::unique_ptr<Player>(new Fighter(playerName)));
            } else if (playerClass == "Wizard") {
                m_activePlayers.push_back(std::unique_ptr<Player>(new Wizard(playerName)));
            } else {
                printInvalidClass();
                return false;
            }
        }
        catch(const InvalidName& e)
        {
            printInvalidName();
            return false;
        }
    }
    else {
        printInvalidName();
        return false;
    }
    return true;
}

int Mtmchkin::getNumberOfPlayers() {
    string input;
    int numberOfPlayers;
    bool valid = false;
    do{
        printEnterTeamSizeMessage();
        std::getline(cin, input);
        if(input.find_first_not_of("0123456789") == std::string::npos) {
            numberOfPlayers = stoi(input);
            if (numberOfPlayers <= MAX_PLAYERS && numberOfPlayers >= MIN_PLAYERS) {
                valid = true;
            }
            else
            {
                printInvalidInput();
            }
        }
        else{
            printInvalidInput();
        }

    }while(!valid);

    return numberOfPlayers;
}

std::vector<std::string> Mtmchkin::getPlayerArguments() {

    string input;
    string argument;
    std::vector<string> words;
    bool valid = false;

    do{
        std::getline(cin,input);
        std::istringstream seperateString(input);
        while(seperateString >> argument)
        {
            words.push_back(argument);
        }

        if(words.size() == NUMBER_OF_ARGUMENTS)
        {
            valid = true;
        }
        else{
            printInvalidNumberOfArgumens();
            words.clear();
        }
    }while(!valid);

    return words;
}

void Mtmchkin::printInvalidNumberOfArgumens() {
    std::cout << "Please enter " << std::to_string(NUMBER_OF_ARGUMENTS) << " arguments" << std::endl;
}

bool Mtmchkin::validName(const std::string& name) {
    if(name.size() > MAX_NAME_LEN)
    {
        return false;
    }

    for(char i : name){
        if( !isalpha(i) || isspace(i)){
            return false;
        }
    }
    return true;
}

void Mtmchkin::playRound() {
    m_roundCounter++;
    printRoundStartMessage(m_roundCounter);
    std::unique_ptr<Card> currentCard;
    int index = 0;

    for(std::unique_ptr<Player> &p : m_activePlayers)
    {
        printTurnStartMessage(p->getName());
        currentCard = std::move(m_deck.front());

        m_deck.pop_front();
        playCard(currentCard, p);
        m_deck.push_back(std::move(currentCard));

        if(p->isWinning())
        {
            m_winners.push_back(std::move(p));
            m_activePlayers.erase(m_activePlayers.begin() + index);
            index--;
        }
        else if(p-> isKnockedOut())
        {
            m_losers.push_front(std::move(p));
            m_activePlayers.erase(m_activePlayers.begin() + index);
            index--;
        }

        if(isGameOver()){
            printGameEndMessage();
        }
        index++;
    }


}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCounter;
}

void Mtmchkin::playCard(std::unique_ptr<Card> &card, std::unique_ptr<Player> &player)
{
    card->applyEncounter(*player);
}

bool Mtmchkin::isGameOver() const {
    if(!m_activePlayers.empty()){
        return false;
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;

    for(unsigned int i=0; i<m_winners.size(); i++)
    {
        printPlayerLeaderBoard(ranking,*m_winners.at(i));
        ranking++;
    }
    for(unsigned int i=0; i<m_activePlayers.size(); i++)
    {
        printPlayerLeaderBoard(ranking,*m_activePlayers.at(i));
        ranking++;
    }
    for(unsigned int i=0; i<m_losers.size(); i++)
    {
        printPlayerLeaderBoard(ranking,*m_losers.at(i));
        ranking++;
    }
}









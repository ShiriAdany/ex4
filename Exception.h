//
// Created by shiri on 06/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <exception>
#include <string>

class DeckExeptions: public std::exception
{
public:
    const char* what() const override{
        return exception::what();
    };
};

class PlayerExeptions : public std::exception
{
public:
    const char* what() const override{
        return exception::what();
    };
};

class InvalidName : public PlayerExeptions
{
public:
    const char * what() const override
    {
        return "Player error: Invalid Name";
    }
};


class DeckFileNotFound : public DeckExeptions{
public:
    const char* what() const override
    {
        return "Deck File Error: File not found";
    };
};


class DeckFileInvalidSize: public DeckExeptions{
public:
    const char* what() const override
    {
        return "Deck File Error: Deck size is invalid";
    };
};



class DeckFileFormatError: public DeckExeptions{
public:
    DeckFileFormatError(int line): m_line(line){};

    const char* what() const override{
        std::string message = "Deck File Error: File format error in line " + std::to_string(m_line);
        int len = message.length();
        char *char_array = new char [len+1];
        strcpy(char_array, message.c_str());
        return char_array;
    }

private:
    int m_line;

};



#endif //EX4_EXCEPTION_H

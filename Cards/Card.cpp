
#include "Card.h"

Card::Card(CardType type)
{
    m_type = type;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    card.printInfo(os);
    return os;
}


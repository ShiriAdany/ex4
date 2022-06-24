
#include "Card.h"

Card::Card(CardType type)
{
    m_type = type;
}

std::ostream &operator<<(std::ostream &os, Card &card) {
    card.printInfo(os);
    return os;
}

int Card::getForce() const {
    return 0;
}

int Card::getLoot() const {
    return 0;
}

int Card::getDamage() const {
    return 0;
}




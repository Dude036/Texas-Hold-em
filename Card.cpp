#include <string>
#include <iostream>

#include "Card.hpp"

/**
 *
 */
Card::Card(Suit _suit, Rank _rank) {
    rank = _rank;
    suit = _suit;
    value = (int)_rank;
}

Card::~Card() {}

/**
 *
 */
void Card::printCard() {
    std::cout << stringifyCard();
}

int Card::getHighValue() {
    if (rank == ACE) {
        return 11;
    } else {
        return value;
    }
}


std::string Card::stringifyCard() {
    std::string retval = "";
    switch (suit) {
        case CLUB:
            retval += "C";
            break;
        case DIAMOND:
            retval += "D";
            break;
        case SPADE:
            retval += "S";
            break;
        case HEART:
            retval += "H";
            break;
    }

    switch (rank) {
        case ACE:   retval+="A"; break;
        case TWO:   retval+="2"; break;
        case THREE: retval+="3"; break;
        case FOUR:  retval+="4"; break;
        case FIVE:  retval+="5"; break;
        case SIX:   retval+="6"; break;
        case SEVEN: retval+="7"; break;
        case EIGHT: retval+="8"; break;
        case NINE:  retval+="9"; break;
        case TEN:   retval+="10";break;
        case JACK:  retval+="J"; break;
        case QUEEN: retval+="Q"; break;
        case KING:  retval+="K"; break;

    }
    return retval;
}

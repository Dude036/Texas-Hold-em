#include <string>
#include <iostream>

#include "Card.hpp"

Card::Card() {}

/**
 *
 */
Card::Card(Suit _suit, Rank _rank) {
    rank = _rank;
    suit = _suit;
    switch (_rank) {
        case ACE:
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
        case SIX:
        case SEVEN:
        case EIGHT:
        case NINE:
        case TEN:
            value = (int)_rank;
            break;
        case JACK:
        case QUEEN:
        case KING:
            value = 10;
            break;
    }
}

Card::~Card() {}

/**
 *
 */
void Card::printCard(bool override = false) {
    if (override) return;

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

    std::cout<<retval;
}

int Card::getHighValue() {
    if (rank == ACE) {
        return 11;
    } else {
        return value;
    }
}

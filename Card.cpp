#include <string>
#include <iostream>

#include "Card.hpp"
#include "Globals.hpp"

/**
 *
 */
Card::Card(Suit _suit, Rank _rank) {
    rank = _rank;
    suit = _suit;
}

Card::~Card() {}

/**
 *
 */
void Card::printCard() {
    std::string s = stringifyCard(), c;
    if (s[0] == 'S') {
        c = green;
    } else if (s[0] == 'H') {
        c = red;
    } else if (s[0] == 'C') {
        c = yellow;
    } else if (s[0] == 'D') {
        c = cyan;
    } else {
        c = white;
    }

    std::cout << c << s << reset;
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

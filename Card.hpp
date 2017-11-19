#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#include "Globals.hpp"

class Card {
  public:
    Card(Suit, Rank);
    ~Card();
    void printCard();
    Suit getSuit() { return suit; };
    Rank getRank() { return rank; };
    int getValue() { return value; };
    std::string stringifyCard();
  private:
    Suit suit;
    Rank rank;
    int value;
};

#endif // CARD_HPP

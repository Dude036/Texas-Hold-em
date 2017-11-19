#ifndef CARD_HPP
#define CARD_HPP

#include "Globals.hpp"

class Card {
  public:
    Card(Suit, Rank);
    ~Card();
    void printCard(bool);
    Suit getSuit() { return suit; };
    Rank getRank() { return rank; };
    int getHighValue();
    int getLowValue() { return value; };
  private:
    Suit suit;
    Rank rank;
    int value;
};

#endif // CARD_HPP

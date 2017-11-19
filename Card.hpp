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
    std::string stringifyCard();

    // Comparison Operators for sorting
    friend bool operator<(const Card& l, const Card& r) {
        return ((int)l.rank < (int)r.rank);
    }

    friend bool operator>(const Card& l, const Card& r) {
        return ((int)r.rank < (int)l.rank);
    }
  private:
    Suit suit;
    Rank rank;
};

#endif // CARD_HPP

#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#include "Globals.hpp"

class Card {
  public:
    Card(Suit, Rank);
    void printCard();
    Suit getSuit() { return suit; };
    Rank getRank() { return rank; };
    std::string stringifyCard();

    // Comparison Operators for sorting
    friend bool operator<(const Card& l, const Card& r) {
        if (l.rank == r.rank) {
            return (l.suit < r.suit);
        } else {
            return (l.rank < r.rank);
        }
    }

    friend bool operator>(const Card& l, const Card& r) {
        return (r.rank < l.rank);
    }
  private:
    Suit suit;
    Rank rank;
};

#endif // CARD_HPP

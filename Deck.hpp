#ifndef DECK_HPP
#define DECK_HPP

#include <vector>

#include "Card.hpp"
#include "Globals.hpp"

class Deck
{
  public:
    Deck();
    ~Deck();
    void shuffle();
    void fillDeck();
    bool isEmpty() { return pullDeck.size() == 0; }
    Card draw();
    std::vector<Card> getPlayedCards() { return usedCard; }

  private:
    const unsigned int TOTAL_DECKS = 1;
    std::vector<Card> pullDeck;
    std::vector<Card> usedCard;
};

#endif // DECK_HPP

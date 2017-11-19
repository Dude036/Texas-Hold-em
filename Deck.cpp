#include <algorithm>
#include <vector>

#include "Deck.hpp"
#include "Globals.hpp"

Deck::Deck() {
    fillDeck();
    shuffle();
}


Deck::~Deck() {
    pullDeck.clear();
    usedCard.clear();
}

void Deck::fillDeck() {
    // For every Deck
    for (int t = 0; t < (int)TOTAL_DECKS; ++t) {
        // For every suit
        for (int i=SPADE; i<=DIAMOND; i++) {
            // for every number
            for (int j=ACE; j<=KING; j++) {
                pullDeck.push_back(Card((Suit)i,(Rank)j));
            }
        }
    }
}

Card Deck::draw() {
    // Cehck if the deck is empty.
    if (pullDeck.size() == 0) {
        fillDeck();
        shuffle();
        usedCard.clear();
    }

    Card returnCard = pullDeck[pullDeck.size()-1];
    pullDeck.pop_back();

    usedCard.push_back(returnCard);

    return returnCard;
}

void Deck::shuffle() {
    std::random_shuffle(pullDeck.begin(), pullDeck.end());
}

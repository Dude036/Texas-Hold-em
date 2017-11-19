#ifndef GLOBALS_HPP
#define GLOBALS_HPP

const int INITIAL_POT = 500;
const int BLIND = INITIAL_POT / 100;
const unsigned int TOTAL_DECKS = 1;

enum RankedWin {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};

enum Suit {
    SPADE,
    HEART,
    CLUB,
    DIAMOND
};

enum Rank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

enum PlayerState {
    IN_PLAY,
    FOLD,
    BROKE
};

#endif  // GLOBALS_HPP

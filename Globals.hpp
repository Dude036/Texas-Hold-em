#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include <string>

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
    DIAMOND,
    CLUB,
    HEART,
    SPADE
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

const std::string magenta("\033[0;35m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string white("\033[0;39m");
const std::string reset("\033[0m");

#endif  // GLOBALS_HPP

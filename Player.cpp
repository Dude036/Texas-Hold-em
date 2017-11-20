#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "AIPlayer.hpp"
#include "Globals.hpp"
#include "Player.hpp"

Player::Player(AIPlayer newPlayer, std::string newName)
: player(newPlayer), playerName(newName) {
    earnings = INITIAL_POT;
    state = IN_PLAY;
}

Player::~Player() {
    hand.clear();
    earnings = 0;
}

void Player::buyIn(int amount) {
    if (earnings < 0) {
        state = BROKE;
        return;
    }
    earnings -= amount;
}

bool Player::addMoney(int amount) {
    earnings += amount;
    if (earnings < 0) {
        state = BROKE;
        return false;
    }
    return true;
}

int Player::getEarnings() {
    return earnings;
}

void Player::addCard(Card card) {
    hand.push_back(card);
}

PlayerState Player::getState() {
    return state;
}

void Player::fold() {
    state = FOLD;
}

bool Player::canPlayAgain() {
    return earnings >= BLIND * 2;
}

RankedWin Player::getHighState(std::vector<Card> river) {
    // Combine the 2 vectors for simple searching
    std::vector<Card> v(river);
    for (int i = 0; i < (int)hand.size(); ++i) {
        v.push_back(hand[i]);
    }

    // Sort the Deck by smaller Rank, then largest suit
    std::sort(v.begin(), v.end());

    std::cout << "Sorted: | Size=" << v.size() << std::endl;
    for (int i = 0; i < (int)v.size(); ++i) {
        v[i].printCard();
        std::cout << "\t";
    }


    // Start for the least likely scenerio to the most likely
    /* Check for Straight Aspect */
    Suit s = v[0].getSuit();
    bool isStraight = false, isFlush = true;
    for (int i = 0; i < (int)v.size() - 4; ++i) {
        if (v[i].getRank() + 1 == v[i+1].getRank() &&
            v[i+1].getRank() + 1 == v[i+2].getRank() &&
            v[i+2].getRank() + 1 == v[i+3].getRank() &&
            v[i+3].getRank() + 1 == v[i+4].getRank()) {
            isStraight = true;
        }
    }

    /* Check for Flush Aspect */
    int riverFailed = 0;
    for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i].getSuit() != s) {
            riverFailed++;
        }
        if (riverFailed == 3) {
            isFlush = false;
            break;
        }
    }

    if (isStraight && isFlush) {
        // ROYAL_FLUSH
        if (v[v.size()-1].getRank() == ACE) {
            return ROYAL_FLUSH;
        }

        // STRAIGHT_FLUSH
        return STRAIGHT_FLUSH;
    } else if (isFlush) {
        // FLUSH
        return FLUSH;
    } else if (isStraight) {
        // STRAIGHT
        return STRAIGHT;
    }

    // FOUR_OF_A_KIND
    for (int i = 0; i < (int)v.size() - 3; ++i) {
        if (v[i].getRank() == v[i+1].getRank() &&
            v[i+1].getRank() == v[i+2].getRank() &&
            v[i+2].getRank() == v[i+3].getRank()) {
            return FOUR_OF_A_KIND;
        }
    }

    /* Three Pair Checking */
    bool isThree = false;
    for (int i = 0; i < (int)v.size() - 2; ++i) {
        if (v[i].getRank() == v[i+1].getRank() &&
            v[i+1].getRank() == v[i+2].getRank()) {
            isThree = true;
        }
    }

    /* Two Pair Checking */
    int pairs = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = i+1; j < (int)v.size(); ++j) {
            if (v[i].getRank() == v[j].getRank()) {
                pairs++;
            }
        }
    }

    if (isThree && pairs > 3) {
        // FULL_HOUSE
        return FULL_HOUSE;
    } else if (isThree) {
        // THREE_KIND
        return THREE_KIND;
    } else if (pairs == 2) {
        // TWO_PAIR
        return TWO_PAIR;
    } else if (pairs == 1) {
        // PAIR
        return PAIR;
    } else {
        // HIGH_CARD
        return HIGH_CARD;
    }
}


/* AI Player Determined Functions */
int Player::initialBet() {
    return player.initialBet();
}

int Player::bet(std::vector<Card> river, unsigned int callBet) {
    return player.bet(hand, river, callBet);
}

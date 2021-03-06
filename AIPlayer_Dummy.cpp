#include <cstdlib>

#include "AIPlayer_Dummy.hpp"

/******************************************************************************
 * This is a Basic Implementation of  the virtual functions from the inherited
 * AIPlayer class.
 *
 * Note: Consider these as dummy functions. They do very little toattempt to
 * win, if anything. I woudln't recommend using this for  anything other than
 * protoype references. You are, however, free to do whatever you want.
 *****************************************************************************/

/**
 * Basic Constructor. Initializer list contains the constructor from parent
 * class (which does nothing with it.)
 * @brief Basic Constructor
 * @param int Your initial betting pool
 */
AIPlayer_Dummy::AIPlayer_Dummy(int bettingPool) : AIPlayer(bettingPool) {
    totalEarnings = bettingPool;
    srand(0);
}

/**
 * You may initially bet as much as your earnings
 * @brief The inital bet of the player
 * @return How much to initially bet
 */
int AIPlayer_Dummy::initialBet() {
    // If I have less than $10
    if (totalEarnings / 10 < 1) {
        // All in
        return totalEarnings;
    }
    // If I have less than $100
    if (totalEarnings / 100 < 1) {
        // Do it by 10
        return totalEarnings / 10;
    }
    // Play by $100 amounts
    return totalEarnings / 100;
}

/**
 * You may initially bet as much as your earnings
 * @brief The inital bet of the player
 * @return How much to initially bet
 */
void AIPlayer_Dummy::updateBalance(int amount) {
    totalEarnings += amount;
    return;
}

/**
 * This function is called every time a player may make a bet.
 * hand will always be populated. There are a few cases for the river:
 * Case 1: River has no cards -> Initial round of betting.
 * Nothing super special, just check your own cards to bet.
 * Case 2: River has three cards -> Second round of betting. This is
 * the average time where people fold.
 * Case 3: River has four cards -> Third round of betting. This weeds
 * out a few more.
 * case 4: River has five cards -> Final round of betting. Last call.
 * @brief Determine's the betting amount
 * @param hand Vector containing your two cards
 * @param river How many cards are currently in the river
 * @param callBet this is the highest bet.
 * @return How much to bet.
 *      if folding,  return -1
 *      if checking, return 0
 *      if raising,  return (how much more to raise)
 *          callbet == 5, returning 5 will raise the bet to 10;
 */
int AIPlayer_Dummy::bet(std::vector<Card> hand, std::vector<Card> river,
        unsigned int callBet, RankedWin highState) {
    // Dummy Player Calls when rand() / 2 is even
    if ((rand() >> 2) % 2 == 0) {
        return 2;
    } else {
        return 0;
    }
}

/**
 * This function will be called at the end of every game round. This
 / will contain all the cards that weren't folded. If there was a fold,
 * that hand is discarded. There's nothing to do with the cards, because
 * the round is
 * @brief Contains all of the cards you may card about for counting cards
 * @param std::vector<Card> Your Hand
 * @param std::vector<Card> All of the Other Players hands
 * @param std::vector<Card> The River
 */
void AIPlayer_Dummy::endRound(std::vector<Card> hand, std::vector<Card> river,
        std::vector<Card> other, int net) {
    // Default Player doesn't care about counting cards.
    return;
}

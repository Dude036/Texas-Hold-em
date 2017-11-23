#include "AIPlayer.hpp"

/**
 * Basic Constructor
 * @brief Basic Constructor
 * @param int Your initial betting pool
 */
AIPlayer::AIPlayer(int bettingPool) {}

/**
 * You may initially bet as much as your earnings
 * @brief The inital bet of the player
 * @return How much to initially bet
 */
int AIPlayer::initialBet() {
    return 10;
}

/**
 * @brief A helper function called when buying in
 * @param int Amount to modify
 */
void AIPlayer::updateBalance(int amount) {
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
int AIPlayer::bet(std::vector<Card> hand, std::vector<Card> river,
        unsigned int callBet, RankedWin highState) {
    // Initial Player always calls
    return 0;
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
void AIPlayer::endRound(std::vector<Card> hand, std::vector<Card> river,
        std::vector<Card> other, int net) {
    // Default Player doesn't care about counting cards.
    return;
}

#include <algorithm>

#include "Globals.hpp"
#include "Player.hpp"
#include "Table.hpp"

Table::Table() {
    tablePot = 0;
    highBet = 0;
    roundsPlayed = 0;
}

Table::~Table() {}

void Table::addPlayer(Player newPlayer) {
    players.push_back(newPlayer);
    playerPot.push_back(0);
}

void Table::removePlayers() {
    for (int i = 0; i < (int)players.size(); ++i) {
        // Remove player from game if Broke, or can't play again
        if (players[i].getState() == BROKE) {
            players.erase(players.begin()+i);
        } else if (!players[i].canPlayAgain()) {
            players.erase(players.begin()+i);
        }
    }
}

std::vector<int> Table::playRound() {
    // Reset variables for play
    tablePot = 0;
    highBet = 0;
    ++roundsPlayed;
    removePlayers();
    river.clear();

    // Buy in + Blinds
    for (int i = 0; i < (int)players.size(); ++i) {
        if (roundsPlayed + i % players.size() == 0) {
            // double blind - Current High Bet
            players[i].buyIn(BLIND * 1.5);
            tablePot += BLIND * 1.5;
            highBet = BLIND * 1.5;
            playerPot[i] = BLIND * 1.5;
        } else if (roundsPlayed + i % players.size() == 1) {
            // single blind
            players[i].buyIn(BLIND * 1.25);
            tablePot += BLIND * 1.25;
            playerPot[i] = BLIND * 1.25;
        } else {
            // Just initialBet
            players[i].buyIn(BLIND);
            tablePot += BLIND;
            playerPot[i] = BLIND;
        }
    }

    // Deal cards to player
    for (int j = 0; j < 2; ++j) {
        /*Burn*/ deck.draw();
        for (int i = 0; i < (int)players.size(); ++i) {
            players[i].addCard(deck.draw());
        }
    }

    // Initial Round of betting
    do {
        playBettingRound();
    } while (!playerPotsNormalized());

    // Deal 3 to the River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());
    river.push_back(deck.draw());
    river.push_back(deck.draw());

    // Second Round of betting
    do {
        playBettingRound();
    } while (!playerPotsNormalized());

    // Deal to River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());

    // Third Round of betting
    do {
        playBettingRound();
    } while (!playerPotsNormalized());

    // Deal to River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());

    // Final Round of betting
    do {
        playBettingRound();
    } while (!playerPotsNormalized());

    // Determine winner
    std::vector<int> winner = whoWon();

    // Special cases for Winner
    int dividedPot = tablePot / winner.size();

    // Move Pot to winning players
    for (int i = 0; i < (int)winner.size(); ++i) {
        players[winner[i]].addMoney(dividedPot);
    }

    // Clear Hands
    for (int i = 0; i < (int)players.size(); ++i) {
        players[i].clearHand();
    }

    // return winner of the round
    return winner;
}

std::string Table::getPlayerNameByIndex(int i) {
    return players[i].getPlayerName();
}

int Table::getPlayerEarningsbyIndex(int i) {
    return players[i].getEarnings();
}

void Table::playBettingRound() {
    for (int i = 0; i < (int)players.size(); ++i) {
        if (players[i].getState() == FOLD) {
            // Player has folded
            continue;
        }
        // Still is IN_PLAY or BROKE
        int betAmount = players[i].bet(river, highBet);
        if (betAmount == -1) {
            // Fold State
            players[i].fold();
        } else if (betAmount > 0 && betAmount <= players[i].getEarnings()) {
            // Raising
            int diff = highBet - playerPot[i];
            if (players[i].addMoney(-1*diff)) {
                tablePot += betAmount + diff;
                playerPot[i] += betAmount;
                highBet = playerPot[i];
            } else {
                players[i].fold();
            }
        } else {
            // Default and Checking
            int diff = highBet - playerPot[i];
            if (players[i].addMoney(-1*diff)) {
                tablePot += diff;
                playerPot[i]  += diff;
            } else  {
                players[i].fold();
            }
        }
    }
}

bool Table::playerPotsNormalized() {
    int normal = playerPot[0];
    for (int i = 0; i < (int)players.size(); ++i) {
        if (playerPot[i] != normal) {
            return false;
        }
    }
    return true;
}

bool sortBySecond(const std::pair<int, RankedWin>& l,
        const std::pair<int, RankedWin>& r) {
    return (l.second > r.second);
}


int Table::comparePairs(std::vector<Card> l, std::vector<Card> r) {
    Card cl = l[1], cr = r[1];
    if (cl > cr) {
        return -1;
    } else if (cl < cr) {
        return 1;
    } else if (cl.getSuit() > cr.getSuit()) {
        return -1;
    } else if (cl.getSuit() < cr.getSuit()) {
        return 1;
    } else {
        return 0;
    }
}

int Table::compareHighs(Card l, Card r) {
    if (l > r) {
        return -1;
    } else if (l < r) {
        return 1;
    } else if (l.getSuit() > r.getSuit()) {
        return -1;
    } else if (l.getSuit() < r.getSuit()) {
        return 1;
    } else {
        return 0;
    }
}
std::vector<int> Table::whoWon() {
    // Initialize the winner vector
    std::vector<std::pair<int, RankedWin> > ranks;
    // Get Ranks
    for (int i = 0; i < (int)players.size(); ++i) {
        ranks.push_back(std::make_pair(i, players[i].getHighState(river)));
    }

    // Sort Ranks by winning rank in ascending order
    std::sort(ranks.begin(), ranks.end(), sortBySecond);

    // Get Highest Winner
    std::vector<int> winners;
    winners.push_back(ranks[0].first);

    // Check for Ties
    for (int i = 0; i < (int)ranks.size(); ++i) {
        if (ranks[i].second == ranks[i+1].second) {
            // Tie found
           if (ranks[i].second >= STRAIGHT) {
                // Already used a five card hand. Get High card
                // Compare high based on the sorted ranks position in Player vector
                int res = compareHighs(players[ranks[i].first].getHighCard(river),
                                     players[ranks[i+1].first].getHighCard(river));

                if (res > 0) {
                    // Check if Right hand side is bigger
                    winners[winners.size()-1] = ranks[i].first;
                } else if (res < 0) {
                    // Check if Left hand side is bigger
                    winners[winners.size()-1] = ranks[i+1].first;
                } else {
                    // Tie. Add it to Players
                    winners.push_back(ranks[i+1].first);
                }
            } else {
                // All other scenarios deal with an ability to have a pair
                std::vector<Card> vi = players[ranks[i].first].getHighPair(river);
                std::vector<Card> vj = players[ranks[i+1].first].getHighPair(river);

                // Make sure the pairs exist
                if (vi.size() == 0 || vj.size() == 0) {
                    // No Pairs Found, check high Card
                    int res = compareHighs(players[ranks[i].first].getHighCard(river),
                                         players[ranks[i+1].first].getHighCard(river));

                    if (res > 0) {
                        winners[winners.size()-1] = ranks[i+1].first;
                    } else if (res < 0) {
                        winners[winners.size()-1] = ranks[i].first;
                    } else {
                        // Tie or in River - Check second high
                        int res = compareHighs(players[ranks[i].first].getSecondHigh(river),
                                         players[ranks[i+1].first].getSecondHigh(river));

                        if (res > 0) {
                            winners[winners.size()-1] = ranks[i+1].first;
                        } else if (res < 0) {
                            winners[winners.size()-1] = ranks[i].first;
                        } else {
                            // River contians highest card. just put it in the vector
                            winners.push_back(ranks[i+1].first);
                        }
                    }
                } else {
                    // Pairs Found
                    int res = comparePairs(vi, vj);
                    if (res > 0) {
                        winners[winners.size()-1] = ranks[i+1].first;
                    } else if (res < 0) {
                        winners[winners.size()-1] = ranks[i].first;
                    } else {
                        // Tie on the pairs, Check High card
                        int res = compareHighs(players[ranks[i].first].getHighCard(river),
                                             players[ranks[i+1].first].getHighCard(river));

                        if (res > 0) {
                            winners.push_back(ranks[i+1].first);
                        } else if (res < 0) {
                            winners.push_back(ranks[i].first);
                        } else {
                            // Tie or in River - Check second high
                            int res = compareHighs(players[ranks[i].first].getSecondHigh(river),
                                             players[ranks[i+1].first].getSecondHigh(river));

                            if (res > 0) {
                                winners[winners.size()-1] = ranks[i+1].first;
                            } else if (res < 0) {
                                winners[winners.size()-1] = ranks[i].first;
                            } else {
                                // Unresolved. Just put it in the vector
                                winners.push_back(ranks[i+1].first);
                            }
                        }
                    }
                }
            }
        } else {
            // Winners can't join
            break;
        }
    }

    return winners;
}

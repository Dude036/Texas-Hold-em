#include "Globals.hpp"
#include "Player.hpp"
#include "Table.hpp"

Table::Table() {
    tablePot = 0;
    highBet = 0;
    roundsPlayed = 0;
}

Table::~Table() {
    players.clear();
    river.clear();
}

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

int Table::playRound() {
    // Reset variables for play
    tablePot = 0;
    highBet = 0;
    ++roundsPlayed;
    removePlayers();

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
    } while (playerPotsNormalized());

    // Deal 3 to the River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());
    river.push_back(deck.draw());
    river.push_back(deck.draw());

    // Second Round of betting
    do {
        playBettingRound();
    } while (playerPotsNormalized());

    // Deal to River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());

    // Third Round of betting
    do {
        playBettingRound();
    } while (playerPotsNormalized());

    // Deal to River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());

    // Final Round of betting
    do {
        playBettingRound();
    } while (playerPotsNormalized());

    // Determine winner

    // Move Pot to winning player, remove earnings from users

    // return winner of the round
    return 0;
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

int Table::whoWon() {
    int winner;
    std::vector<RankedWin> ranks;
    // Get Ranks
    for (int i = 0; i < (int)players.size(); ++i) {
        ranks.push_back(players[i].getHighState(river));
    }

    // Get Winner from ranks
    RankedWin highestWin;
    for (int i = 0; i < (int)ranks.size() - 1; ++i) {
        if (ranks[i] < ranks[i+1]) {
            winner = i+1;
            highestWin = ranks[i+1];
        }
    }

    // Check for Tie
    for (int i = 0; i < (int)ranks.size(); ++i) {
        if (i == winner) { continue; }
        if (highestWin == ranks[i]) {
            // Tie Found

        }
    }

    return winner;
}
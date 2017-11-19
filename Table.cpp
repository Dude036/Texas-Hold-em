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
            // double blind
            players[i].buyIn(BLIND * 1.5);
            tablePot += BLIND * 1.5;
        } else if (roundsPlayed + i % players.size() == 1) {
            // single blind
            players[i].buyIn(BLIND * 1.25);
            tablePot += BLIND * 1.25;
        } else {
            // Just initialBet
            players[i].buyIn(BLIND);
            tablePot += BLIND;
        }
    }

    // Deal cards to player
    for (int j = 0; j < 2; ++j) {
        /*Burn*/ deck.draw();
        for (int i = 0; i < (int)players.size(); ++i) {
            players[i].addCard(deck.draw());
        }
    }

    // Fill highBet

    // Initial Round of betting
    playBettingRound();

    // Deal 3 to the River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());
    river.push_back(deck.draw());
    river.push_back(deck.draw());

    // Second Round of betting

    // Deal to River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());

    // Third Round of betting

    // Deal to River
    /*Burn*/ deck.draw();
    river.push_back(deck.draw());

    // Final Round of betting

    // Determine winner

    // Move Pot to winning player, remove earnings fromm users

    // return winner of the round
    return 0;
}


void Table::playBettingRound() {

}

bool Table::playerPotsNormalized() {
    int normal = players[0].getEarnings();
    for (int i = 0; i < (int)players.size(); ++i) {
        if (players[i].getEarnings() != normal) {
            return false;
        }
    }
    return true;
}

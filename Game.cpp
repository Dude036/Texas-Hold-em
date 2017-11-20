#include <iomanip>
#include <iostream>

#include "Game.hpp"
#include "Globals.hpp"
#include "Table.hpp"

Game::Game() {}


Game::~Game() {
    // Print the final scoreboard
    std::cout << "===Final Score===" << std::endl;
    std::cout << "           " << "Rounds Won | Final Pot" << std::endl;
    for (int i = 0; i < (int)playerScores.size(); ++i) {
        std::cout << "Player " << std::left << std::setw(2) << i+1 << ": "
                  << table.getPlayerNameByIndex(i) << std::endl
                  << "           " << std::setw(11) << playerScores[i] << "  "
                  << std::setw(9) << table.getPlayerEarningsbyIndex(i)
                  << std::endl;
    }
}

void Game::play(int rounds) {
    if (playerScores.size() < 2) {
        std::cout << "Not enough Players!" << std::endl;
        return;
    } else if (playerScores.size() > 99) {
        std::cout << "Too many Players!" << std::endl;
        return;
    }

    for (int i = 0; i < rounds; ++i) {
        playerScores[table.playRound()] += 1;
    }
}

void Game::addUser(Player newPlayer) {
    playerScores.push_back(0);
    table.addPlayer(newPlayer);
}

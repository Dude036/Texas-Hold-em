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
        std::cout << "Player " << i+1 << ':';
        std::cout << std::endl;
    }
}

void Game::play(int rounds) {
    if (playerScores.size() < 2) {
        std::cout << "Not enough Players!" << std::endl;
        return;
    }

    for (int i = 0; i < rounds; ++i) {
        table.playRound();
    }
}

void Game::addUser(Player newPlayer) {
    playerScores.push_back(0);
    table.addPlayer(newPlayer);
}

#include <iostream>
#include <map>

#include "AllAIPlayers.hpp"
#include "Game.hpp"
#include "Globals.hpp"

int main(int argc, char const *argv[])
{
    int rounds = 1000;
    Game game;
    std::map<std::string, AIPlayer*> map = getPlayerMap();

    for (auto const x : map) {
        game.addUser(Player(*x.second, x.first));
    }

    game.play(rounds);
    return 0;
}

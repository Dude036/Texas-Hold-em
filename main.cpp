#include <iostream>

#include "AllAIPlayers.hpp"
#include "Game.hpp"
#include "Globals.hpp"

int main(int argc, char const *argv[])
{
    int rounds = 1000;
    Game game;
    game.addUser(Player(AIPlayer(INITIAL_POT), "Josh"));
    game.addUser(Player(AIPlayer_Dummy(INITIAL_POT), "Dummy1"));
    game.addUser(Player(AIPlayer_Dummy(INITIAL_POT), "Dummy2"));
    game.addUser(Player(AIPlayer_Dummy(INITIAL_POT), "Dummy3"));

    game.play(rounds);
    return 0;
}

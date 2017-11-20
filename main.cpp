#include <iostream>

#include "Game.hpp"
#include "Globals.hpp"

int main(int argc, char const *argv[])
{
    int rounds = 1000;
    Game game;
    game.addUser(Player(AIPlayer(INITIAL_POT), "Josh"));
    game.addUser(Player(AIPlayer(INITIAL_POT), "Jared"));
    game.addUser(Player(AIPlayer(INITIAL_POT), "Terra"));
    game.addUser(Player(AIPlayer(INITIAL_POT), "Mason"));
    game.addUser(Player(AIPlayer(INITIAL_POT), "Atticus"));
    game.addUser(Player(AIPlayer(INITIAL_POT), "Racheal"));

    game.play(rounds);
    return 0;
}

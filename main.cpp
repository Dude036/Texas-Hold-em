#include <iostream>

#include "Game.hpp"
#include "Globals.hpp"

int main(int argc, char const *argv[])
{
    int rounds = 5;
    Game game;
    game.addUser(Player(AIPlayer(INITIAL_POT), "Josh"));
    game.addUser(Player(AIPlayer(INITIAL_POT), "Kevin"));

    game.play(rounds);
    std::cout << "End Game" << std::endl;
    game.endGame();
    std::cout << "Game End" << std::endl;
    return 0;
}

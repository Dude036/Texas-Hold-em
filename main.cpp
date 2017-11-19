#include <iostream>

#include "Game.hpp"
#include "Globals.hpp"

int main(int argc, char const *argv[])
{
    int rounds = 5;
    Game game;

    game.play(rounds);
    return 0;
}

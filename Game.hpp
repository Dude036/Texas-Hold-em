#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

#include "Card.hpp"
#include "Player.hpp"
#include "Table.hpp"

class Game {
  public:
    Game();
    ~Game();
    void play(int);
    void addUser(Player);
    void endGame();

    Table table;
  private:
    std::vector<int> playerScores;
};

#endif // GAME_HPP

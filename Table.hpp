#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>

#include "Deck.hpp"
#include "Player.hpp"

class Table
{
  public:
    Table();
    ~Table();
    void addPlayer(Player);
    void removePlayers();
    int playRound();
    std::string getPlayerNameByIndex(int);
    int getPlayerEarningsbyIndex(int);

    std::vector<Card> river;
    unsigned int tablePot;
    unsigned int highBet;
  private:
    void playBettingRound();
    bool playerPotsNormalized();
    void fillPots();
    int whoWon();

    Deck deck;
    std::vector<Player> players;
    std::vector<int> playerPot;
    unsigned int roundsPlayed;
};

#endif  // TABLE_HPP

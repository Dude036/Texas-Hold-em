#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

#include "AIPlayer.hpp"
#include "Card.hpp"

class Player
{
  public:
    Player(AIPlayer, std::string);
    ~Player();
    void buyIn(int);
    bool addMoney(int);
    int getEarnings();
    void addCard(Card);
    PlayerState getState();
    void fold();
    bool canPlayAgain();
    RankedWin getHighState(std::vector<Card>);
    // Player Functions
    int initialBet();
    int bet(std::vector<Card>, unsigned int);

  private:
    std::vector<Card> hand;
    AIPlayer player;
    PlayerState state;
    std::string playerName;
    int earnings;
};

#endif  // PLAYER_HPP

#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include <vector>

#include "Card.hpp"

class AIPlayer
{
  public:
    AIPlayer(int);
    ~AIPlayer();
    int initialBet();
    int bet(std::vector<Card>, std::vector<Card>, unsigned int);
    void endRound();
    void addMoney(int);
  private:
    // Add anything you need
};

#endif // AIPLAYER_HPP

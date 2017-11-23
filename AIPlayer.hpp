#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include <vector>

#include "Card.hpp"
#include "Globals.hpp"

class AIPlayer
{
  public:
    AIPlayer(int);
    virtual int initialBet();
    virtual void updateBalance(int);
    virtual int bet(std::vector<Card>, std::vector<Card>, unsigned int, RankedWin);
    virtual void endRound(std::vector<Card>, std::vector<Card>, std::vector<Card>, int);
  private:
    // Add anything you need
};

#endif // AIPLAYER_HPP

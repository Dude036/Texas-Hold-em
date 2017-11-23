#ifndef AIPLAYER_HIGH_ROLLER_HPP
#define AIPLAYER_HIGH_ROLLER_HPP

#include "AIPlayer.hpp"
#include "Globals.hpp"

class AIPlayer_High_Roller: public AIPlayer
{
  public:
    AIPlayer_High_Roller(int);
    int initialBet();
    void updateBalance(int);
    int bet(std::vector<Card>, std::vector<Card>, unsigned int, RankedWin);
    void endRound(std::vector<Card>, std::vector<Card>, std::vector<Card>, int);
  private:
    int totalEarnings;
    int initialEarnings;
    int roundBets;
};

#endif  // AIPLAYER_HIGH_ROLLER_HPP

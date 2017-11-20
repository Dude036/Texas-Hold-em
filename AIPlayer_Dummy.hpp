#ifndef AIPLAYER_DUMMY_HPP
#define AIPLAYER_DUMMY_HPP

#include "AIPlayer.hpp"

class AIPlayer_Dummy: public AIPlayer
{
  public:
    AIPlayer_Dummy(int);
    int initialBet();
    int bet(std::vector<Card>, std::vector<Card>, unsigned int);
    void endRound(std::vector<Card>, std::vector<Card>, std::vector<Card>, int);
  private:
    int totalEarnings;
};

#endif  // AIPLAYER_DUMMY_HPP

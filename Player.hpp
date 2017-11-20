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
    void clearHand();
    Card getHighCard(std::vector<Card>);
    Card getSecondHigh(std::vector<Card>);
    std::vector<Card> getHighPair(std::vector<Card>);
    RankedWin getHighState(std::vector<Card>);
    std::string getPlayerName();
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

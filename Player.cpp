#include <string>
#include <vector>

#include "AIPlayer.hpp"
#include "Globals.hpp"
#include "Player.hpp"

Player::Player(AIPlayer* newPlayer, std::string newName) {
    player = newPlayer;
    playerName = newName;
    earnings = INITIAL_POT;
    state = IN_PLAY;
}

Player::~Player() {
    hand.clear();
    earnings = 0;
}

void Player::buyIn(int amount) {

}

void Player::addMoney(int amount) {
    earnings += amount;
    if (earnings < 0) {
        state = BROKE;
    }
}

int Player::getEarnings() {
    return earnings;
}

void Player::addCard(Card card) {
    hand.push_back(card);
}

PlayerState Player::getState() {
    return state;
}

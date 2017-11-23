#ifndef ALL_AI_PLAYERS_HPP
#define ALL_AI_PLAYERS_HPP

#include <map>
#include <string>

#include "AIPlayer_Dummy.hpp"
#include "AIPlayer_High_Roller.hpp"

std::map<std::string, AIPlayer*> getPlayerMap() {
    std::map<std::string, AIPlayer*> map;

    map["Dummy Player1"] = new AIPlayer_Dummy(INITIAL_POT);
    map["High Roller"] = new AIPlayer_High_Roller(INITIAL_POT);
    // Populate with all of the other players.

    return map;
}

#endif  // ALL_AI_PLAYERS_HPP

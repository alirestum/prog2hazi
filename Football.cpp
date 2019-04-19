//
// Created by Restum Ali on 2019-04-15.
//

#include "Football.h"

const String &Football::getSecondcoach() const {
    return secondcoach;
}

void Football::setSecondcoach(const String &secondcoach) {
    Football::secondcoach = secondcoach;
}

Football::Football(const Football &rhs) {
    players = new String[rhs.playercnt];
    playercnt = rhs.playercnt;
    for (size_t i = 0; i < rhs.playercnt; i++) {
        players[i] = rhs[i];
    }
    coach = rhs.coach;
    secondcoach = rhs.secondcoach;

}

Football& Football::operator=(const Football& rhs){
    if (this->players != rhs.players) {
        delete[] players;
        playercnt = rhs.playercnt;
        players = new String[playercnt];
        for (size_t i = 0; i < playercnt; i++)
            players[i] = rhs.players[i];
        coach = rhs.coach;
        secondcoach = rhs.secondcoach;
    }
    return *this;

}

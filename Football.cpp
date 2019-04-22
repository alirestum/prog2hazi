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
    name = rhs.name;

}

Football &Football::operator=(const Football &rhs) {
    if (this->players != rhs.players) {
        delete[] players;
        playercnt = rhs.playercnt;
        players = new String[playercnt];
        for (size_t i = 0; i < playercnt; i++)
            players[i] = rhs.players[i];
        coach = rhs.coach;
        secondcoach = rhs.secondcoach;
        name = rhs.name;
    }
    return *this;

}

std::ostream &operator<<(std::ostream &os, Football &out) {
    os << "Team: " << out.getName() << "\n";
    os << "\tJatekosok:\n";
    for (size_t i = 0; i < out.size(); i++)
        os << "\t\t" << out[i] << "\n";
    os << "\tCoach:\n\t" << out.getCoach() << "\n";
    os << "\tSecond coach:\n\t" << out.getSecondcoach();
    return os;
}


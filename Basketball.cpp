//
// Created by Restum Ali on 2019-04-15.
//

#include "Basketball.h"

int Basketball::getpompomcnt() const {
    return pompomcnt;
}

void Basketball::setpompomcnt(int pompomcnt) {
    Basketball::pompomcnt = pompomcnt;
}

Basketball::Basketball(const Basketball &rhs) {
    players = new String[rhs.playercnt];
    playercnt = rhs.playercnt;
    for (size_t i = 0; i < rhs.playercnt; i++) {
        players[i] = rhs[i];
    }
    coach = rhs.coach;
    pompomcnt = rhs.pompomcnt;
    name = rhs.name;
}

Basketball &Basketball::operator=(const Basketball &rhs) {
    if (this->players != rhs.players) {
        delete[] players;
        playercnt = rhs.playercnt;
        players = new String[playercnt];
        for (size_t i = 0; i < playercnt; i++)
            players[i] = rhs.players[i];
        coach = rhs.coach;
        pompomcnt = rhs.pompomcnt;
        name = rhs.name;
    }
    return *this;
}

const char *Basketball::classname() {
    return "Basketball";
}


std::ostream &operator<<(std::ostream &os, Basketball &out) {
    os << "Team: " << out.getName() << "\n";
    os << "\tJatekosok:\n";
    for (int i = 0; i < out.size(); i++)
        os << "\t\t" << out[i] << "\n";
    os << "\tEdzo:\n\t" << out.getCoach() << "\n";
    os << "\tPomPomCnt:\n\t" << out.getpompomcnt();
    return os;

}



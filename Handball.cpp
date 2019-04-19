//
// Created by Restum Ali on 2019-04-19.
//

#include "Handball.h"

int Handball::getYearlybonus() const {
    return yearlybonus;
}

void Handball::setYearlybonus(int yearlybonus) {
    Handball::yearlybonus = yearlybonus;
}

Handball::Handball(const Handball &rhs) {
    players = new String[rhs.playercnt];
    playercnt = rhs.playercnt;
    for (size_t i = 0; i < rhs.playercnt; i++) {
        players[i] = rhs[i];
    }
    coach = rhs.coach;
    yearlybonus = rhs.yearlybonus;
}

Handball &Handball::operator=(const Handball &rhs) {
    if (this->players != rhs.players) {
        delete[] players;
        playercnt = rhs.playercnt;
        players = new String[playercnt];
        for (size_t i = 0; i < playercnt; i++)
            players[i] = rhs.players[i];
        coach = rhs.coach;
        yearlybonus = rhs.yearlybonus;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Handball &out) {
    os << "Jatekosok:\n";
    for (size_t i = 0; i < out.size(); i++)
        os << "\t" << out[i] << "\n";
    os << "Coach:\n\t" << out.getCoach() << "\n";
    os << "Yearly bonus:\n\t" << out.getYearlybonus();
    return os;
}

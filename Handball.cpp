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
    name = rhs.name;
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
        name = rhs.name;
    }
    return *this;
}

void Handball::list(std::ostream &os) {
    os << "Team: " << this->getName() << "\n";
    os << "\tJatekosok:\n";
    for (size_t i = 0; i < this->playercnt; i++)
        os << "\t\t" << players[i] << "\n";
    os << "\tEdzo:\n\t" << this->getCoach() << "\n";
    os << "\tMasodedzo:\n\t" << this->getYearlybonus();
}

const char *Handball::classname() {
    return "Handball";
}

std::ostream &operator<<(std::ostream &os, Handball &out) {
    os << "Team: " << out.getName() << "\n";
    os << "\tJatekosok:\n";
    for (int i = 0; i < out.size(); i++)
        os << "\t\t" << out[i] << "\n";
    os << "\tCoach:\n\t" << out.getCoach() << "\n";
    os << "\tYearly bonus:\n\t" << out.getYearlybonus();
    return os;
}

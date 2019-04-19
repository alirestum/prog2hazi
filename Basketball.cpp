//
// Created by Restum Ali on 2019-04-15.
//

#include "Basketball.h"

int Basketball::getYearlybonus() const {
    return yearlybonus;
}

void Basketball::setYearlybonus(int yearlybonus) {
    Basketball::yearlybonus = yearlybonus;
}

Basketball::Basketball(const Basketball &rhs) {
    players = new String[rhs.playercnt];
    playercnt = rhs.playercnt;
    for (size_t i = 0; i < rhs.playercnt; i++) {
        players[i] = rhs[i];
    }
    coach = rhs.coach;
    yearlybonus = rhs.yearlybonus;
}

Basketball& Basketball::operator=(const Basketball &rhs) {
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




std::ostream &operator<<(std::ostream &os, Basketball &out) {
    os << "Jatekosok:\n";
    for (size_t i = 0; i < out.size(); i++)
        os << "\t" << out[i] << "\n";
    os << "Edzo:\n\t" << out.getCoach() << "\n";
    os << "Yearly bonus:\n\t" << out.getYearlybonus();
    return os;

}



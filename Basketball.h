//
// Created by Restum Ali on 2019-04-15.
//

#ifndef PROG2HAZI_BASKETBALL_H
#define PROG2HAZI_BASKETBALL_H


#include "team.h"
#include "string.h"
#include <iostream>

class Basketball : public Team {
private:
    int pompomcnt;

public:
    Basketball() : Team(), pompomcnt(0) {}
    Basketball(String coachname, int bonus, String tname): Team(coachname, tname), pompomcnt(bonus){}

    int getpompomcnt() const;

    void setpompomcnt(int pompomcnt);

    Basketball(const Basketball &rhs);

    Basketball &operator=(const Basketball &rhs);

    void list(std::ostream& os){
        os << "Team: " << this->getName() << "\n";
        os << "\tJatekosok:\n";
        for (size_t i = 0; i < this->playercnt; i++)
            os << "\t\t" << players[i] << "\n";
        os << "\tEdzo:\n\t" << this->getCoach() << "\n";
        os << "\tPomPomCnt:\n\t" << this->getpompomcnt();


    }

};

std::ostream &operator<<(std::ostream &os, Basketball &out);


#endif //PROG2HAZI_BASKETBALL_H

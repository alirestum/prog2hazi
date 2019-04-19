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
    Basketball(String coachname, int bonus): Team(coachname), pompomcnt(bonus){}

    int getpompomcnt() const;

    void setpompomcnt(int pompomcnt);

    Basketball(const Basketball &rhs);

    Basketball &operator=(const Basketball &rhs);

};

std::ostream &operator<<(std::ostream &os, Basketball &out);


#endif //PROG2HAZI_BASKETBALL_H

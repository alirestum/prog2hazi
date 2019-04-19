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
    int yearlybonus;
public:
    Basketball() : Team(), yearlybonus(0) {}
    Basketball(String coachname, int bonus): Team(coachname), yearlybonus(bonus){}

    int getYearlybonus() const;

    void setYearlybonus(int yearlybonus);

    Basketball(const Basketball &rhs);

    Basketball &operator=(const Basketball &rhs);

};

std::ostream &operator<<(std::ostream &os, Basketball &out);


#endif //PROG2HAZI_BASKETBALL_H

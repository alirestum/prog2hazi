//
// Created by Restum Ali on 2019-04-19.
//

#ifndef PROG2HAZI_HANDBALL_H
#define PROG2HAZI_HANDBALL_H

#include "string5.h"
#include "team.h"
#include <iostream>

class Handball : public Team {
private:
    int yearlybonus;


public:
    Handball() : Team(), yearlybonus(0) {}

    Handball(String coachname, int bonus) : Team(coachname), yearlybonus(bonus) {}

    int getYearlybonus() const;

    void setYearlybonus(int yearlybonus);

    Handball(const Handball &rhs);

    Handball &operator=(const Handball &rhs);
};


std::ostream &operator<<(std::ostream &os, Handball &out);

#endif //PROG2HAZI_HANDBALL_H

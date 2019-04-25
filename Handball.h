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

    Handball(String coachname, String tname, int bonus) : Team(coachname, tname), yearlybonus(bonus) {}
    Handball(String coachname, String tname) : Team(coachname, tname), yearlybonus(0) {}
    int getYearlybonus() const;

    void setYearlybonus(int yearlybonus);

    Handball(const Handball &rhs);

    Handball &operator=(const Handball &rhs);

    const String &getType1() const;
};


std::ostream &operator<<(std::ostream &os, Handball &out);

#endif //PROG2HAZI_HANDBALL_H

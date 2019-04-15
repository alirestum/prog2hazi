//
// Created by Restum Ali on 2019-04-15.
//

#ifndef PROG2HAZI_BASKETBALL_H
#define PROG2HAZI_BASKETBALL_H


#include "team.h"

class Basketball : public Team {
private:
    int yearlybonus;
public:
    Basketball(): Team(), yearlybonus(0) {}

    int getYearlybonus() const;

    void setYearlybonus(int yearlybonus);



};


#endif //PROG2HAZI_BASKETBALL_H

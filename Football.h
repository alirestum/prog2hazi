//
// Created by Restum Ali on 2019-04-15.
//

#ifndef PROG2HAZI_FOOTBALL_H
#define PROG2HAZI_FOOTBALL_H

#include "team.h"
#include "string5.h"
#include <iostream>

class Football: public Team{
private:
    String secondcoach;
public:
    Football(): Team(), secondcoach(""){}
    Football(String coachname):Team(coachname), secondcoach(""){}
    Football(String coach, String secondcoach): Team(coach), secondcoach(secondcoach){}

    Football(const Football& rhs);

    Football& operator=(const Football& rhs);
    const String &getSecondcoach() const;

    void setSecondcoach(const String &secondcoach);



};

std::ostream& operator<<(std::ostream& os, Football& out);

#endif //PROG2HAZI_FOOTBALL_H

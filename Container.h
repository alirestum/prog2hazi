//
// Created by Restum Ali on 2019-04-19.
//

#ifndef PROG2HAZI_CONTAINER_H
#define PROG2HAZI_CONTAINER_H
#include "team.h"
#include <iostream>

class Container {
private:
    Team* teams;
    size_t teamcnt;
public:
    Container(): teams(NULL), teamcnt(0){}

    const size_t size() { return teamcnt; } const;
    void addteam(const Team newteam);

};

std::ostream& operator<<(std::ostream& os, Container& out);

#endif //PROG2HAZI_CONATINER_H

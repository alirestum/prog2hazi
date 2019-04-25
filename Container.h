//
// Created by Restum Ali on 2019-04-19.
//

#ifndef PROG2HAZI_CONTAINER_H
#define PROG2HAZI_CONTAINER_H

#include "team.h"
#include <iostream>
#include <fstream>

class Container {
private:
    Team **teams;
    size_t teamcnt;
public:
    Container() : teams(nullptr), teamcnt(0) {}

    const size_t size() { return teamcnt; };

    Team *operator[](size_t idx);

    const Team *operator[](size_t idx) const;

    void addteam(Team *newteam);

    void list(std::ostream& os, size_t idx){
        teams[idx]->list(os);
    }

    void savedata(String &fname);

    ~Container();

};


std::ostream &operator<<(std::ostream &os, Container &out);

#endif //PROG2HAZI_CONATINER_H

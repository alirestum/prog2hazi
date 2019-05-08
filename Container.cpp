//
// Created by Restum Ali on 2019-04-19.
//

#include "Container.h"
#include "Basketball.h"
#include "Football.h"
#include "Handball.h"


void Container::addteam(Team *newteam) {
    Team **temp = new Team *[teamcnt + 1];
    for (size_t i = 0; i < teamcnt; i++)
        temp[i] = teams[i];
    delete[] teams;
    teams = temp;
    teams[teamcnt] = newteam;
    teamcnt++;
}


std::ostream &operator<<(std::ostream &os, Container &out) {
    for (size_t i = 0; i < out.size(); i++)
        os << out[i] << "\n";
    return os;
}


Team *Container::operator[](size_t idx) {
    return teams[idx];
}


const Team *Container::operator[](size_t idx) const {
    return teams[idx];
}



void Container::listnames() {
    for (size_t i = 0; i < teamcnt; i++)
        std::cout<< i << ". " << teams[i]->getName() << " \n";
}

void Container::removeteam(size_t idx) {
    delete teams[idx];
    for (size_t i = idx + 1; i < teamcnt; i++)
        teams[i - 1] = teams[i];
    teamcnt--;
}

Container::~Container() {
    for (size_t i = 0; i < teamcnt; i++)
        delete teams[i];
    delete[] teams;
}
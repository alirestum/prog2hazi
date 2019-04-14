//
// Created by Restum Ali on 2019-04-14.
//

#ifndef PROG2HAZI_TEAM_H
#define PROG2HAZI_TEAM_H

#include <iostream>

using namespace std;

#include "string5.h"


class Team {

private:
    String *players;
    size_t playercnt;
public:
    Team() : players(NULL), playercnt(0) {}

    Team(const Team &rteam);

    void addplayer(const String player);

    size_t size() { return playercnt; }

   // const size_t size() { return playercnt; } const;

    Team &operator=(const Team &team);

    String &operator[](size_t index);

    const String &operator[](size_t index) const;

    ostream &operator<<(ostream &os);

    virtual ~Team() { delete[] players; }

};




#endif //PROG2HAZI_TEAM_H

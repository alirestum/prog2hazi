//
// Created by Restum Ali on 2019-04-14.
//

#ifndef PROG2HAZI_TEAM_H
#define PROG2HAZI_TEAM_H

#include <iostream>

using namespace std;

#include "string5.h"
#include "memtrace.h"
#include <iostream>


class Team {

protected:
    String *players;
    size_t playercnt;
    String coach;
public:
    Team() : players(NULL), playercnt(0), coach("") {}

    Team(String coachname) : players(NULL), playercnt(0), coach(coachname) {}

    Team(const Team &rteam);

    void addplayer(const String newplayer);

    void removeplayer(size_t idx);

    void addcoach(const String coach);

    const size_t size() { return playercnt; } const;

    Team &operator=(const Team &team);

    String &operator[](size_t index);

    const String &operator[](size_t index) const;

    virtual ~Team() { delete[] players; }

    const String &getCoach() const;


};

ostream &operator<<(ostream &os, Team &out);


#endif //PROG2HAZI_TEAM_H

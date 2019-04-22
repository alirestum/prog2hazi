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
    String name;
public:
    Team() : players(NULL), playercnt(0), coach("") {}

    Team(String coachname, String tname) : players(NULL), playercnt(0), coach(coachname), name(tname) {}

    Team(const Team &rteam);

    void addplayer(const String &newplayer);

    void removeplayer(size_t idx);

    void addcoach(const String coach);


    const size_t size() { return playercnt; };

    Team &operator=(const Team &team);

    String &operator[](size_t index);

    const String &operator[](size_t index) const;

    virtual ~Team() { delete[] players; }

    const String &getCoach() const;

    const String &getName() const;

    void setName(const String &name);

    virtual void list(std::ostream& os){
        os << "Team: " << this->getName() << "\n";
        os << "\tJatekosok:\n";
        for (size_t i = 0; i < this->size(); i++)
            os << "\t\t" << players[i] << "\n";
        os << "\tEdzo:\n\t" << this->getCoach() << "\n";
     //   os << "\tPomPomCnt:\n\t" << this->getpompomcnt();


    }


};

ostream &operator<<(ostream &os, Team &out);


#endif //PROG2HAZI_TEAM_H

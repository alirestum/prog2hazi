//
// Created by Restum Ali on 2019-04-14.
//

#include "team.h"
#include "string5.h"
#include "memtrace.h"
#include <cstring>


#include <iostream>

using namespace std;


const char *Team::operator[](size_t index) const {
    return players[index].c_str();
}

/*char *Team::operator[](size_t index) {
    return players[index].c_str();
}*/

Team::Team(const Team &rteam) {
    players = new String[rteam.playercnt];
    playercnt = rteam.playercnt;
    for (size_t i = 0; i < rteam.playercnt; i++) {
        players[i] = rteam[i];
    }
    coach = rteam.coach;
    name = rteam.name;
}

void Team::addplayer(const String &newplayer) {
    if (players != NULL) {
        String *temp;
        temp = new String[playercnt + 1];
        for (size_t i = 0; i < playercnt; i++)
            temp[i] = players[i];
        temp[playercnt] = newplayer;
        delete[] players;
        players = temp;
        playercnt++;
    } else {
        players = new String[playercnt + 1];
        players[playercnt] = newplayer;
        playercnt++;
    }

}


void Team::removeplayer(size_t idx) {
    String *temp = new String[playercnt-1];
       for (size_t i = idx+1; i < playercnt; i++)
           players[i-1] = players[i];
       playercnt--;
       for(size_t i= 0; i<playercnt; i++)
           temp[i]=players[i];
       delete []players;
       players = temp;

}


const char *Team::classname() {
    return "Team";
}

Team &Team::operator=(const Team &team) {
    if (this->players != team.players) {
        delete[] players;
        playercnt = team.playercnt;
        players = new String[playercnt];
        for (size_t i = 0; i < playercnt; i++)
            players[i] = team.players[i];
        coach = team.coach;
        name = team.name;
    }
    return *this;
}

void Team::addcoach(const String coach) {
    this->coach = coach;
}

const char *Team::getCoach() const {
    return coach.c_str();
}

const char *Team::getName() const {
    return name.c_str();
}

void Team::setName(const String &name) {
    Team::name = name;
}



ostream &operator<<(ostream &os, Team &out) {
    os << "Team: " << out.getName() << "\n";
    os << "\tJatekosok:\n";
    for (int i = 0; i < out.size(); i++)
        os << "\t\t" << i << ". " << out[i] << "\n";
    os << "\tEdzo:\n" << "\t" << out.getCoach();
    return os;
}



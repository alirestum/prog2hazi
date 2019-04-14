//
// Created by Restum Ali on 2019-04-14.
//

#include "team.h"
#include "string5.h"
#include <cstring>


#include <iostream>

using namespace std;


const String &Team::operator[](size_t index) const {
    return players[index];
}

String &Team::operator[](size_t index) {
    return players[index];
}

Team::Team(const Team &rteam) {
    players = new String[rteam.playercnt];
    playercnt = rteam.playercnt;
    for (size_t i = 0; i < rteam.playercnt; i++) {
        players[i] = rteam[i];
    }
}

void Team::addplayer(const String player) {
    String *temp = new String[playercnt + 1];
    for (size_t i = 0; i < playercnt; i++)
        temp[i] = players[i];
    temp[playercnt + 1] = player;
    playercnt++;
    delete[] players;
    players = temp;
}


Team &Team::operator=(const Team &team) {
    if (this->players != team.players) {
        delete[] players;
        playercnt = team.playercnt;
        players = new String[playercnt];
        for (size_t i = 0; i < playercnt; i++)
            players[i] = team.players[i];
        return *this;
    }
}

ostream& Team::operator<<(ostream &os) {
    os << "Jatekosok:";
    for (size_t i = 0; i < playercnt; i++)
        os << "\t" << players[i];
    return os;
}

/*ostream &operator<<(ostream &os, Team &out) {
    os << "Jatekosok:";
    for (size_t i = 0; i < out.size(); i++)
        os << "\t" << out[i];
    return os;
}*/



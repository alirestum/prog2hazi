//
// Created by Restum Ali on 2019-04-19.
//

#include "Container.h"


void Container::addteam(const Team newteam){
    if(teams != NULL){
        Team *temp;
        temp = new Team[teamcnt+1];
        for( size_t i=0; i<teamcnt; i++)
            temp[i] = teams[i];
        temp[teamcnt]= newteam;
        delete [] teams;
        teams = temp;
        teamcnt++;
    }
    else {
        teams = new Team[teamcnt+1];
        teams[teamcnt] = newteam;
        teamcnt++;
    }
}
/*
std::ostream& operator<<(std::ostream& os, Container& out){
    for(size_t i =0; i<out.size(); i++)
        os << out[i] <<"\n";
    return os;
}*/
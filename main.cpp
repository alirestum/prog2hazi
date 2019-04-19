#include <iostream>
#include "string5.h"
#include "team.h"
#include "memtrace.h"
#include "Basketball.h"
#include "Football.h"
#include "Handball.h"
#include "Container.h"

int main() {
    //Declarations
    Container Container;
    Team team1;
    Basketball team2;
    Football team3;
    Handball team4;
    String player1("player1");
    String player2("player2");
    String player3("player3");
    String player4("player4");

    //Adding players, setting custom attributes

    team2.addplayer(player1); //Basketball
    team2.setpompomcnt(100000);

    team1.addplayer(player1); //Simple team
    team1.addplayer(player2);
    team1.addplayer(player3);
    team1.addplayer(player4);
    team1.removeplayer(3);

    team3.addplayer(player1);// Football
    team3.addplayer(player2);
    team3.setSecondcoach("Lajoska");

    team4.addplayer(player1); //Handball
    team4.setYearlybonus(500);

    Container.addteam(team1);
    Container.addteam(team2);
    Container.addteam(team3);

    // std::cout << "Simple team:\n" << team1 << std::endl;
    // std::cout << "Basketball\n" << team2 << std::endl;
    // std::cout << "Football\n" << team3 << std::endl;
    // std::cout << "Handball\n" << team4 << std::endl;
    std::cout << Container << std::endl;
    return 0;
}
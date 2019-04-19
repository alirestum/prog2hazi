#include <iostream>
#include "string5.h"
#include "team.h"
#include "memtrace.h"
#include "Basketball.h"
int main() {
    Team csapat1;
    Basketball team2;
    String player1("player1");
    String player2("player2");
    String player3("player3");
    String player4("player4");
    team2.addplayer(player1);
    team2.setYearlybonus(100000);
    csapat1.addplayer(player1);
    csapat1.addplayer(player2);
    csapat1.addplayer(player3);
    csapat1.addplayer(player4);
    csapat1.removeplayer(3);
    std::cout << csapat1 << std::endl;
    std::cout << team2 << std::endl;
    return 0;
}
#include <iostream>
#include "string5.h"
#include "team.h"
#include "memtrace.h"

int main() {
    Team csapat1;
    String player1("player1");
    String player2("player2");
    String player3("player3");
    String player4("player4");
    csapat1.addplayer(player1);
    csapat1.addplayer(player2);
    csapat1.addplayer(player3);
    csapat1.addplayer(player4);
    csapat1.removeplayer(3);
    std::cout << csapat1 << std::endl;
    return 0;
}
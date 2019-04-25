#include <iostream>

using namespace std;
#include "string5.h"
#include "team.h"
#include "memtrace.h"
#include "Basketball.h"
#include "Football.h"
#include "Handball.h"
#include "Container.h"
#include "gtest_lite.h"
#include <fstream>

#define Teszt 1

/* Teszt esetek:
 * Teszt == 1 -> Team osztály tesztjei
 * Teszt == 2 -> Basketball osztály tesztjei
 * Teszt == 3 -> Football osztály tesztjei
 */

int main() {
    //Declarations
    Container Container;


    Team team1;
    Basketball team2;
    Football team3;
    Handball team4;

    String teamname("Barcelona");
    String coachname("Test coach");
    String player1("player1");
    String player2("player2");
    String player3("player3");

#if Teszt == 1
    //Team tests
    team1.setName(teamname);
    team1.addcoach(coachname);
    team1.addplayer(player1);
    team1.addplayer(player1);
    team1.addplayer(player1);
    TEST(Team, getName)
        {
            EXPECT_STREQ("Barcelona", team1.getName()) << "Nev nem OK!";
        }
    END
    TEST(Team, getCoach)
        {
            EXPECT_STREQ("Test coach", team1.getCoach()) << "Coach nem OK!";
        }
    END
    TEST(Team, size)
        {
            EXPECT_EQ(3, team1.size()) << "Size nem OK!";
        }
    END
    TEST(Team, operator[])
        {
            for (int i = 0; i < team1.size(); i++)
                EXPECT_STREQ("player1", team1[i]) << "Player nem OK!";
        }
    END
    team1.addplayer(player2);
    team1.addplayer(player3);
    TEST(Team, operator[])
        {
            EXPECT_STREQ("player2", team1[3]) << "Player nem OK!";
        }
    END
    team1.removeplayer(2);
    TEST(Team, size)
        {
            EXPECT_EQ(4, team1.size()) << "Size nem OK!";
        }
    END
    team1.removeplayer(0);
    team1.removeplayer(0);
    TEST(Team, removeplayer)
        {
            EXPECT_STREQ("player3", team1[1]) << "Player nem OK!";
        }
    END
#endif

#if Teszt == 2
    team2.setpompomcnt(120);
    TEST(Basketball, set/get-pompomcnt){
        EXPECT_EQ(120, team2.getpompomcnt()) << "PomPomcnt nem OK!";
    } END

#endif

#if Teszt == 3
    String second("Ernesto Valverde");
    team3.setSecondcoach(second);
    TEST(Football, set/get-secondcoach){
        EXPECT_STREQ("Ernesto Valverde", team3.getSecondcoach()) << "Second coach nem OK!";
    } END
#endif

    return 0;
}


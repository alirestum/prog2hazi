#include <iostream>
#include <typeinfo>

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
#define Mode 2

/* Módok:
 * Mode == 1 -> teszt mód
 * Mode ==2 -> felhasználói mód, felülettel együtt

 * Teszt esetek:
 * Teszt == 1 -> Team osztály tesztjei
 * Teszt == 2 -> Basketball osztály tesztjei
 * Teszt == 3 -> Football osztály tesztjei
 * Teszt == 4 -> Handball osztály tesztjei
 * Teszt == 5 -> Container osztály tesztjei
 */


int main() {
    //Declarations
    Container Container;


    Team team1;
    Football team3;
    Handball team4;

    String teamname("Barcelona");
    String coachname("Test coach");
    String player1("player1");
    String player2("player2");
    String player3("player3");

#if Mode == 1

    //Team tests
#if Teszt == 1
    team1.setName(teamname);
    team1.addcoach(coachname);
    team1.addplayer(player1);
    team1.addplayer(player1);
    team1.addplayer(player1);
    TEST(Team, getName)
        {
            EXPECT_STREQ("Barcelona", team1.getName()) << "Nev nem OK!";
        }
    END //Name test
    TEST(Team, getCoach)
        {
            EXPECT_STREQ("Test coach", team1.getCoach()) << "Coach nem OK!";
        }
    END //Coach test
    TEST(Team, size)
        {
            EXPECT_EQ(3, team1.size()) << "Size nem OK!";
        }
    END //size test #1
    TEST(Team, operator[])
        {
            for (int i = 0; i < team1.size(); i++)
                EXPECT_STREQ("player1", team1[i]) << "Player nem OK!";
        }
    END //idx operator test #1
    team1.addplayer(player2);
    team1.addplayer(player3);
    TEST(Team, operator[])
        {
            EXPECT_STREQ("player2", team1[3]) << "Player nem OK!";
        }
    END //idx operator test #2
    team1.removeplayer(2);
    TEST(Team, size)
        {
            EXPECT_EQ(4, team1.size()) << "Size nem OK!";
        }
    END // size test #2
    team1.removeplayer(0);
    team1.removeplayer(0);
    TEST(Team, removeplayer)
        {
            EXPECT_STREQ("player3", team1[1]) << "Player nem OK!";
        }
    END //player removing test
    //team1.list(std::cout);


    TEST(Team, ctor){
        Team copied = team1;
        EXPECT_EQ(2, copied.size()) << "Size nem OK!";
        EXPECT_STREQ("Barcelona", copied.getName()) << "Nev nem OK!";
        EXPECT_STREQ("Test coach", copied.getCoach()) << "Coach nem OK!";
        EXPECT_STREQ("player2", copied[0]) << "Player nem OK!";
        EXPECT_STREQ("player3", copied[1]) << "Player nem OK!";
    } END //Team ctor

    TEST(Team, operator=){
        Team other;
        other.addcoach("Guardiola");
        other.setName("Mancity");
        for (int i=0; i<50; i++)
            other.addplayer("player1");
        //other.list(std::cout);
        other = team1;
        EXPECT_EQ(2, other.size()) << "Size nem OK!";
        EXPECT_STREQ("Barcelona", other.getName()) << "Nev nem OK!";
        EXPECT_STREQ("Test coach", other.getCoach()) << "Coach nem OK!";
        EXPECT_STREQ("player2", other[0]) << "Player nem OK!";
        EXPECT_STREQ("player3", other[1]) << "Player nem OK!";

    }END

#endif

    //Basketball tests
#if Teszt == 2
    Basketball team2;
    team2.setpompomcnt(120);
    for (int i= 0; i<15; i++)
        team2.addplayer(player1);
    team2.setName("Kosar");
    team2.addcoach("Kosaredzo");

    TEST(Basketball, set/get-pompomcnt){
        EXPECT_EQ(120, team2.getpompomcnt()) << "PomPomcnt nem OK!";
    } END //pompomcnt test
    TEST(Basketball, ctor){
        Basketball copied = team2;
            EXPECT_EQ(15, copied.size()) << "Size nem OK!";
            EXPECT_STREQ("Kosar", copied.getName()) << "Nev nem OK!";
            EXPECT_STREQ("Kosaredzo", copied.getCoach()) << "Coach nem OK!";
            EXPECT_STREQ("player1", copied[0]) << "Player nem OK!";
            EXPECT_STREQ("player1", copied[1]) << "Player nem OK!";
    } END //Basketball ctor test
    TEST(Basketball, operator=){
        Basketball other;
        other.setpompomcnt(140);
        for (int i= 0; i<15; i++)
            other.addplayer(player2);
        other.setName("Kosar1");
        other.addcoach("Kosaredzo1");
        other = team2;
        EXPECT_EQ(15, other.size()) << "Size nem OK!";
        EXPECT_STREQ("Kosar", other.getName()) << "Nev nem OK!";
        EXPECT_STREQ("Kosaredzo", other.getCoach()) << "Coach nem OK!";
        EXPECT_STREQ("player1", other[0]) << "Player nem OK!";
        EXPECT_STREQ("player1", other[1]) << "Player nem OK!";
    } END //Basketball operator= test

#endif

    //Football tests
#if Teszt == 3
    String second("Ernesto Valverde");
    team3.setSecondcoach(second);
    TEST(Football, set/get-secondcoach){
        EXPECT_STREQ("Ernesto Valverde", team3.getSecondcoach()) << "Second coach nem OK!";
    } END
    Football team3copied = team3;
    TEST(Football, ctor){
        EXPECT_STREQ("Ernesto Valverde", team3copied.getSecondcoach()) << "Ctor nem OK!";
    } END
    team3copied.setSecondcoach("test");
    team3 = team3copied;
    TEST(Football, operator=){
        EXPECT_STREQ("test", team3.getSecondcoach()) << "operator= nem OK!";
    } END
#endif


    //Handball tests
#if Teszt == 4
    team4.setYearlybonus(14234);
    TEST(Handball, set/get-yearlybonus){
        EXPECT_EQ(14234,team4.getYearlybonus()) << "Yearly bonus nem OK!";
    } END
    Handball teamcopiedhandball = team4;
    TEST(Handball, ctor){
            EXPECT_EQ(14234,team4.getYearlybonus()) << "Ctor bonus nem OK!";
    } END
    teamcopiedhandball.setYearlybonus(555);
    team4 = teamcopiedhandball;
    TEST(Handball, operator=){
            EXPECT_EQ(555,team4.getYearlybonus()) << "Operator= nem OK!";
    } END

#endif

//Container tests
#if Teszt == 5

    Container.addteam(new Basketball);
    Container.addteam(new Football);
    Container.addteam(new Handball);
    Container.addteam(new Team);

    Container[0]->setName("basketball");
    Container[1]->setName("Football");
    Container[2]->setName("Handball");
    Container[3]->setName("Team");

    TEST(Container, Size){
        EXPECT_EQ(4, (int)(Container.size())) << "Size nem ok!";
    } END
    TEST(Container, operator[]){
        EXPECT_STREQ("Football", ((Football*)Container[1])->getName()) << "operator[] nem OK!";
    } END
    TEST(Container, Removeteam){
        Container.removeteam(1);
            EXPECT_STREQ("Handball", ((Handball*)Container[1])->getName()) << "removeteam nem OK!";
    } END

#endif //Container tesztek

#endif //teszt mód

#if Mode == 2

    class Container csapatok;
    cout << "Fitt sportegyesulet csapatkezelo szoftver" << endl;
    bool exit=false;
    int option;
    bool jocsapat = false;
    while (!exit) {
        cout << "Opcio kivalasztasa(irja be a szamot):\n";
        cout <<"\t1. Csapat hozzaadasa\n\t2. Csapat kezelese\n\t3. Csapat torlese\n\t4. Csapatok listazasa\n\t5. Kilepes"<< endl;
        cin>>option;
        switch (option) {
            case (1):
                //Csapat hozzaadasa
                jocsapat = false;
                char tipus[10];
                while (jocsapat == false) {
                    cout << "Kerem adja meg a csapat tipusat(Basketball/Football/Handball):";
                    cin >> tipus;
                    if (strcmp(tipus, "Basketball") == 0) {
                        csapatok.addteam(new Basketball);
                        jocsapat = true;
                    } else if (strcmp(tipus, "Football") == 0) {
                        csapatok.addteam(new Football);
                        jocsapat = true;
                    } else if (strcmp(tipus, "Handball") == 0) {
                        csapatok.addteam(new Handball);
                        jocsapat = true;
                    } else
                        cout << "Rossz csapat tipus\n";
                }
                cout << "Kerem adja meg a csapat nevet:";
                char nev[100];
                cin >> nev;
                csapatok[csapatok.size() - 1]->setName(nev);
                break;
            case (2): {
                int wteam;
                csapatok.listnames();
                cout << "Irja be a csapat szamat:";
                cin >> wteam;
                cout << "A kivalasztott csapat:" << csapatok[wteam]->getName() << endl;
                bool submenu = false;
                while (!submenu) {
                    int suboption;
                    cout << "Valasszon opciot:\n";
                    cout
                            << "\t1. Jatekos hozzaadasa\n\t2.Jatekos torlese\n\t3.Edzo hozzaadasa\n\t4. Egyedi ertek beallitasa\n\t5.Elozo menu\n";
                    cin >> suboption;
                    switch (suboption) {
                        case (1):
                            cout << "Adja meg a jatekos nevet:";
                            char jnev[100];
                            cin >> jnev;
                            csapatok[wteam]->addplayer(jnev);
                            break;
                        case (2):
                            cout << "Valassza ki a torlendo jatekost\t";
                            csapatok[wteam]->listplayers(cout);
                            int torlendo;
                            cin >> torlendo;
                            csapatok[wteam]->removeplayer(torlendo);
                            break;
                        case (3):
                            cout << "Adja meg az edzo nevet:";
                            char enev[100];
                            cin >> enev;
                            csapatok[wteam]->addcoach(enev);
                            break;
                        case (4) :
                            if (strcmp(csapatok[wteam]->classname(), "Basketball") == 0) {
                                cout << "Kerem adja meg a Pom-Pom lanyok szamat:";
                                int pomcnt;
                                cin >> pomcnt;
                                ((Basketball *) csapatok[wteam])->setpompomcnt(pomcnt);
                            } else if (strcmp(csapatok[wteam]->classname(), "Football") == 0) {
                                cout << "Kerem adja meg a Masodedzo nevet:";
                                char masodedzo[100];
                                cin >> masodedzo;
                                String stringmasodedzo(masodedzo);
                                ((Football *) csapatok[wteam])->setSecondcoach(stringmasodedzo);
                            } else if (strcmp(csapatok[wteam]->classname(), "Handball") == 0) {
                                cout << "Kerem adja meg az eves tamogatas osszeget:";
                                int tamogatas;
                                cin >> tamogatas;
                                ((Handball *) csapatok[wteam])->setYearlybonus(tamogatas);
                            }
                            break;
                        case (5):
                            submenu = true;
                            break;
                        default:
                            cout << "Valasszon opciot:";
                            cout
                                    << "1. Jatekos hozzaadasa\n\t2.Jatekos torlese\n\t3.Edzo hozzaadasa\n\t4. Egyedi ertek beallitasa\n\t5.Elozo menu\n";
                    }
                }
                break;
        }
            case (3): {
                csapatok.listnames();
                cout << "Irja be a torlendo csapat szamat:";
                int torlendo;
                cin >> torlendo;
                csapatok.removeteam(torlendo);
                break;
            }
            case (4): {
                csapatok.listnames();
                break;
            }
            case (5):
                exit=true;
                break;
            default:
                cout << "Opcio kivalasztasa(irja be a szamot):\n";
                cout
                        << "\t1. Csapat hozzaadasa\n\t2. Csapat kezelese\n\t3. Csapat torlese\n\t4. Csapatok listazasa\n\t5. Kilepes"
                        << endl;
        }
    }

#endif //Felhasználói mód

    return 0;
}


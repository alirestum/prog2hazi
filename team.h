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


/*! @brief A Team osztály.
 *
 * String tömbben tárolja egy csapat játékosainak nevét.
 * További adattagjaiban egy String formájában a csapat edzőjének a nevét,
 * illetve a csapat nevét is. Tárolja a játékosok számát is unsigned int-ként
 *
 */
class Team {

protected:
    String *players;
    size_t playercnt;
    String coach;
    String name;
public:
    /*!
     * @brief A default konstruktor
     *
     * NULL pointert állít be a String tömbnek, 0-ra állítja a játékosok számát.
     * Az edző és a csapat nevét létrehozza egy üres String-ként
     */
    Team() : players(NULL), playercnt(0), coach(""), name("") {}

    /*!
     * @brief Edző ill. csapatnévvel hívható konstruktor.
     *
     * A játékosok tömbje Null pointer, a darabszám nulla, az edző és a csapat nevét meg lehet adni.
     * @param coachname A csapat edzőjének a neve
     * @param tname A csapat neve
     */
    Team(String coachname, String tname) : players(NULL), playercnt(0), coach(coachname), name(tname) {}

    /*!
     * @brief Másoló konstruktor
     * @param rteam Másolandó osztály
     */
    Team(const Team &rteam);

    /*!
     * @brief Játékos hozzáadása a csapathoz
     * @param newplayer Játékos neve akit hozzáadunk
     */
    void addplayer(const String &newplayer);

    /*!
     * @brief Játékos eltávolítása a csapatból
     * @param idx A játékos index-e a tömbben.
     */
    void removeplayer(size_t idx);

    /*!
     * @brief Edző beállítása
     * @param coach Edző nevét tartalmazó String
     */
    void addcoach(const String coach);


    /*!
     * @brief A csapat játékosai számának lekérdezése
     * @return A játékos tömb mérete
     */
    const int size() { return playercnt; };

    /*!
     * @brief Egyenlőség operátor
     * @param team A csapat amivel egyenlővé tesszük a baloldalt
     * @return Az egyenlővé tett csapat
     */
    Team &operator=(const Team &team);


    /*!
     * @brief Az osztály nevét adja vissza C string-ként
     * @return Az osztály neve
     */
    virtual const char *classname();

    //virtual int getpompomcnt() const = 0;

    //virtual void setpompomcnt(int pompomcnt) =0;

    /*!
     * @brief Indexelő operátor
     * @param index Adott elem indexe
     * @return A játékos tömb adott indexű tagja
     */
    const char *operator[](size_t index) const;

    /*!
     * @brief Virtuális destruktor
     */
    virtual ~Team() { delete[] players; }

    /*!
     * @brief Edző nevének lekérdezése
     * @return Edző neve
     */
    const char *getCoach() const;

    /*!
     * @brief Csapat nevének lekérdezése
     * @return Csapat neve
     */
    const char *getName() const;

    /*!
     * @brief Csapat nevének beállítása
     * @param name A beállítandó név
     */
    void setName(const String &name);

    /*!
     * @brief A Team osztály kiírása output streamre
     *
     * Egy előre megadott formátumban a csapat minden információját(játékosok, edző, csapatnév)
     * kilistázza.
     * @param os Az output stream
     */
    virtual void list(std::ostream& os){
        os << "Team: " << this->getName() << "\n";
        os << "\tJatekosok:\n";
        for (size_t i = 0; i < this->playercnt; i++)
            os << "\t\t" << players[i] << "\n";
        os << "\tEdzo:\n\t" << this->getCoach() << "\n";
        //   os << "\tPomPomCnt:\n\t" << this->getpompomcnt();


    }

    /*!
     * @brief Csapat játékosainak kilistázása az output streamre
     * @param os Az output stream
     */
    void listplayers(std::ostream& os){
        for (size_t i = 0; i < playercnt; i++)
            os << i << ". " << players[i] << "\n";
    }


};

/*!
 * @brief Inserter operátor, kiirja a streamre a Team osztályt
 * @param os Output stream
 * @param out Kiirandó csapat
 * @return
 */
ostream &operator<<(ostream &os, Team &out);


#endif //PROG2HAZI_TEAM_H

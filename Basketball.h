//
// Created by Restum Ali on 2019-04-15.
//

#ifndef PROG2HAZI_BASKETBALL_H
#define PROG2HAZI_BASKETBALL_H


#include "team.h"
#include "string.h"
#include <iostream>

/*!
 * @brief Basketball osztály
 *
 * Örökli a Team osztály adattagjait, hozzáad egy sajátot, a Pom-Pom lányok számát
 * tárolja egészként.
 */
class Basketball : public Team {
private:
    int pompomcnt;

public:
    /*!
     * @brief Alapértelmezett konstruktor
     *
     * Meghívja a Team osztály alapértelmezett konstruktorát, a Pom-Pom lányok számát 0-ra állítja
     */
    Basketball() : Team(), pompomcnt(0) {}

    /*!
     * @brief Edző, csapatnév, és PomPom darabszámmal hívható konstruktor
     *
     * Meghívja a Team osztály megfelelő konstruktorát, a megadott értékre állítja a Pom-Pom lányok számát
     * @param coachname A beállítandó név az edzőnek
     * @param cnt A beállítandó név a Pom-Pom lányok számának
     * @param tname A beállítandó név a csapatnak
     */
    Basketball(String coachname, int cnt, String tname) : Team(coachname, tname), pompomcnt(cnt) {}

    /*!
     * @brief Pom-Pom lányok számának lekérdezése
     * @return Pom-Pom lányok száma
     */
    int getpompomcnt() const;

    /*!
     * @brief Pom-Pom lányok számának beállítása
     * @param pompomcnt A beállítandó érték
     */
    void setpompomcnt(int pompomcnt);

    /*!
     * @brief Másoló konstruktor
     * @param rhs A másolandó Basketball osztály
     */
    Basketball(const Basketball &rhs);

    /*!
     * @brief Egyenlőség operátor
     * @param rhs A Basketball osztály amivel egyenlővé tesszük a baloldalt
     * @return Az egyenlővé tett Basketball osztály
     */
    Basketball &operator=(const Basketball &rhs);

    /*!
     * @brief A Basketball osztály kiírása output streamre
     *
     * Egy előre megadott formátumban a csapat minden információját(játékosok, edző, csapatnév, Pom-Pom lányok száma)
     * kilistázza.
     * @param os Az output stream
     */
    void list(std::ostream& os){
        os << "Team: " << this->getName() << "\n";
        os << "\tJatekosok:\n";
        for (size_t i = 0; i < this->playercnt; i++)
            os << "\t\t" << players[i] << "\n";
        os << "\tEdzo:\n\t" << this->getCoach() << "\n";
        os << "\tPomPomCnt:\n\t" << this->getpompomcnt();


    }

    /*!
     * @brief Az osztály nevét adja vissza C string-ként
     * @return Az osztály neve
     */
    const char *classname();

};

/*!
 * @brief Inserter operátor, kiirja a streamre a Basketball osztályt
 * @param os Output stream
 * @param out Kiirandó csapat
 * @return
 */
std::ostream &operator<<(std::ostream &os, Basketball &out);


#endif //PROG2HAZI_BASKETBALL_H

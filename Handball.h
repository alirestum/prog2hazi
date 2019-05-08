//
// Created by Restum Ali on 2019-04-19.
//

#ifndef PROG2HAZI_HANDBALL_H
#define PROG2HAZI_HANDBALL_H

#include "string5.h"
#include "team.h"
#include <iostream>

/*!
 * @brief Handball osztály osztály
 *
 * Örökli a Team osztály minden adattagját, illetve hozzáad egy sajátot,
 * a csapat éves támogatását rátolja egészként.
 */
class Handball : public Team {
private:
    int yearlybonus;
public:
    /*!
     * @brief Alapértelmezett konstruktor
     *
     * A Team osztály alapértelmezett konstruktorát hívja a támogatást 0-ra állítja
     */
    Handball() : Team(), yearlybonus(0) {}

    /*!
     * @brief Edző, csapatnév, és támogatás számával hívható konstruktor
     * @param coachname A beállítandó edző név
     * @param tname A beállítandó csapatnév
     * @param bonus A beállítandó támogatás mértéke
     */
    Handball(String coachname, String tname, int bonus) : Team(coachname, tname), yearlybonus(bonus) {}

    /*!
     * @brief Edző és csapatnévvel hívható konstruktor
     * @param coachname A beállítandó edző név
     * @param tname A beállítandó csapatnév
     */
    Handball(String coachname, String tname) : Team(coachname, tname), yearlybonus(0) {}

    /*!
     * @brief Támogatás lekérdezése
     * @return Támogatás mennyisége
     */
    int getYearlybonus() const;

    /*!
     * @brief Támogatás beállítása
     * @param yearlybonus A beállítandó támogatás
     */
    void setYearlybonus(int yearlybonus);

    /*!
     * @brief Másoló konstruktor
     * @param rhs A lemásolandó Handball osztály
     */
    Handball(const Handball &rhs);

    /*!
     * @brief Egyenlőség operátor
     * @param rhs A Handball osztály amivel egynlővé szeretnénk tenni a baloldalt
     * @return Az egyenlővé tett Handball osztály
     */
    Handball &operator=(const Handball &rhs);

    /*!
     * @brief A Handball osztály kiírása output streamre
     *
     * Egy előre megadott formátumban a csapat minden információját(játékosok, edző, csapat, másodedző név)
     * kilistázza.
     * @param os Az output stream
     */
    void list(std::ostream &os);

    /*!
     * @brief Az osztály nevét adja vissza C string-ként
     * @return Az osztály neve
     */
    const char *classname();

};


/*!
 * @brief Inserter operátor, kiirja a streamre a Handball osztályt
 * @param os Output stream
 * @param out Kiirandó csapat
 * @return
 */
std::ostream &operator<<(std::ostream &os, Handball &out);

#endif //PROG2HAZI_HANDBALL_H

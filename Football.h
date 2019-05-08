//
// Created by Restum Ali on 2019-04-15.
//

#ifndef PROG2HAZI_FOOTBALL_H
#define PROG2HAZI_FOOTBALL_H

#include "team.h"
#include "string5.h"
#include <iostream>

/*!
 * @brief Football osztály
 *
 * Örökli a Team osztály minden adattagját, illetve hozzáad egy sajátot,
 * a másodedzőt. Egy Stringben tárolja a másodedzőt
 */
class Football: public Team{
private:
    String secondcoach;
public:
    /*!
     * @brief Alapértelmezett konstruktor
     *
     * A Team osztály konstruktorát hívja paraméter nélkül, a másodedzőt üres Stringre állítja
     */
    Football(): Team(), secondcoach(""){}

    /*!
     * @brief Edző és csapatnévvel hívható konstruktor
     *
     * A Team osztály konstruktorát hívja az edző ill. a csapat nevével, a másodedzőt üres Stringre állítja.
     * @param coachname A beállítandó név az edzőnek
     * @param tname A beállítandó név a csapatnak
     */
    Football(String coachname, String tname) : Team(coachname, tname), secondcoach("") {}

    /*!
     * @brief Mindkét edző, ill. a csapat nevével hívható konstruktor
     *
     * A Team osztály konstruktorát hívja az edző illetve a csapat nevével, majd a másodedzőnek beállítja a megadott Stringet
     * @param coach A beállítandó név az edzőnek
     * @param secondcoach A beállítandó név a másodedzőnek
     * @param tname A beállítandó név a csapatnak
     */
    Football(String coach, String secondcoach, String tname): Team(coach, tname), secondcoach(secondcoach){}

    /*!
     * @brief Másoló konstruktor
     * @param rhs A másolandó Football osztály
     */
    Football(const Football& rhs);

    /*!
     * @brief Egyenlőség operátor
     * @param rhs A Football osztály amivel egyenlővé szeretnénk tenni a baldolalt
     * @return Az egyenlővé tett Football osztály
     */
    Football& operator=(const Football& rhs);

    /*!
     * @brief Másodedző lekérdezése
     * @return Másodedző neve C string-ként
     */
    const char *getSecondcoach() const;

    /*!
     * @brief Másodedző beállítása
     * @param secondcoach A beállítandó név a másodedzőnek
     */
    void setSecondcoach(const String &secondcoach);

    /*!
     * @brief A Football osztály kiírása output streamre
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
 * @brief Inserter operátor, kiirja a streamre a Football osztályt
 * @param os Output stream
 * @param out Kiirandó csapat
 * @return
 */
std::ostream& operator<<(std::ostream& os, Football& out);

#endif //PROG2HAZI_FOOTBALL_H

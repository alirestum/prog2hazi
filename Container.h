//
// Created by Restum Ali on 2019-04-19.
//

#ifndef PROG2HAZI_CONTAINER_H
#define PROG2HAZI_CONTAINER_H

#include "team.h"
#include <iostream>
#include <fstream>

/*!
 * @brief Container osztály
 *
 * Team ősosztály pointereket tárol, így valosítja meg a heterogén kollekciót
 */
class Container {
private:
    Team **teams;
    size_t teamcnt;
public:
    /*!
     * @brief Alapértelmezett konstruktor
     *
     * A tömböt nullpointer-re állítja a csapatok számát pedig 0-ra
     */
    Container() : teams(nullptr), teamcnt(0) {}

    /*!
     * @brief Visszaadja a tárolóban tárolt elemek számát
     * @return Az elemek száma
     */
    const size_t size() { return teamcnt; };

    /*!
     * @brief Indexelő operátor
     * @param idx Melyik elemet szeretnénk visszakapni
     * @return A megadott elem
     */
    Team *operator[](size_t idx);

    /*!
     * @brief Indexelő operátor
     * @param idx Melyik elemet szeretnénk visszakapni
     * @return A megadott elem
     */
    const Team *operator[](size_t idx) const;

    /*!
     * @brief Csapat hozzáadása a tömbhöz
     * @param newteam Az új csapatra mutató pointer
     */
    void addteam(Team *newteam);

    /*!
     * @brief Csapat törlése a tömbből
     * @param idx Hányadik csapatot szeretnénk törölni
     */
    void removeteam(size_t idx);


    /*!
     * @brief Tömbben lévő csapat neveinek a kilistázása
     */
    void listnames();

    /*!
     * @brief Destruktor
     */
    ~Container();

};


std::ostream &operator<<(std::ostream &os, Container &out);

#endif //PROG2HAZI_CONATINER_H

#ifndef STRING_H
#define STRING_H



#define ELKESZULT 6



#include <iostream>


/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 *
 */
class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:


    /// Paraméter nélküli konstruktor:
    String() : pData(NULL), len(0) {}

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char *c_str() const { return pData == NULL ? "\0" : pData; }

    /*!
     * @brief Desktruktor
     */
    ~String() { delete[] pData; }

    /*!
     * @brief Karakterrel hívható konstruktor
     * @param c A kivánt karakter
     */
    String(char c);

    /*!
     * @brief C-string-el hívható konstruktor
     * @param s az adott c string
     */
    String(const char *s);

    /*!
     * @brief Másoló konstruktor
     * @param rhs A másolni kívánt String
     */
    String(const String &rhs);

    /*!
     * @brief Egyenlőség operátor
     * @param rhs Amivel egyenlővé szeretnénk tenni a baloldalt
     * @return Az egyenlővé tett String
     */
    String &operator=(const String &rhs);

};

std::ostream &operator<<(std::ostream &os, const String &out);

#endif

/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(char c){
    this->len=1;
    this->pData=new char[2];
    this->pData[0]=c;
    this->pData[1]='\0';
}

String::String(const char *s){
    this->len=strlen(s);
    this->pData=new char [this->len+1];
    strcpy(this->pData,s);
}
/// Másoló konstruktor: String-ből készít (createString)
String::String(const String& rhs){
    char *p = new char [strlen(rhs.pData)+1];
    len=rhs.len;
    strcpy(p, rhs.pData);
    this->pData=p;
}

/// Destruktor (disposeString)

/// operator=
String& String::operator=(const String& rhs){
    if (pData == rhs.pData)
        return *this;
    delete [] pData;
    pData=new char [strlen(rhs.pData)+1];
    len=rhs.len;
    strcpy(pData, rhs.pData);
    //pData[strlen(rhs.pData)+1]='\0';
    return *this;
}


std::ostream& operator<<(std::ostream &os, const String& out) {
    os << out.c_str();
    return os;
}
/*String::String& operator=(const String& rhs){
    this->pData=rhs.pData;
    this->len=rhs.len;
    return *this;
}*/
/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!


/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)

/// << operator, ami kiír az ostream-re


/// >> operátor, ami beolvas az istream-ről egy szót

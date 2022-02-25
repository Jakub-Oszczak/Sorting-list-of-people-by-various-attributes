#ifndef LOSOWANIE_H
#define LOSOWANIE_H
#include <string>
#include <iostream>
#include "lista.h"

using namespace std;

struct Dane{                //struktura, która pomaga przechować informacje o studencie w polu tablicy dynamicznej
    string imie;
    string nazwisko;
    int wiek;
    double sr_ocen;
    char plec;
};

class Losowanie
{
public:
    Studenci *glowa;
    Losowanie();
    void losujPoWieku();
    void losujPoSr_ocen();
    void losujPoPlci();
};

#endif // LOSOWANIE_H

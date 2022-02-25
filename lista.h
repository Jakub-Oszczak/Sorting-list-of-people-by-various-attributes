#ifndef LISTA_H
#define LISTA_H
#include "student.h"

struct Studenci{                             //struktura potrzebna do zrobienia listy studentów
    Student student;
    Studenci *nast;
};

class Lista
{
public:
    Studenci *glowa;
    Studenci *ogon;
    Lista();
    void dodajStudenta(Studenci *n);
    void usunStudenta(string imie, string nazwisko);
    void wypiszListeStudentow();
};

#endif // LISTA_H

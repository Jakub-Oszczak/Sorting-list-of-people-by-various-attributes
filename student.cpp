#include "student.h"

Student::Student()
{

}
Student::Student(string imie, string nazwisko){       //konstruktor
    this->imie=imie;
    this->nazwisko=nazwisko;
}
void Student::ustawWiek(int &wiek){                   //ustawia wiek studenta
    this->wiek=wiek;
}
void Student::ustawSr_ocen(double &sr_ocen){          //ustawia średnią ocen studenta
    this->sr_ocen=sr_ocen;
}
void Student::ustawPlec(char &plec){                  //ustawia płeć studenta
    this->plec=plec;
}

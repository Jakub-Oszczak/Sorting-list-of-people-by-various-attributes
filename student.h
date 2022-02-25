#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{    
public:
    string imie, nazwisko;
    char plec;
    int wiek;
    double sr_ocen;
    Student();
    Student(string imie, string nazwisko);
    void ustawWiek(int &wiek);
    void ustawSr_ocen(double &sr_ocen);
    void ustawPlec(char &plec);
};

#endif // STUDENT_H

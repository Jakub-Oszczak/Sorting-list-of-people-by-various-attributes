#include <iostream>
#include "lista.h"
#include "student.h"
#include "losowanie.h"

using namespace std;

Studenci konfiguracjaStudenta(string a,string b,int c,char d,double e){   //Studenci to struktura potrzebna do stworzenia listy studentów, sama funkcja wpierw tworzy obiekt klasy Student
   Student student1(a,b);                                                 // i ustawia wartości pól takie jak imie, nazwisko, wiek, pleć, średnia ocen. Następnie tworzy obiekt struktury Studenci
   student1.ustawWiek(c);                                                 // i przypisuje polu "student" stworzony wcześniej obiekt klasy Student z wypełnionymi polami.
   student1.ustawPlec(d);                                                 //Na koniec zwraca stwrzony obiekt strukturalny
   student1.ustawSr_ocen(e);
   Studenci *nowystudent=new Studenci;
   nowystudent->student=student1;
   return *nowystudent;
}

int main()
{
    string a,b;
    int c,opcja;
    char d;
    double e;
    Lista listastudentow;
    Losowanie losowanie;
    for(int i=40;i<42;i++){                                                                //tutaj tworzymy pierwszych dwóch "obowiązkowych" studentów, żeby było sposród czego losować.
        if(i==40){                                                                         //podajemy po koleji informacje o studencie, następnie tworzy się pomocniczy obiekt struktury Studenci
          cout<<"Prosze podac imie i nazwisko pierwszego studenta"<<endl<<"Imie: ";        //pod który przypisujemy obiekt strukturalny, który zwraca wcześniej opisana funkcja. Na koniec
        }                                                                                  //używamy metody klasy Lista, która dodaje nam do listy studentów naszego studenta.
        if(i==41){
          cout<<endl<<"Prosze podac imie i nazwisko drugiego studenta"<<endl<<"Imie: ";
        }
        cin>>a;
        cout<<"Nazwisko: ";
        cin>>b;
        cout<<"Teraz prosze podac wiek, plec(k/m), srednia ocen "<<endl<<"Wiek: ";
        cin>>c;
        while(!(c>18 && c<100)){
            cout<<"prosze podac odpowiedni wiek ( <18,100> )"<<endl;
            cout<<"Wiek: ";
            cin>>c;
        }
        cout<<"Plec: ";
        cin>>d;
        while(!(d=='k' || d=='K' || d=='m' || d=='M')){
            cout<<"prosze podac poprawna odpowiedz(k/m)"<<endl;
            cout<<"Plec: ";
            cin>>d;
        }
        cout<<"Srednia ocen: ";
        cin>>e;
        while(!(e>=2.00 && e<=5.00)){
            cout<<"prosze podac odpowiednia srednia ( <2.00,5.00> )"<<endl;
            cout<<"Srednia ocen: ";
            cin>>e;
        }
        Studenci *temp= new Studenci;
        *temp=konfiguracjaStudenta(a,b,c,d,e);
        listastudentow.dodajStudenta(temp);
    }

    do{                                                                                                  //wypisanie listy czynności, które użytkownik może zrobić
    cout<<endl<<"Teraz dostepnych jest kilka opcji"<<endl<<"(1) Dodaj studenta"<<endl<<
          "(2) Usun studenta"<<endl<<"(3) Pokaz liste studentow"<<endl<<"(4) Losuj po wieku"<<endl<<
          "(5) Losuj po sredniej ocen"<<endl<<"(6) Losuj po plci"<<endl<<"(7) Zakoncz"<<endl;
    cout<<"aby wybrac opcje wpisz numer z nawiasu"<<endl<<"Wybieram opcje numer: ";

    cin>>opcja;
    cout<<endl;

    switch (opcja) {                                                              //tutaj z wykorzystaniem funkcji switch case program wykonuje odpowiednią czynność, wcześniej wybraną przez użytkownika
    case 1:                                                                       // case 1 - ten sam schemat dodawania studentów co przy pierwszych dwóch "obowiązkowych" studentach
    {
        string a,b;
        int c;
        char d;
        double e;
        cout<<"imie: ";
        cin>>a;
        cout<<"Nazwisko: ";
        cin>>b;
        cout<<"wiek: ";
        cin>>c;
        while(!(c>18 && c<100)){
            cout<<"prosze podac odpowiedni wiek ( <18,100> )"<<endl;
            cout<<"Wiek: ";
            cin>>c;
        }
        cout<<"Plec: ";
        cin>>d;
        while(!(d=='k' || d=='K' || d=='m' || d=='M')){
            cout<<"prosze podac poprawna odpowiedz(k/m)"<<endl;
            cout<<"Plec: ";
            cin>>d;
        }
        cout<<"Srednia ocen: ";
        cin>>e;
        while(!(e>=2.00 && e<=5.00)){
            cout<<"prosze podac odpowiednia srednia ( <2.00,5.00> )"<<endl;
            cout<<"Srednia ocen: ";
            cin>>e;
        }
        Studenci *temp=new Studenci;
        *temp=konfiguracjaStudenta(a,b,c,d,e);
        listastudentow.dodajStudenta(temp);
        break;
    }

    case 2:                                                                                 //case 2 - usuwa studenta przeszukując liste studentów po imieniu i nazwisku
    {
        string imie, nazwisko;
        cout<<"Podaj imie i nazwisko studenta, ktorego chcesz usunac z listy"<<endl;
        cout<<"imie: ";
        cin>>imie;
        cout<<"nazwisko: ";
        cin>>nazwisko;
        listastudentow.usunStudenta(imie,nazwisko);
        break;
    }
    case 3:                                                                                 //case 3 - wypisuje liste studentów
        listastudentow.wypiszListeStudentow();
        break;

    case 4:                                                                                 //case 4 - rozpoczyna losowanie kolejności studentów po wieku
        losowanie.glowa=listastudentow.glowa;
        losowanie.losujPoWieku();
        break;

    case 5:                                                                                 //case 5 - rozpoczyna losowanie kolejności studentów po średniej ocen
        losowanie.glowa=listastudentow.glowa;
        losowanie.losujPoSr_ocen();
        break;

    case 6:                                                                                 //case 6 - rozpoczyna losowanie kolejności studentów po płci
        losowanie.glowa=listastudentow.glowa;
        losowanie.losujPoPlci();
        break;

    case 7:                                                                                 //case 7 - kończy działanie programu
        opcja=100;
        break;

    }

}while(opcja!=100);

return 0;
}

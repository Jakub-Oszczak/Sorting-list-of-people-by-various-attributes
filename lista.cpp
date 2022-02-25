#include "lista.h"
#include<iostream>

Lista::Lista()
{
    glowa=nullptr;
    ogon=nullptr;
}

void Lista::dodajStudenta(Studenci *n){         //metoda dodaje studenta do listy
    if(glowa==nullptr){                  //przypadek gdyby lista była pusta
        glowa=n;
        ogon=n;
        ogon->nast=nullptr;
    }
    else{                                //gdy lista nie jest pusta dodajemy nowego studenta na koniec listy
        ogon->nast=new Studenci;
        ogon=ogon->nast;
        ogon->student=n->student;
        ogon->nast=nullptr;
    }
    }
void Lista::usunStudenta(string imie, string nazwisko){          //metoda usuwa wybranego studenta, rozważa trzy przypadki: kiedy usuwany student jest głową listy, ogonem listy lub jest w środku listy
    Studenci *w=glowa;
    Studenci *poprzedni= new Studenci;
    while(w!=nullptr){
        if(w->student.imie==imie && w->student.nazwisko==nazwisko){
            if(w==glowa){
                glowa=w->nast;
                delete w;
            }
            else if(w==ogon){
               ogon=poprzedni;
               delete w;
               ogon->nast=nullptr;
            }
            else{
                poprzedni->nast=w->nast;
                delete w;
            }
        }
        poprzedni=w;
        w=w->nast;
    }
}
void Lista::wypiszListeStudentow(){                             //metoda wypisuje liste studentów wraz z informacjami o nich
    Studenci *w=glowa;
    while(w!=nullptr){
        cout<<w->student.imie<<" "<<w->student.nazwisko<<endl;
        cout<<'\t'<<"plec: "<<w->student.plec<<endl;
        cout<<'\t'<<"wiek: "<<w->student.wiek<<endl;
        cout<<'\t'<<"srednia ocen: "<<w->student.sr_ocen<<endl;
        w=w->nast;
    }
}

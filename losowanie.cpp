#include "losowanie.h"

Losowanie::Losowanie()
{

}

void Losowanie::losujPoWieku(){
    Studenci *w=glowa;
    Studenci *p=glowa;
    int k=0,i=0;
    while(w!=nullptr){            //zliczanie ilości studentów na liście
        k++;
        w=w->nast;
    }
    Dane *a=nullptr;              //stworzenie dynamicznej tablicy typu Dane, dzięki temu każde pole tablicy reprezentuje studenta i przechowuje informacje o nim (wiek, pleć, imie...)
    a=new Dane[k];

    while(p!=nullptr){                          //wypełnienie tablicy studentami (wypełniam jedynie dane potrzebne do losowania)
        a[i].imie=p->student.imie;
        a[i].nazwisko=p->student.nazwisko;
        a[i].wiek=p->student.wiek;
        i++;
        p=p->nast;
    }

    for(int i=0; i<k-1; i++){                   //algorytm sortujący tablice (sortowanie przez wybieranie)
        int i_max=i;
        for(int j=i+1; j<k; j++)
            if(a[j].wiek > a[i_max].wiek)
                i_max=j;
        Dane schowek=a[i];
        a[i]=a[i_max];
        a[i_max]=schowek;
    }

    cout<<"Wynik losowania:"<<endl;                                 //wypisanie wyników losowania
    for(int i=0; i<k; i++){
        cout<<i+1<<". "<<a[i].imie<<" "<<a[i].nazwisko<<endl;
    }
}

void Losowanie::losujPoSr_ocen(){             //taki sam schemat działania jak w poprzedniej metodzie
    Studenci *w=glowa;
    Studenci *p=glowa;
    int k=0,i=0;
    while(w!=nullptr){
        k++;
        w=w->nast;
    }
    Dane *a=nullptr;
    a=new Dane[k];

    while(p!=nullptr){
        a[i].imie=p->student.imie;
        a[i].nazwisko=p->student.nazwisko;
        a[i].sr_ocen=p->student.sr_ocen;
        i++;
        p=p->nast;
    }

    for(int i=0; i<k-1; i++){
        int i_max=i;
        for(int j=i+1; j<k; j++)
            if(a[j].sr_ocen > a[i_max].sr_ocen)
                i_max=j;
        Dane schowek=a[i];
        a[i]=a[i_max];
        a[i_max]=schowek;
    }

    cout<<"Wynik losowania:"<<endl;
    for(int i=0; i<k; i++){
        cout<<i+1<<". "<<a[i].imie<<" "<<a[i].nazwisko<<endl;
    }
}

void Losowanie::losujPoPlci(){                                   //taki sam schemat działania jak w poprzedniej metodzie
    Studenci *w=glowa;
    Studenci *p=glowa;
    int k=0,i=0;
    while(w!=nullptr){
        k++;
        w=w->nast;
    }
    Dane *a=nullptr;
    a=new Dane[k];

    while(p!=nullptr){
        a[i].imie=p->student.imie;
        a[i].nazwisko=p->student.nazwisko;
        a[i].plec=p->student.plec;
        i++;
        p=p->nast;
    }

    for(int i=0; i<k-1; i++){
        int i_min=i;
        for(int j=i+1; j<k; j++)
            if(a[j].plec < a[i_min].plec)
                i_min=j;
        Dane schowek=a[i];
        a[i]=a[i_min];
        a[i_min]=schowek;
    }

    cout<<"Wynik losowania:"<<endl;
    for(int i=0; i<k; i++){
        cout<<i+1<<". "<<a[i].imie<<" "<<a[i].nazwisko<<endl;
    }
}

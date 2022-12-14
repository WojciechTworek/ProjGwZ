#include "plansza.h"

void Plansza::alokuj(){
    tab = new bool*[m_kolumny];
    tab[0] = new bool[m_kolumny*m_wiersze];

    for(int i = 1; i<m_wiersze; i++){
        tab[i] = &tab[0][i*m_kolumny];
    }
}

void Plansza::dealokacja(){
    delete[] tab[0];
    delete[] tab;
    tab=nullptr;
}

Plansza::Plansza(int wiersze,int kolumny){
    m_kolumny = kolumny; m_wiersze = wiersze;
    alokuj();
}

int Plansza::getSzerokosc(){return m_kolumny;}
int Plansza::getWysokosc(){return m_wiersze;}
int Plansza::getIlkom(){return m_kolumny*m_wiersze;}

void Plansza::setWielkosc(int wiersze,int kolumny){

}

Plansza::~Plansza(){
    for (int i = 0; i < m_wiersze; i++) {
         delete[] tab[i];
       }
       delete[] tab;
}


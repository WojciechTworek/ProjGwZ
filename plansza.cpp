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

int Plansza::getIlkolumn(){return m_kolumny;}
int Plansza::getIlwierszy(){return m_wiersze;}


void Plansza::setWielkosc(int wiersze,int kolumny){
    Plansza nowa_plansza(wiersze,kolumny);

        for(int i = 0;i<wiersze;i++){
            for(int j = 0;j<kolumny;j++){
                nowa_plansza.tab[i][j] = this->tab[i][j];
            }
        }

        this->dealokacja();
        this->tab=nowa_plansza.tab;
}

int Plansza::size(){
    return (m_kolumny*m_wiersze);
}

void Plansza::clear(){
    for (int i = 0; i < m_wiersze; i++) {
        delete[] tab[i];
    }
}

Plansza::~Plansza(){
    delete[] tab[0];
    delete[] tab;
}

bool* Plansza::operator[](int i){
    return this->tab[i];
}

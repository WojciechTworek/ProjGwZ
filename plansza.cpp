#include "plansza.h"

void Plansza::alokuj(){
    tab = new bool*[m_wiersze];
    for(int i = 0; i<m_wiersze; i++){
        tab[i] = new bool[m_kolumny];
    }
}

void Plansza::dealokacja(){
    for(int i = 0; i<m_wiersze; i++){
        delete[] tab[i];
    }
    delete[] tab;
    tab=nullptr;
}

Plansza::Plansza(int wiersze,int kolumny){
    m_kolumny = kolumny; m_wiersze = wiersze;
    alokuj();
}

void Plansza::setPlanszaAll(int wiersze,int kolumny){
    m_kolumny = kolumny; m_wiersze = wiersze;
    alokuj();
}

int Plansza::getIlkolumn(){return m_kolumny;}
int Plansza::getIlwierszy(){return m_wiersze;}

void Plansza::setWielkosc(int wiersze,int kolumny){
    Plansza nowa_plansza(wiersze,kolumny);

        for(int i = 0;i<wiersze;i++){
            if(this->getIlwierszy()>i){
            for(int j = 0;j<kolumny;j++){
                if(this->getIlkolumn()>j){
                    nowa_plansza.tab[i][j] = this->tab[i][j];
                }
                else{
                    nowa_plansza.tab[i][j] = 0;
                }
            }
            }
            else{
                for(int j = 0;j<kolumny;j++){
                     nowa_plansza.tab[i][j] = 0;
                }
            }
        }

        this->dealokacja();
        setIlwierszy(wiersze);
        setIlkolumn(kolumny);
        this->tab=nowa_plansza.tab;
        nowa_plansza.tab=nullptr;
}

int Plansza::size(){
    return (m_kolumny*m_wiersze);
}

void Plansza::clear(){
    for (int i = 0; i < m_wiersze; i++) {
        for(int j = 0;j<m_kolumny;j++){
            tab[i][j] = 0;
        }
    }
}

Plansza::~Plansza(){
    if(tab!=nullptr){
        delete[] tab[0];
        delete[] tab;
    }
}

bool* Plansza::operator[](int i){
    return this->tab[i];
}

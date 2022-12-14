#include "gra.h"

Gra::Gra(int i_wiersze, int i_kolumny):plansza(i_wiersze, i_kolumny){}

    bool Gra::getCzy_losowac(){return czy_losowac;}

void Gra::inicjalizacjaStartowa(){
if(getCzy_losowac())
     for (int i = 0; i < plansza.getIlwierszy(); i++) {
       for (int j = 0; j < plansza.getIlkolumn(); j++) {
             plansza[i][j] = rand()/RAND_MAX;
       }
     }
    else{
       for (int i = 0; i < plansza.getIlwierszy(); i++) {
         for (int j = 0; j < plansza.getIlkolumn(); j++) {
             plansza[i][j] = 0;
         }
       }
    }
}

int Gra::ZliczSasiadow(int x, int y) {
    int liczba_sasiadow= 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {continue;}
            int pomoc_x = x + i;
            int pomoc_y = y + j;
            if (pomoc_x >= 0 && pomoc_x < plansza.getIlkolumn()&& pomoc_y >= 0 && pomoc_y < plansza.getIlwierszy()) {
                 if (plansza[pomoc_x ][pomoc_y ]) {liczba_sasiadow++;}
            }
        }
    }
    return liczba_sasiadow;
}

void Gra::przetrwanie(){
    for (int i = 0; i < plansza.getIlwierszy(); i++) {
      for (int j = 0; j < plansza.getIlkolumn(); j++) {
         if(ZliczSasiadow(plansza.getIlkolumn(),plansza.getIlwierszy()) < 2 || plansza.getIlkolumn(),plansza.getIlwierszy() > 3){
             plansza[i][j] = 0;
         }
         if((plansza.getIlkolumn(),plansza.getIlwierszy()) == 3 && plansza[i][j] == 0){
             plansza[i][j] = 1;
         }
      }
    }
}

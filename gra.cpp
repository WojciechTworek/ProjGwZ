#include "gra.h"

Gra::Gra()
{}

    int Gra::getRozmiar_planszy(){return rozmiar_planszy;}
    bool Gra::getCzy_losowac(){return czy_losowac;}
    int Gra::getSzerokosc(){return kol;}
    int Gra::getWysokosc(){return wie;}

void Gra::inicjalizacjaStartowa(Plansza plansza){
//if(getCzy_losowac())
   //  for (int i = 0; i < rozmiar_planszy; i++) {
      // for (int j = 0; j < rozmiar_planszy; j++) {
      //   plansza[i][j] = rand()/RAND_MAX;
     //  }
    // }
   // else{
       for (int i = 0; i < rozmiar_planszy; i++) {
         for (int j = 0; j < rozmiar_planszy; j++) {
             plansza[i][j] = 0;
         }
       }
   // }
}

int Gra::ZliczSasiadow(Plansza &plansza, int x, int y) {
    int liczba_sasiadow= 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {continue;}
            int pomoc_x = x + i;
            int pomoc_y = y + j;
            if (pomoc_x >= 0 && pomoc_x < getSzerokosc()&& pomoc_y >= 0 && pomoc_y < getWysokosc()) {
                 if (plansza[pomoc_x ][pomoc_y ]) {liczba_sasiadow++;}
            }
        }
    }
    return liczba_sasiadow;
 }

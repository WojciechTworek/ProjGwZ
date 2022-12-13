#ifndef GRA_H
#define GRA_H

#include<vector>

class Gra
{   bool czy_losowac = false;
    int rozmiar_planszy = 100;
    int Szerokosc;
    int Wysokosc;
    std::vector<std::vector<bool>> plansza(std::vector<bool>(getRozmiar_planszy()));
public:
    Gra();

    int getRozmiar_planszy(){return rozmiar_planszy;}
    bool getCzy_losowac(){return czy_losowac;}
    int getSzerokosc(){return Szerokosc;}
    int getWysokosc(){return Szerokosc;}



    void inicjalizacjaStartowa(std::vector<std::vector<bool>> plansza) {
     if(getCzy_losowac() == true)
      for (int i = 0; i < rozmiar_planszy; i++) {
        for (int j = 0; j < rozmiar_planszy; j++) {
          plansza[i][j] = rand()/RAND_MAX;
        }
      }
     else{
        for (int i = 0; i < rozmiar_planszy; i++) {
          for (int j = 0; j < rozmiar_planszy; j++) {
              plansza[i][j] = false;
          }
        }
     }
    }

    int ZliczSasiadow(std::vector<std::vector<bool>> &plansza, int x, int y) {
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
};


#endif // GRA_H

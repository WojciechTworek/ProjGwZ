#ifndef GRA_H
#define GRA_H
#include "plansza.h"

#include<vector>

class Gra
{   bool czy_losowac = false;
    int rozmiar_planszy = 100;
    int kol;
    int wie;
    Plansza plansza(int wie, int kol);
public:
    Gra();

    int getRozmiar_planszy();
    bool getCzy_losowac();
    int getSzerokosc();
    int getWysokosc();

    void inicjalizacjaStartowa(Plansza plansza);

    int ZliczSasiadow(Plansza &plansza, int x, int y);
};


#endif // GRA_H

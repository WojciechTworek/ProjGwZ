#ifndef GRA_H
#define GRA_H
#include "plansza.h"
#include<QString>

#include<vector>

class Gra
{   bool czy_losowac = true;
    Plansza plansza;
public:
    Gra(int i_wiersze, int i_kolumny);
    Gra(){}

    bool getCzy_losowac();

    void inicjalizacjaStartowa();

    int ZliczSasiadow(int x, int y);

    void przetrwanie();
    bool czy_zyje(int x, int y);
    void zapis(QString sciezka);
    void odczyt(QString sciezka);
};


#endif // GRA_H

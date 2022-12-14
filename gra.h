#ifndef GRA_H
#define GRA_H
#include "plansza.h"
#include<QString>

#include<vector>

class Gra
{   bool czy_losowac = false;
    Plansza plansza;
public:
    Gra(int i_wiersze, int i_kolumny);

    bool getCzy_losowac();

    void inicjalizacjaStartowa();

    int ZliczSasiadow(int x, int y);

    void przetrwanie();
    void zycie();
    void zapis(QString sciezka);
    void odczyt(QString sciezka);
};


#endif // GRA_H

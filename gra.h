#ifndef GRA_H
#define GRA_H
#include "plansza.h"
#include<QString>

#include<vector>

class Gra
{
    Plansza plansza;
public:
    Gra(int i_wiersze, int i_kolumny);
    Gra(){}

    void inicjalizacjaStartowa();

    int ZliczSasiadow(int x, int y);

    void przetrwanie();
    void wypelnij(int x, int y);
    void zapis(QString sciezka);
    void odczyt(QString sciezka);

    void Czysc();
    int get_ilosc_wierszy();
    int get_ilosc_kolumn();
    bool getCzyZyje(int w,int k);
    void setAll(int wie, int kol);
};


#endif // GRA_H

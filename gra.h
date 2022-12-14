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

    int getRozmiar_planszy();
    bool getCzy_losowac();
    int getSzerokosc();
    int getWysokosc();

    void inicjalizacjaStartowa(std::vector<std::vector<bool>> plansza);

    int ZliczSasiadow(std::vector<std::vector<bool>> &plansza, int x, int y);
};


#endif // GRA_H

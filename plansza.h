#ifndef PLANSZA_H
#define PLANSZA_H


class Plansza
{
private:
    int m_kolumny;
    int m_wiersze;
    bool **tab = nullptr;

    void alokuj();
    void dealokacja();
public:
    Plansza(int wiersze, int kolumny);

    int getSzerokosc();
    int getWysokosc();
    int getIlkom();

    void setWielkosc(int wiersze, int kolumny);

    ~Plansza();
};

#endif // PLANSZA_H

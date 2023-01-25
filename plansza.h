#ifndef PLANSZA_H
#define PLANSZA_H


class Plansza
{
private:
    int m_kolumny;
    int m_wiersze;
    bool **tab = nullptr;
//zmiana wierszy i kolumn na x
    void alokuj();
    void dealokacja();
public:
    Plansza(int wiersze, int kolumny);
    Plansza(){}

    void setIlkolumn(int m_kol){m_kolumny = m_kol;}
    void setIlwierszy(int m_wie){m_wiersze = m_wie;}

    int getIlkolumn();
    int getIlwierszy();

    void setWielkosc(int wiersze, int kolumny);

    int size();
    void clear();

    ~Plansza();

    bool* operator[](int i);
};

#endif // PLANSZA_H

#ifndef PLANSZA_H
#define PLANSZA_H


class Plansza
{
private:
    int m_kolumny;
    int m_wiersze;
    bool **tab = nullptr;

    void alokuj(){
        tab = new bool*[m_kolumny];
        tab[0] = new bool[m_kolumny*m_wiersze];

        for(int i = 1; i<m_wiersze; i++){
            tab[i] = &tab[0][i*m_kolumny];
        }
    }

    void dealokacja(){
        delete[] tab[0];
        delete[] tab;
        tab=nullptr;
    }
public:
    Plansza(int wiersze, int kolumny){
        m_kolumny = kolumny; m_wiersze = wiersze;
        alokuj();
    }

    int getSzerokosc(){return m_kolumny;}
    int getWysokosc(){return m_wiersze;}
    int getIlkom(){return m_kolumny*m_wiersze;}

    void setWielkosc(int wiersze, int kolumny){

    }

    ~Plansza(){
        for (int i = 0; i < m_wiersze; i++) {
             delete[] tab[i];
           }
           delete[] tab;
    }

};

#endif // PLANSZA_H

#include "gra.h"
#include<QFile>
#include<fstream>
#include<cstdlib>

using namespace std;

Gra::Gra(int i_wiersze, int i_kolumny):plansza(i_wiersze, i_kolumny){}

void Gra::inicjalizacjaStartowa(){
     for (int i = 0; i < plansza.getIlwierszy(); i++) {
       for (int j = 0; j < plansza.getIlkolumn(); j++) {
             plansza[i][j] = rand()%2;
       }
     }
}

int Gra::ZliczSasiadow(int x, int y) {
    int liczba_sasiadow= 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {continue;}
            int pomoc_x = x + i;
            int pomoc_y = y + j;
            if (pomoc_x >= 0 && pomoc_x < plansza.getIlwierszy()&& pomoc_y >= 0 && pomoc_y < plansza.getIlkolumn()) {
                 if (plansza[pomoc_x ][pomoc_y ]) {liczba_sasiadow++;}
            }
        }
    }
    return liczba_sasiadow;
}

void Gra::przetrwanie(){
    for (int i = 0; i < plansza.getIlwierszy(); i++) {
      for (int j = 0; j < plansza.getIlkolumn(); j++) {
         int liczba = ZliczSasiadow(i,j);
         if((liczba < 2 && plansza[i][j] == 1) || (liczba > 3 && plansza[i][j] == 1)){
             plansza[i][j] = 0;
         }
         if(liczba == 3 && plansza[i][j] == 0){
             plansza[i][j] = 1;
         }
      }
    }
}

void Gra::wypelnij(int x, int y){
    plansza.setWielkosc(x,y);
}

bool Gra::getCzyZyje(int w,int k){
    return plansza[w][k];
}

void Gra::setAll(int wie, int kol){
    plansza.setPlanszaAll(wie,kol);
}

void Gra::Czysc(){
    plansza.clear();
}

int Gra::get_ilosc_wierszy(){return plansza.getIlwierszy();}

int Gra::get_ilosc_kolumn(){return plansza.getIlkolumn();}

void Gra::zapis(QString sciezka){
    if(!sciezka.isEmpty()){
        std::ofstream file(sciezka.toStdString()); // otwieranie pliku z podanej ścieżki do zapisu
        for(int i=0; i<plansza.getIlwierszy(); i++){
            for(int j=0; j<plansza.getIlkolumn(); j++){
            file << i <<" ";
            file << j <<" ";
            file << plansza[i][j] << endl;
            }
        }
        file.close();
        }
}

void Gra::odczyt(QString sciezka){
    if(!sciezka.isEmpty()){
        plansza.clear();
        int x,y;
        bool przetrwanie;
        std::ifstream file(sciezka.toStdString()); // otwieranie pliku z podanej ścieżki do odczytu
        for(int i=0;!file.eof();i++){
            file>>x, file>>y, file>>przetrwanie;
            plansza[x][y] = przetrwanie;
            }
        file.close();
    }
}

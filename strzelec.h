#include <iostream>
#include <string>
#include "postac.h"

using namespace std;

class Strzelec : public Postac {
    public:
        Strzelec();
        Strzelec(string, int, int, int, double);
        void atakuj(Postac &cel);
        void przyjmij_atak(int obrazenia);
        void wypisz_statystyki();
        bool czy_zyje();
        void awansuj();
    private:
        string imie;
        int hp;
        int atak;
        int zasieg = 10;
        double krytyczne = 0.1;
};
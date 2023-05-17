#include <iostream>
#include <string>

using namespace std;

class Postac {
    public:
        virtual void atakuj(Postac &cel) = 0;
        virtual void przyjmij_atak(int) = 0;
        virtual void wypisz_statystyki() = 0;
        virtual bool czy_zyje() = 0;
        virtual void awansuj() = 0;
};
#include<iostream>
#include <string>

using namespace std;

class Postac {
    public:
        virtual void atakuj(Postac &cel) = 0;
        virtual void przyjmij_atak(double) = 0;
        virtual void wypisz_statystyki() = 0;
        virtual string podaj_imie() = 0;
        virtual bool czy_zyje() = 0;
        virtual void awansuj() = 0;
};
class Strzelec : public Postac {
    public:
        Strzelec();
        Strzelec(string, int, int, int, double);
        void atakuj(Postac &cel);
        void przyjmij_atak(double obrazenia);
        void wypisz_statystyki();
        string podaj_imie();
        bool czy_zyje();
        void awansuj();
    private:
        string imie;
        int hp;
        int atak;
        int zasieg = 10;
        double krytyczne = 0.1;
};

class Mag : public Postac {
    public:
        Mag();
        Mag(string, int, int, int, double);
        void atakuj(Postac &cel);
        void potezny_atak(Postac &cel);
        void przyjmij_atak(double obrazenia);
        void wypisz_statystyki();
        string podaj_imie();
        bool czy_zyje();
        void awansuj();
    private:
        string imie;
        int hp;
        int atak;
        int mana;
        double moc_umiejetnosci;
};

void pojedynek(Postac* cel, Postac* cel2); //na razie w strzelec.cpp
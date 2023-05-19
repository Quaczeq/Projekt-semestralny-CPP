#include<iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Postac {
    public:
        virtual void stworz() = 0;
        virtual void atakuj(Postac &cel) = 0;
        virtual void przyjmij_atak(double) = 0;
        virtual void wypisz_statystyki() = 0;
        virtual string podaj_imie() = 0;
        virtual char podaj_typ() = 0;
        virtual bool czy_zyje() = 0;
        virtual void awansuj() = 0;
        virtual void zapisz_do_pliku() = 0;
};
class Strzelec : public Postac {
    public:
        Strzelec();
        Strzelec(string, int, int, int, double);
        ~Strzelec();
        void stworz();
        void atakuj(Postac &cel);
        void przyjmij_atak(double obrazenia);
        void wypisz_statystyki();
        string podaj_imie();
        char podaj_typ();
        bool czy_zyje();
        void awansuj();
        void zapisz_do_pliku();
    private:
        char typ = 's';
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
        ~Mag();
        void stworz();
        void atakuj(Postac &cel);
        void potezny_atak(Postac &cel);
        void przyjmij_atak(double obrazenia);
        void wypisz_statystyki();
        string podaj_imie();
        char podaj_typ();
        bool czy_zyje();
        void awansuj();
        void zapisz_do_pliku();
    private:
        char typ = 'm';
        string imie;
        int hp;
        int atak;
        int mana;
        double moc_umiejetnosci;
};

//MENU
void menu();

//ZACHOWANIE POSTACI
void pojedynek(Postac &p1, Postac &p2); //na razie w strzelec.cpp

//METODY
void wczytaj_z_pliku_do_vectora(vector<Postac*> &wektor); //wczytuje postacie z pliku strzelcy.txt i magowie.txt do wektora
void usun_pliki(); //usuwa pliki strzelcy.txt i magowie.txt
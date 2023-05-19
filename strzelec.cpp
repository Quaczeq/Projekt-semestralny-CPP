#include <iostream>
#include <string>
#include "klasy.h"
#include <time.h>

using namespace std;

Strzelec::Strzelec() {
    Strzelec::stworz();
    Strzelec::zapisz_do_pliku();
}

Strzelec::Strzelec(string i, int h, int a, int z = 10, double k = 0.1) {
    this->imie = i;
    this->hp = h;
    this->atak = a;
    this->zasieg = z;
    this->krytyczne = k;
}

void Strzelec::stworz() {
    cout << "Tworzenie strzelca" << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj HP: ";
    cin >> hp;
    cout << "Podaj atak: ";
    cin >> atak;
    cout << "Podaj zasieg (5 - 15): ";
    cin >> zasieg;
    cout << "Podaj szanse na trafienie krytyczne (0.1 - 0.9): ";
    cin >> krytyczne;
}

void Strzelec::atakuj(Postac &cel) {
    if (cel.czy_zyje()) {
        cel.przyjmij_atak(atak);
        if (cel.czy_zyje()) {
            if (rand() % 200 < krytyczne * 100) {
                cout << "Krytyczny atak! ";
                cel.przyjmij_atak(atak*2);
            }
        }
    }
}

void Strzelec::przyjmij_atak(double obrazenia) {
    cout << imie << " przyjal " << obrazenia << " obrazen" << endl;
    hp -= int(obrazenia);
}

void Strzelec::wypisz_statystyki() {
    cout << "Imie: " << imie << " | HP: " << hp << endl << "Atak: " << atak << " | Zasieg: " << zasieg << " | Krytyczne: " << krytyczne << endl << endl;
}

bool Strzelec::czy_zyje() {
    return hp > 0;
}

string Strzelec::podaj_imie() {
    return imie;
}

void Strzelec::awansuj() {
    atak += 5;
    zasieg += 5;
    krytyczne += 0.1;
    cout << "Awansowano strzelca " << imie << "!" << endl;
}

void Strzelec::zapisz_do_pliku() {
    ofstream plik;
    plik.open("strzelcy.txt", ios::app);
    plik << imie << endl;
    plik << hp << endl;
    plik << atak << endl;
    plik << zasieg << endl;
    plik << krytyczne << endl;
    plik.close();
}

char Strzelec::podaj_typ() {
    return typ;
}
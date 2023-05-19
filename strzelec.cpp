#include <iostream>
#include <string>
#include "klasy.h"

using namespace std;

Strzelec::Strzelec() {
    imie = "Bezimienny Strzelec";
    hp = 100;
    atak = 10;
    zasieg = 10;
    krytyczne = 0.1;
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
            if (rand() % 100 < krytyczne * 100) {
                cel.przyjmij_atak(atak);
            }
        }
    }
}

void Strzelec::przyjmij_atak(double obrazenia) {
    cout << imie << " przyjal " << obrazenia << " obrazen" << endl;
    hp -= int(obrazenia);
}

void Strzelec::wypisz_statystyki() {
    cout << "Imie: " << imie << endl;
    cout << "HP: " << hp << endl;
    cout << "Atak: " << atak << endl;
    cout << "Zasieg: " << zasieg << endl;
    cout << "Szansa na krytyczne: " << krytyczne << endl << endl;
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
}

void pojedynek(Postac* cel, Postac* cel2) {
    while (cel->czy_zyje() && cel2->czy_zyje()) {
        cel->atakuj(*cel2);
        cel2->atakuj(*cel);
    }
    if (cel->czy_zyje()) {
        cout << cel->podaj_imie() << " wygral!" << endl;
   } else {
        cout << cel2->podaj_imie() << " wygral!" << endl;
    }
}
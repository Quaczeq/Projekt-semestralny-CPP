#include<iostream>
#include <string>
#include "klasy.h"

using namespace std;

Mag::Mag() {
    Mag::stworz();
    Mag::zapisz_do_pliku();
}

Mag::Mag(string i, int h, int a, int m = 100, double mu = 0.1) {
    this->imie = i;
    this->hp = h;
    this->atak = a;
    this->mana = m;
    this->moc_umiejetnosci = mu;
}

void Mag::stworz() {
    cout << "Tworzenie maga" << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj hp: ";
    cin >> hp;
    cout << "Podaj atak: ";
    cin >> atak;
    cout << "Podaj mana: ";
    cin >> mana;
    cout << "Podaj moc umiejetnosci: ";
    cin >> moc_umiejetnosci;
}

void Mag::atakuj(Postac &cel) {
    if (cel.czy_zyje()) {
        cel.przyjmij_atak(atak);
        if (cel.czy_zyje()) {
            if (mana > 0) {
                cel.przyjmij_atak(atak * moc_umiejetnosci);
                mana -= rand() % 20 + 10;
            }
            if (rand() % 100 < 10 && mana >= 50) {
                potezny_atak(cel);
            }
        }
    }
}

void Mag::potezny_atak(Postac &cel) {
    if (cel.czy_zyje()) {
        cout << "Potezny atak! ";
        cel.przyjmij_atak(atak * moc_umiejetnosci * 2);
        mana -= 50;
    }
}

void Mag::przyjmij_atak(double obrazenia) {
    cout << imie << " przyjal " << obrazenia << " obrazen" << endl;
    hp -= int(obrazenia);
}

void Mag::wypisz_statystyki() {
    cout << "Imie: " << imie << " | HP: " << hp << endl << "Atak: " << atak << " | Mana: " << mana << " | Moc umiejetnosci: " << moc_umiejetnosci << endl << endl;
}

string Mag::podaj_imie() {
    return imie;
}

bool Mag::czy_zyje() {
    return hp > 0;
}

void Mag::awansuj() {
    atak += 2;
    mana += 20;
    moc_umiejetnosci += 0.15;
    cout << "Awansowano maga " << imie << "!" << endl;
}

void Mag::zapisz_do_pliku() {
    ofstream plik;
    plik.open("magowie.txt", ios::app);
    plik << imie << endl;
    plik << hp << endl;
    plik << atak << endl;
    plik << mana << endl;
    plik << moc_umiejetnosci << endl;
    plik.close();
}

char Mag::podaj_typ() {
    return typ;
}
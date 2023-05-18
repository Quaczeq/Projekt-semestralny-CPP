#include<iostream>
#include <string>
#include "klasy.h"

using namespace std;

Mag::Mag() {
    imie = "Bezimienny";
    hp = 100;
    atak = 10;
    mana = 100;
    moc_umiejetnosci = 0.1;
}

Mag::Mag(string i, int h, int a, int m = 100, double mu = 0.1) {
    this->imie = i;
    this->hp = h;
    this->atak = a;
    this->mana = m;
    this->moc_umiejetnosci = mu;
}

void Mag::atakuj(Postac &cel) {
    if (cel.czy_zyje()) {
        cel.przyjmij_atak(atak);
        if (cel.czy_zyje()) {
            if (mana > 0) {
                cel.przyjmij_atak(atak * moc_umiejetnosci);
                mana -= 10;
            }
        }
    }
}

void Mag::potezny_atak(Postac &cel) {
    if (cel.czy_zyje()) {
        cel.przyjmij_atak(atak);
        if (cel.czy_zyje()) {
            if (mana > 0) {
                cel.przyjmij_atak(atak * moc_umiejetnosci * 2);
                mana -= 50;
            }
        }
    }
}

void Mag::przyjmij_atak(int obrazenia) {
    cout << imie << " przyjal " << obrazenia << " obrazen" << endl;
    hp -= obrazenia;
}

void Mag::wypisz_statystyki() {
    cout << "Imie: " << imie << endl;
    cout << "HP: " << hp << endl;
    cout << "Atak: " << atak << endl;
    cout << "Mana: " << mana << endl;
    cout << "Moc umiejetnosci: " << moc_umiejetnosci << endl;
}

bool Mag::czy_zyje() {
    return hp > 0;
}

void Mag::awansuj() {
    atak += 2;
    mana += 20;
    moc_umiejetnosci += 0.15;
}
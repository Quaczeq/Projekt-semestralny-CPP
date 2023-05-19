#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "klasy.h"

using namespace std;

void pojedynek(Postac &p1, Postac &p2) {
    while (p1.czy_zyje() && p2.czy_zyje()) { 
        p1.atakuj(p2);       
        if (p2.czy_zyje()) {
            p2.atakuj(p1);
            }
        if (rand() % 100 < 10) {
            p1.awansuj();
        }
        if (rand() % 100 < 10) {
            p2.awansuj();
        }
    }
    cout << endl;
    if (p1.czy_zyje()) {
        cout << p1.podaj_imie() << " wygral" << endl;
    } else {
        cout << p2.podaj_imie() << " wygral" << endl;
    }
    system("pause");
}

void wczytaj_z_pliku_do_vectora(vector<Postac*> &v) {
    ifstream plik;
    plik.open("strzelcy.txt");
    if (plik.good()) {
        string imie;
        string temp;
        int hp;
        int atak;
        int zasieg;
        double krytyczne;
        while (!plik.eof()) {
            plik >> imie >> hp >> atak >> zasieg >> krytyczne;
            if (imie == temp) break;
            v.push_back(new Strzelec(imie, hp, atak, zasieg, krytyczne));
            temp = imie;
        }
    }
    plik.close();
    plik.open("magowie.txt");
    if (plik.good()) {
        string imie;
        string temp;
        int hp;
        int atak;
        int mana;
        double moc_umiejetnosci;
        while (!plik.eof()) {
            plik >> imie >> hp >> atak >> mana >> moc_umiejetnosci;
            if (imie == temp) break;
            v.push_back(new Mag(imie, hp, atak, mana, moc_umiejetnosci));
            temp = imie;
        }
    }
    plik.close();
}

void usun_pliki(vector<Postac*> &v) {
    cout << "Jestes pewien? (y/n): ";
    string wybor;
    cin >> wybor;
    if (wybor == "n") {
        return;
    } else {
        cout << "Usuwam pliki strzelcy.txt i magowie.txt" << endl;
        remove("strzelcy.txt");
        remove("magowie.txt");
        v.clear();
        system("pause");
    }
}


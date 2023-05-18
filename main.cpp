// Created by Marcin Kłak on 2023-05-17
#include<iostream>
#include "klasy.h"
#include <string>

using namespace std;

int main()
{
    Strzelec p1("Wind", 147, 13, 11, 0.12);
    Strzelec p2("Karm", 93, 21, 15, 0.09);
    p1.wypisz_statystyki();
    cout << endl;
    p2.wypisz_statystyki();
    cout << endl;

    Mag m1("Gandalf", 200, 2, 100, 1.4);
    Mag m2("Saruman", 165, 3, 200, 2.3);

    m1.wypisz_statystyki();
    cout << endl;
    m2.wypisz_statystyki();
    cout << endl;

    p1.atakuj(m1);
    p1.atakuj(m1);
    p1.awansuj();
    p1.atakuj(m1);

    m1.wypisz_statystyki();
    cout << endl;

    m2.atakuj(p1);
    m2.potezny_atak(p1);

    cout << endl;
    p1.wypisz_statystyki();
    cout << endl;
    m1.awansuj();
    m1.wypisz_statystyki();
    cout << endl;
    m2.wypisz_statystyki();

    system("pause");
}
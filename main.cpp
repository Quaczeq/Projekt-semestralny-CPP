// Created by Marcin Kłak on 2023-05-17
#include<iostream>
#include "klasy.h"
#include <string>

using namespace std;

int main()
{
    Strzelec p1("Wind", 147, 13, 11, 0.12);
    Strzelec p2("Karm", 93, 21, 15, 0.09);

    Mag m1("Gandalf", 200, 2, 100, 1.4);
    Mag m2("Saruman", 165, 3, 200, 2.3);

    Postac* w;
    Postac* w2;
    w = &p1;
    w2 = &m2;

    pojedynek(w, w2);

    w->wypisz_statystyki();
    cout << endl;
    w2->wypisz_statystyki();


    system("pause");
}
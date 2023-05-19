// Created by Marcin Kłak on 2023-05-17
#include<iostream>
#include "klasy.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <Postac*> postacie;

    Postac* w = new Strzelec;
    Postac* w2 = new Mag;
    
    w->stworz();
    w2->stworz();

    postacie.push_back(w);
    postacie.push_back(w2);

    postacie[0]->wypisz_statystyki();
    postacie[1]->wypisz_statystyki();
    cout << "Wielkosc kontenera: " << postacie.size() << endl;

    system("pause");
}
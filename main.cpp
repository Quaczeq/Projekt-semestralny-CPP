// Created by Marcin Kłak on 2023-05-17
#include<iostream>
#include "klasy.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

char wybor;

int main()
{
    vector <Postac*> postacie;
    wczytaj_z_pliku_do_vectora(postacie);
    do {
        system("cls");
        cout << "Witaj w grze!" << endl << endl;
        cout << "Wybierz opcje:" << endl;
        cout << "1. Stworz postac" << endl;
        cout << "2. Pokaz postacie" << endl;
        cout << "3. Usun postacie" << endl;
        cout << "4. Rozpocznij pojedynek" << endl;
        cout << "5. Wyjdz z gry" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;
        switch (wybor) {
            case '1':
                system("cls");
                cout << "Wybierz typ postaci:" << endl;
                cout << "1. Strzelec" << endl;
                cout << "2. Mag" << endl;
                cout << "Wybierz opcje: ";
                cin >> wybor;
                if (wybor == '1') {
                    postacie.push_back(new Strzelec());
                } else if (wybor == '2') {
                    postacie.push_back(new Mag());
                }
                break;
            case '2':
                system("cls");
                for (int i = 0; i < postacie.size(); i++) {
                    cout << i + 1 << ". ";
                    postacie[i]->wypisz_statystyki();
                }
                system("pause");
                break;
            case '3':
                system("cls");
                usun_pliki(postacie);
                break;
            case '4':
                system("cls");
                cout << "Wybierz postacie do pojedynku: " << endl << endl;
                for (int i = 0; i < postacie.size(); i++) {
                cout << i + 1 << ". ";
                postacie[i]->wypisz_statystyki();
                }
                int pierwsza, druga;
                cout << "Wybierz pierwsza postac: "; cin >> pierwsza;
                cout << "Wybierz druga postac: "; cin >> druga;
                pojedynek(*postacie[pierwsza - 1], *postacie[druga - 1]); break;
        }
    } while (wybor != '5');
}
// Created by Marcin Kłak on 2023-05-17
#include<iostream>
#include "strzelec.h"
#include <string>

using namespace std;

int main()
{
    Strzelec p1("Wind", 147, 13, 11, 0.12);
    Strzelec p2("Karm", 93, 21, 15, 0.09);
    p1.wypisz_statystyki();
    cout << endl;
    p2.wypisz_statystyki();
    system("pause");
}
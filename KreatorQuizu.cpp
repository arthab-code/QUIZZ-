#include <iostream>
#include "Pytanie.h"
#include "OperacjeNaPlikach.h"
#include "KreatorQuizu.h"
#include "FolderQuizow.h"

using namespace std;

KreatorQuizu::KreatorQuizu(string nazwaQuizu)
{
    FolderQuizow folder;
    string nazwaFolderu = folder.ZwrocFolder();
    _sciezka = nazwaFolderu+"/"+nazwaQuizu+".txt";
}

bool KreatorQuizu::SprawdzCzyIstnieje()
{
    OperacjeNaPlikach operacjeNaPlikach(_sciezka);
    return operacjeNaPlikach.CzyIstnieje();
}

void KreatorQuizu::UstawLiczbePytan(short liczbaPytan)
{
    _liczbaPytan = liczbaPytan;
}

void KreatorQuizu::DodajPytania()
{
    OperacjeNaPlikach operacjeNaPlikach(_sciezka);

    if (operacjeNaPlikach.CzyIstnieje())
    {
        cout << endl;
        cout << "Taki quiz juz istnieje" << endl;
        system("pause");
        return;
    }

    for (int i=0; i<_liczbaPytan;i++)
    {

    string trescPytania, odp1, odp2, odp3;
    short odpPrawidlowa;
    cout << "Podaj tresc pytania: " << endl;
    cin.ignore();
    getline(cin, trescPytania,'\n');
    cout << "Podaj odpowiedz 1: " << endl;
    getline(cin, odp1);
    cout << "Podaj odpowiedz 2: " << endl;
    getline(cin, odp2);
    cout << "Podaj odpowiedz 3: " << endl;
    getline(cin, odp3);
    cout << "Ktora z tych odpowiedzi jest prawidlowa ? (wybierz numer od 1 do 3)" << endl;
    cin >> odpPrawidlowa;

    Pytanie pytanieTmp(trescPytania, odp1, odp2, odp3, odpPrawidlowa);



    operacjeNaPlikach.DodajPytanie(pytanieTmp, i+1);

    cout << endl;

    }
}

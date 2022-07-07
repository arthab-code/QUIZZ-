#include <iostream>
#include <fstream>
#include <dirent.h>
#include <filesystem>
#include <vector>
#include "OperacjeNaPlikach.h"
#include "FolderQuizow.h"
#include "Pytanie.h"

using namespace std;

OperacjeNaPlikach::OperacjeNaPlikach(string sciezka)
{
    _sciezka = sciezka;
}

bool OperacjeNaPlikach::CzyIstnieje()
{
    _plik.open(_sciezka);

    bool rezultat = _plik.good();

    _plik.close();

    return rezultat;
}


void OperacjeNaPlikach::DodajPytanie(Pytanie pytanie, int _nrPytania)
{
    _plik.open(_sciezka, ios::out | ios::app);
    string nrPytania = "["+to_string(_nrPytania)+"]";
    _plik << nrPytania << endl;
    _plik << pytanie.ZwrocTrescPytania() << endl;
    _plik << pytanie.ZwrocTrescOdpowiedzi(0) << endl;
    _plik << pytanie.ZwrocTrescOdpowiedzi(1) << endl;
    _plik << pytanie.ZwrocTrescOdpowiedzi(2) << endl;
    _plik << pytanie.ZwrocOdpowiedzPrawidlowa() << endl;
    _plik.close();

}

vector<string> OperacjeNaPlikach::PobierzListeKursow()
{
           FolderQuizow folder;
           mkdir(folder.ZwrocFolder());

           DIR * dr;
           dr = opendir(folder.ZwrocFolder());
           dirent * pdir;
           vector<string> quizy;

           while ((pdir = readdir(dr) ))
           {
               quizy.push_back(pdir->d_name);
           }

           quizy.erase(quizy.begin());
           quizy.erase(quizy.begin());

           return quizy;
}

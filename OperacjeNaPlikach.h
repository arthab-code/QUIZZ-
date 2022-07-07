#ifndef OPERACJENAPLIKACH_H_INCLUDED
#define OPERACJENAPLIKACH_H_INCLUDED

#include <fstream>
#include <vector>
#include "Pytanie.h"
class OperacjeNaPlikach
{
    private:
    fstream _plik;
    string _sciezka;

  public:

    OperacjeNaPlikach(string sciezka);

    bool CzyIstnieje();

    void DodajPytanie(Pytanie pytanie, int nrPytania);

    vector<string> PobierzListeKursow();

};

#endif // OPERACJENAPLIKACH_H_INCLUDED

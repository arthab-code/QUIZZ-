#ifndef PYTANIE_H_INCLUDED
#define PYTANIE_H_INCLUDED
#include <iostream>

using namespace std;

class Pytanie
{
    private:
    string trescPytania;
    string odpowiedz[3];
    short odpowiedzPrawidlowa;
    int nrPytania;

public:

    Pytanie();

    Pytanie(string tresc, string odpowiedz1, string odpowiedz2, string odpowiedz3, short prawidlowa);


    bool ZadajPytanie(int nrPytania);

    short ZwrocOdpowiedz();

    void UstawTrescPytania(string pytanie);

    void UstawOdpowiedz(int index, string tresc);

    void UstawOdpowiedzPrawidlowa(short odp);

    string ZwrocTrescPytania();

    string ZwrocTrescOdpowiedzi(int index);

    short ZwrocOdpowiedzPrawidlowa();

    int ZwrocNrPytania();

};


#endif // PYTANIE_H_INCLUDED

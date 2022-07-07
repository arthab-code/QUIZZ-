#include <iostream>
#include "Pytanie.h"

    Pytanie::Pytanie() {}

    Pytanie::Pytanie(string tresc, string odpowiedz1, string odpowiedz2, string odpowiedz3, short prawidlowa):
        trescPytania(tresc),
        odpowiedzPrawidlowa(prawidlowa)
    {
        odpowiedz[0] = odpowiedz1;
        odpowiedz[1] = odpowiedz2;
        odpowiedz[2] = odpowiedz3;

        if (prawidlowa < 1 || prawidlowa > 3)
        {
            cout << "Nieprawidlowy zakres odpowiedzi w pytaniu : " << tresc << endl;
            odpowiedzPrawidlowa = -1;
        }
    }


    bool Pytanie::ZadajPytanie(int nrPytania)
    {

    short odp;

    cout << "Pytanie nr [" << nrPytania << "] \n";
    cout << trescPytania << endl;
    cout << "odp [1]: " << odpowiedz[0] << endl;
    cout << "odp [2]: " << odpowiedz[1] << endl;
    cout << "odp [3]: " << odpowiedz[2] << endl;
    cout << "Twoja odpowiedz : " << flush;
    cin >> odp;

    if (odp < 1 || odp > 3)
    {
        cout << "Nieprawidlowy zakres odpowiedzi" << endl;
        return false;
    }

    if (odp == odpowiedzPrawidlowa)
        return true;
    else
        return false;

}


short Pytanie::ZwrocOdpowiedz()
{
    return odpowiedzPrawidlowa;
}


void Pytanie::UstawTrescPytania(string pytanie)
{
   trescPytania = pytanie;
}

void Pytanie::UstawOdpowiedz(int index, string tresc)
{
   Pytanie::odpowiedz[index] = tresc;
}

void Pytanie::UstawOdpowiedzPrawidlowa(short odp)
{
   Pytanie::odpowiedzPrawidlowa = odp;
}

string Pytanie::ZwrocTrescPytania()
{
    return trescPytania;
}

string Pytanie::ZwrocTrescOdpowiedzi(int index)
{
    return odpowiedz[index];
}

short Pytanie::ZwrocOdpowiedzPrawidlowa()
{
    return odpowiedzPrawidlowa;
}

int Pytanie::ZwrocNrPytania()
{
    return nrPytania;
}


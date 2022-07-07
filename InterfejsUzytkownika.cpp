#include "InterfejsUzytkownika.h"
#include "KreatorQuizu.h"
#include "QuizManager.h"
#include "FolderQuizow.h"
#include "OperacjeNaPlikach.h"
#include <iostream>
#include <vector>

using namespace std;

void InterfejsUzytkownika::WyswietlaczEkranu()
{
    char wybor;

      while(1)
      {
        cout << "[0] Stworz quiz" << endl;
        cout << "[1] Uruchom quiz"<< endl;
        cout << "[2] Wyjscie" << endl;

        cin >> wybor;

        switch(wybor)
        {
          case '0':
            StworzQuiz();
            system("pause");
            WyczyscEkran();
            break;

          case '1':
            ListaQuizow();
            system("pause");
            WyczyscEkran();
            break;

          case '2':
              return;
            break;

        }
      }
}

        void InterfejsUzytkownika::WyczyscEkran()
        {
            system("cls");
        }

        void InterfejsUzytkownika::StworzQuiz()
        {
          short ilePytan;
          string nazwaQuizu;

          cout << "Podaj nazwe quizu : " << endl;
          cin >> nazwaQuizu;

          KreatorQuizu kreator(nazwaQuizu);

          if (kreator.SprawdzCzyIstnieje())
          {
              return;
          }

          cout << "Podaj ilosc pytan (musi byc to liczba > 0) : " << endl;
          cin >> ilePytan;

          if (ilePytan <= 0) return;

          kreator.UstawLiczbePytan(ilePytan);
          kreator.DodajPytania();


         }

         void InterfejsUzytkownika::ListaQuizow()
         {
           FolderQuizow folder;
           OperacjeNaPlikach operacjeNaPlikach(folder.ZwrocFolder());

           vector<string> quizy = operacjeNaPlikach.PobierzListeKursow();

           if (quizy.size() <= 0)
           {
               cout << "Brak quizow na liscie, musisz stworzyc jakis quiz" << endl;
               return;
           }
           short sum = 0;
           for (int i=0; i< quizy.size(); i++)
           {
               cout <<"["<<i<<"] " << quizy[i] << endl;
               sum += i;
           }
           cout << "[" << sum+1 << "] POWROT"<< endl;

           short choice;
           cin >> choice;

           if (choice < 0 || choice >= quizy.size()) return;


           QuizManager qM(quizy[choice]);
           qM.StartQuiz();

         }



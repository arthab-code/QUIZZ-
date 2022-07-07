#ifndef KREATORQUIZU_H_INCLUDED
#define KREATORQUIZU_H_INCLUDED

class KreatorQuizu
{
   private:
       string _sciezka;
       short  _liczbaPytan;

   public:
       KreatorQuizu(string nazwaQuizu);

       void UstawLiczbePytan(short liczbaPytan);

       bool SprawdzCzyIstnieje();

       void DodajPytania();



};


#endif // KREATORQUIZU_H_INCLUDED

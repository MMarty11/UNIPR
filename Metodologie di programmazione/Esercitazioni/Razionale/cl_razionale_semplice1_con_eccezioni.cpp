/*
  Scrivere una classe che implementa il tipo di dato astratto "numero razionale"
  (rappresentato come numeratore/denominatore). Scrivere anche un programma 
  principale di prova che effettui semplici operazioni di somma di numeri
  razionali, stampando i risultati calcolati.
*/

#include <iostream>
#include <vector>

using namespace std;

class Razionale {
   private:
      int n;    // Numeratore.
      int d;    // Denominatore.
   public:
      // Inizializzazione
      Razionale() {                   // Costruttore senza parametri 
         n = 0;
         d = 1;
         }
      Razionale(int num, int den=1) {   // Costruttore con 2 parametri
         n = num;
         if (den == 0) throw 0;
         d = den;
         }

      // Legge il numero razionale nella forma `n/d'.
      void leggi(istream& s_in) {
         int num, den;
         char sep;
         s_in >> num >> sep >> den;
         n = num;
         if (den == 0) throw 0;
         if (sep != '/') throw 1;
         d = den;
         return;
         }

      // Stampa il numero razionale nella forma `n/d'.
      void stampa(ostream& s_out) const {
         s_out << n << '/' << d;
         return;
         }     

      // Esegue la somma tra 'x' e l'oggetto di invocazione.
      Razionale operator+(Razionale x) const {
         Razionale risultato;
         risultato.d = d * x.d;
         risultato.n = n * x.d + x.n * d;
         return risultato;
         }
};

ostream& operator<<(ostream& s_out, const Razionale& r) {
  r.stampa(s_out);
  return s_out;
}

istream& operator>>(istream& s_in, Razionale& r) {
  r.leggi(s_in);
  return s_in;
}



int main() {
   try {
      Razionale a,b,c;  // invocano il costruttore senza parametri
      cout << "Dai la prima frazione (n/d): ";
      cin >> a;
      cout << "Dai la seconda frazione (n/d): ";
      cin >> b;
      c = a + b;
      cout << "La somma e': " << c << endl;
      
      vector<int> v1;
      v1[-1] = 2;
      
      
   }
   catch (int codice) {
      if (codice == 0)
          cout << "Denominatore nullo!" << endl;
      else if (codice == 1)
          cout << "Errore sintattico nella frazione" << endl;
      else
          cout << "Errore non previsto" << endl;
   }
   catch (...) {   // cattura qualsiasi eccezione   
      cout << "Eccezione non gestita" << endl;
   }
   cout << "Programma terminato" << endl;
   
   system("pause");
   return 0;
}

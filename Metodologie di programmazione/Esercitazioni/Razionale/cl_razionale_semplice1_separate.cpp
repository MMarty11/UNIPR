/*
  Scrivere una classe che implementa il tipo di dato astratto "numero razionale"
  (rappresentato come numeratore/denominatore). Scrivere anche un programma 
  principale di prova che effettui semplici operazioni di somma di numeri
  razionali, stampando i risultati calcolati.
*/

#include <iostream>

using namespace std;

class Razionale {
   private:
      int n;    // Numeratore.
      int d;    // Denominatore.
   public:
      Razionale();                     // Costruttore senza parametri 
      Razionale(int num, int den=1);   // Costruttore con 2 parametri
      // Legge il numero razionale nella forma `n/d'.
      void leggi(istream& s_in);
      // Stampa il numero razionale nella forma `n/d'.
      void stampa(ostream& s_out) const; 
      // Somma tra 'x' e l'oggetto di invocazione.
      Razionale operator+(Razionale x) const;
};
Razionale::Razionale() {               
         n = 0;
         d = 1;
         }
         
Razionale::Razionale(int num, int den) {   
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else 
            d = den;
         }

void Razionale::leggi(istream& s_in) {
         int num, den;
         char sep;
         s_in >> num >> sep >> den;
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else
            d = den;
         return;
         }

void Razionale::stampa(ostream& s_out) const {
         s_out << n << '/' << d;
         return;
         }     

Razionale Razionale::operator+(Razionale x) const {
         Razionale risultato;
         risultato.d = d * x.d;
         risultato.n = n * x.d + x.n * d;
         return risultato;
         }
         
ostream& operator<<(ostream& s_out, const Razionale& r) {
  r.stampa(s_out);
  return s_out;
}

istream& operator>>(istream& s_in, Razionale& r) {
  r.leggi(s_in);
  return s_in;
}



int main() {
   Razionale a,b,c;  // invocano il costruttore senza parametri
   cout << "Dai la prima frazione (n/d): ";
   cin >> a;
   cout << "Dai la seconda frazione (n/d): ";
   cin >> b;
   c = a + b;
   cout << "La somma e': " << c << endl;
   
   Razionale d(2,3);     // invoca il costruttore con 2 parametri; d <- 2/3
   const Razionale e(3); // invoca il costruttore con 2 parametri, 
                         // ma con valore di default (=1) per il secondo par.:
                         // e <- 3/1
   cout << "La somma e': " << e + d << endl;   // 3/1 + 2/3 = 11/3
   
   Razionale f = 4;      // invoca il costruttore con 2 parametri; d <- 4/1
   cout << "La somma e': " << f + Razionale(1,5) << endl;  // 4/1 + 1/5 = 21/5
 
   system("pause");
   return 0;
}

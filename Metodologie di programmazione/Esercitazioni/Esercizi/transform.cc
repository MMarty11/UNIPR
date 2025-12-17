#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

/*****************************
 * Date due sequenze in input,
 * scrive su una sequenza in output il risultato di una procedura binaria.
 * Nota1: le tre sequenze possono avere tipi diversi.
 * Nota2: le sequenze in input possono avere dimensioni diverse.
 */
template <typename In1, typename In2, typename Out, typename Proc>
Out
transform(In1 f1, In1 l1, // prima sequenza in input
          In2 f2, In2 l2, // seconda sequenza in input
          Out out,        // iteratore alla sequenza di output
          Proc f) {
  while(f1 != l1 && f2 != l2) {
    *out = f(*f1,*f2);
    ++out;
    ++f1;
    ++f2;
  }
  return out;            // restituisco l'it aggiornato al termine della seq in output.
}

// Due possibili implementazioni con cui istanziare `Proc'
template <typename T>
struct Media {
 T operator() (const T& x, const T& y) const {
   return (x + y)/2;
 }
};

template <typename T>
T media(const T& x, const T& y) {
  return (x + y)/2;
}

/*******
 * Funzione di stampa che utlizza la std::copy.
 * Utilizzata per dedurre il tipo con cui istanziare
 * std::ostream_iterator dal tipo degli elementi puntati dall'iteratore.
 */
template <typename It>
void
print(It first, It last) {
  if (first == last) {
    std::cout<<"Sequenza vuota!"<<std::endl;
    return;
  }
  using T = typename std::iterator_traits<It>::value_type;
  std::ostream_iterator<T> out(std::cout, " ");
  std::copy(first, last, out);
  std::cout<<std::endl;
}



int main() {
  std::vector<int> vi;
  std::vector<double> vd;
  std::list<double> ld;

  // Inizializzazione (con lunghezze diverse)
  for (int i = 0; i < 50; i+=5)
    vi.push_back(i % 3);
  for (int i = 0; i < 50; i+=3)
    vd.push_back(i % 5);

  // Stampe di controllo
  std::cout<<"Vector int: ";
  print(vi.begin(), vi.end());
  std::cout<<"Vector double: ";
  print(vd.begin(), vd.end());
  std::cout<<"List double: ";
  print(ld.begin(), ld.end());
  std::cout<<std::endl;

  Media<double> my_media;

  /************************************************************
   * Utilizzo della funzione transform per la stampa su std output
   */
  std::cout<<"Stampa delle medie: "<<std::endl;
  std::ostream_iterator<double> out(std::cout, " ");
  transform(vi.begin(), vi.end(),
           vd.begin(), vd.end(),
           out,
           my_media);              // oppure: media);
  std::cout<<std::endl;


  /************************************************************
   * Utilizzo della funzione transform per l'inserimento in altro contenitore.
   * NB: NON sarà argomento della prova in itinere.
   */
  // Versione 1: `my_output_adaptor' trasforma le scritture in overwrite
  // in inserimenti (tramite push_back) sul contenitore con cui viene
  // costruito.
  std::back_insert_iterator< std::list<double> > my_output_adaptor(ld);
  transform(vi.begin(), vi.end(),
           vd.begin(), vd.end(),
           my_output_adaptor,
           my_media);               // oppure: media);

  // Versione 2 equivalente: sfrutta deduzione templatica tramite metodo
  // std::back_inserter che ritorna un std::back_insert_iterator
  // istanziato con il tipo del contenitore con cui viene costruito.
  transform(vi.begin(), vi.end(),
           vd.begin(), vd.end(),
	   std::back_inserter(ld),
           my_media);               // oppure: media);

  std::cout<<"\nDopo (doppio) inserimento in ld:"<<std::endl;
  std::cout<<"Vector int: ";
  print(vi.begin(), vi.end());
  std::cout<<"Vector double: ";
  print(vd.begin(), vd.end());
  std::cout<<"List double: ";
  print(ld.begin(), ld.end());

  return 0;
}

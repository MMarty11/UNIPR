#include <iostream>
#include <iterator>
#include <vector>

/*************
 * FIND: restituisce la posizione della prima occorrenza di x in sequenza.
 *  Se non è presente restituisce last.
 */
template <typename It, typename T>
It
find(It first, It last, const T& x) {
  for (; first != last; ++first)
    if (*first == x)
      return first;
  return last; // first == last.
}

/*************
 * FIND_IF: restituisce la posizione del primo elemento che soddisfa un predicato.
 * Livelli di generalizzazione:
 * 1) predicato fissato.
 * 2) predicato parametrico come oggetto funzione.
 */

// 1) predicato codificato all'interno della funzione.
template <typename It>
It
find_if_maggiore_di_42(It first, It last) {
  for (; first != last ; ++first)
    if (*first > 42)
      return first;
  return last;
}

// 2) predicato f parametrico.
template <typename It, typename Pred>
It
find_if(It first, It last, Pred f) {
  for (; first != last; ++first)
    if (f(*first))
      return first;
  return last;
}

/**************/
// Con cosa istanziare Pred?
// Oggetto funzione.. più o meno parametrico..

struct Intero_maggiore_di_42 {
  bool operator() (int y) {
    return y > 42;
  }
};

class Intero_maggiore_di {
private:
  int _x;
public:
  Intero_maggiore_di(int x) : _x(x) {};
  bool operator() (int y) {
    return y > _x;
  }
};

// Prerequisiti: il tipo T deve fornire copy ctor e operator>.
template <typename T>
class Maggiore_di {
private:
  T _x;
public:
  Maggiore_di(T x) : _x(x) {};
  bool operator() (T y) {
    return y > _x;
  }
};


/**************/
// Un tipo `wrapper' di int.
class My_silly_type {
private:
  int field;
public:
  My_silly_type() = default;
  My_silly_type(int x) : field(x) {};
  My_silly_type(const My_silly_type& mst) : field(mst.get()) {};
  int get() const { return field; }
  bool operator==(const My_silly_type& mst) {
    return field == mst.get();
  }
  bool operator>(const My_silly_type& mst) {
    return field > mst.get();
  }
};
/***************/


int main() {
  std::vector<int> vi = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  std::vector<int>::iterator vi_it;
  int x = 6;

  std::vector<My_silly_type> vmst = {1,2,3,6,10,18,29,40};
  std::vector<My_silly_type>::iterator vmst_it;
  My_silly_type y(6);

  vi_it = find(vi.begin(), vi.end(), x);
  if (vi_it != vi.end())
    std::cout<<"Elemento "<< x <<" trovato: "<< *vi_it <<std::endl;
  else
    std::cout<<"Elemento "<< x <<" non trovato!"<<std::endl;

  vmst_it = find(vmst.begin(), vmst.end(), y);
  if (vmst_it != vmst.end())
    std::cout<<"Elemento "<< y.get() <<" trovato: "<< vmst_it->get() <<std::endl;
  else
    std::cout<<"Elemento "<< y.get() <<" non trovato!"<<std::endl;

  std::cout<<std::endl;
  /****************/

  vi_it = find_if_maggiore_di_42(vi.begin(), vi.end());
  if (vi_it != vi.end())
    std::cout<<"L'elemento "<<*vi_it<<" e' il primo maggiore di 42"<<std::endl;
  else
    std::cout<<"Nessun elemento maggiore di 42 trovato!"<<std::endl;

  // Oggetto funzione fisso
  Intero_maggiore_di_42 pred42;
  vi_it = find_if(vi.begin(), vi.end(), pred42);
  if (vi_it != vi.end())
    std::cout<<"L'elemento "<< *vi_it <<" e' il primo maggiore di 42"<<std::endl;
  else
    std::cout<<"Nessun elemento maggiore di 42 trovato!"<<std::endl;


  // Oggetto funzione parametrico per valore
  Intero_maggiore_di int_pred(x);
  vi_it = find_if(vi.begin(), vi.end(), int_pred);
  if (vi_it != vi.end())
    std::cout<<"L'elemento "<< *vi_it <<" e' il primo maggiore di "<< x <<std::endl;
  else
    std::cout<<"Nessun elemento maggiore di "<< x <<" trovato!"<<std::endl;


  // Oggetto funzione parametrico per valore e tipo
  Maggiore_di<int> pred1(x);
  vi_it = find_if(vi.begin(), vi.end(), pred1);
  if (vi_it != vi.end())
    std::cout<<"L'elemento "<< *vi_it <<" e' il primo maggiore di "<< x <<std::endl;
  else
    std::cout<<"Nessun elemento maggiore di "<< x <<" trovato!"<<std::endl;


  Maggiore_di<My_silly_type> pred2(y);
  vmst_it = find_if(vmst.begin(), vmst.end(), pred2);
  if (vmst_it != vmst.end())
    std::cout<<"L'elemento "<< vmst_it->get()
             <<" e' il primo maggiore di "<< y.get() <<std::endl;
  else
    std::cout<<"Nessun elemento maggiore di "<< y.get() <<" trovato!"<<std::endl;

  return 0;
}

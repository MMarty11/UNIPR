#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

/************
 * COUNT_VAL : conta le occorrenze di un elemento in una sequenza.
 * Livelli di generalizzazione:
 * 1) la sequenza è un vector di interi.
 * 2) la sequenza è un vector di elementi di tipo T.
 * 3) la sequenza è un contenitore di elementi di tipo T.
 * 4) la sequenza è espressa da una coppia di iteratori: first e last.
 * 5) 4 + il tipo di ritorno è ricavato con std::iterator_traits
 */

// 1) la sequenza è un vector di interi.
int
count_val1(const std::vector<int>& vi, int x) {
  int n = 0;
  for (int i = vi.size(); i-- > 0; )
    if (vi[i] == x) ++n;
  return n;
}

// 2) la sequenza è un vector di elementi di tipo T.
//    Il tipo T deve fornire: operator==
template <typename T>
int
count_val2(const std::vector<T>& v, const T& x) {
  int n = 0;
  for (int i = v.size(); i-- > 0; )
    if (v[i] == x) ++n;
  return n;
}

// 3) la sequenza è un contenitore di elementi di tipo T.
//    Il tipo T deve fornire: operator==
//    Il tipo Cont deve fornire: size,  T operator[],
template <typename Cont, typename T>
int
count_val3(const Cont& v, const T& x) {
  int n = 0;
  for (int i = v.size(); i-- > 0; )
    if (v[i] == x) ++n;
  return n;
}

// 4) la sequenza è espressa da una coppia di iteratori: first e last.
//    Il tipo It deve fornire: operator++, T *.
//    Precondizioni : fist <= last.
template <typename It, typename T>
int
count_val4(It first, It last, const T& x) {
  int n = 0;
  for (; first != last; ++first)
    if (*first == x) ++n;
  return n;
}

// 5) 4 + il tipo di ritorno è ricavato con std::iterator_traits
template <typename It, typename T>
typename std::iterator_traits<It>::difference_type
count_val(It first, It last, const T& x) {
  typename std::iterator_traits<It>::difference_type n = 0;
  for (; first != last; ++first)
    if (*first == x) ++n;
  return n;
}


int main() {
  int x = 7;
  std::string s = "bla";

  std::vector<int> vi = {7,7,1,7,2,3,7,4,5,6,7};
  std::cout<<"1) "<< count_val1(vi, x) <<std::endl;

  std::vector<std::string> vs = {"bla", "ciao", "mondo", "bla", "bla", "ciao"};
  std::cout<<"2) "<< count_val2(vs, s) <<std::endl;

  std::deque<std::string> ds = {"bla", "ciao", "mondo", "bla", "bla", "ciao"};
  std::cout<<"3) "<< count_val3(ds, s) <<std::endl;

  std::cout<<"4) "<< count_val4(vs.begin(), vs.end(), s) <<std::endl;

  std::cout<<"5) "<< count_val(ds.begin(), ds.end(), s) <<std::endl;

  return 0;
}

#include <string>
#include <vector>
#include <algorithm>    // <----
#include <iostream>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;

/**

void f(const vect& v) {
  const_iter i = std::find(v.begin(), v.end(), "cioccolato");
  const_iter i_end = std::find(v.begin(), v.end(), "menta");
  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}

void g(vect& v) {
  iter i = v.begin();
  iter i_end = v.end();
  *i = "cacao";
  v.insert(i, "vaniglia");
  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}

************************/

typedef std::vector<std::string>::const_iterator const_iter;

void f(const vect& v) {
  const_iter i = std::find(v.begin(), v.end(), "cioccolato");
  const_iter i_end = std::find(v.begin(), v.end(), "menta");
  while (i != i_end) {
    if (i == v.end()) {
      std::cout << "End of sequence." << std::endl;
      return;
    }
    std::cout << *i << std::endl;
    ++i;
  }
}

void g(vect& v) {
  iter i = v.begin();
  if (i != v.end())
    *i = "cacao";

  i = v.insert(i, "vaniglia");
  // oppure ricalcola i = v.begin(); dopo l'inserimento.
  iter i_end = v.end();

  while (i != i_end) {
    std::cout << *i << std::endl;
    ++i;
  }
}

/************************/

int main() {
  vect vs;
  vs.reserve(6);
  vs.push_back("fragola");
  vs.push_back("cioccolato");
  vs.push_back("limone");
  vs.push_back("menta");

  std::cout <<"Function `f' on `vs' :" << std::endl;
  f(vs);
  std::cout <<"\nFunction `g' on `vs' :" << std::endl;
  g(vs);

  /*******/

  vect vs1 = {"menta", "limone", "cioccolato", "panna", "fragola"};
  std::cout <<"\nFunction `f' on `vs1' :" << std::endl;
  f(vs1);
  std::cout <<"\nFunction `g' on `vs1' :" << std::endl;
  g(vs1);

}

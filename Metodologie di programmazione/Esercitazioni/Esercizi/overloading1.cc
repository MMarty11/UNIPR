#include <iostream>

namespace N {

struct S {
  S();
  S(int);
  void phi(int i);
  void psi(int i);
};
struct R : public S {
  R(int);
  void psi(double d);
};

void foo(int i);
void foo(double d, S& s_obj);
void bar(const char* pc);

} // namespace N

void foo(double d);
void bar(char c);
void bar(unsigned long ul);


void test(const N::S& s_obj) {
  N::foo(4, s_obj);
  foo(4.5, 3);
  N::foo(4.5, 3);
  N::foo(3.3);
  bar(123);
  bar("123");
  bar('a');
}


int main() {
  N::S s(1);
  test(s);

  N::R r;
  r.psi(3);
  r.phi(3);
}

/*********************************************

  N::S s(1);                              N::S::S(int)
  test(s);                                test(const N::S&)

  N::foo(4, s_obj);                       ERROR: discards const qual
  foo(4.5, 3);                            ERROR: no match
  N::foo(4.5, 3);                         ERROR: tmp -> non-const lval
  N::foo(3.3);                            N::foo(int)
  bar(123);                               ERROR: ambiguous
  bar("123");                             ERROR: invalid conv
  bar('a');                               bar(char)

  N::R r;                                 ERROR: deleted func N::R::R()
  r.psi(3);                               N::R::psi(double)
  r.phi(3);                               N::S::phi(int)

*/

#include <iostream>
#include <string>

namespace N {

class C {
private:
  void foo(int) const;
public:
  C(int);
  C(std::string);
  C(const C&);
  void foo(double);
};

void f(int d);
void f(double d);
void f(const C& c);
void g(int i, double d);
void g(int i, int j);
void h(C* pc);
void r(const C& c);

} // namespace N

void f(N::C& c);
int h(const char* s = 0);
int h(const N::C* pc);

int p(std::string);
int p(const char* c);

void fie(const std::string& s);


int main() {
  int x;
  const std::string s;

  N::C c(5);
  const N::C c1("42");
  c.foo(3.f);
  c1.foo(3.f);

  f(x);
  f(c);
  N::f('a');

  g(5, 3.7);
  N::g(2.3, 5);
  N::g(5, 2.3);

  h(&c);
  h();

  p(0);
  p(s);

  N::r(x);

  return 0;
}





/********************************************************************

  N::C c(5);                   N::C::C(int)
  const N::C c1("42");         N::C::C(std::string)
  c.foo(3.f);                  N::C::foo(double)
  c1.foo(3.f);                 ERROR: "N::C::foo(int) const" is private

  f(x);                        ERROR: tmp -> non-const lval
  f(c);                        f(N::C&)
  N::f('a');                   N::f(int)

  g(5, 3.7);                   ERROR: Not declared in this scope
  N::g(2.3, 5);                N::g(int, int)
  N::g(5, 2.3);                N::g(int, double)

  h(&c);                       N::h(N::C*)
  h();                         h(char const*)

  p(0);                        p(char const*)
  p(s);                        p(std::string)

  N::r(x);                     N::C::C(int) + N::r(N::C const&)

*/

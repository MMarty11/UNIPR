#include <iostream>

/*************

class Derived1 {
private:
  void g() { std::cout << "Derived1 g()" std::endl; }
public:
  void f(Derived1* d1) {
    d1->g();
  }
  ~Derived1() { std::cout << "~Derived1 " << std::endl; }
};

class Derived2 {
private:
  void h() { std::cout << "Derived2 h()" std::endl; }
public:
  void f(Derived2* d2) {
    d2->h();
  }
  ~Derived2() { std::cout << "~Derived2 " << std::endl; }
};

**************/

class Base {
public:
  virtual void f(Base*) = 0;
  virtual ~Base() {}
};


class Derived1 : public Base {
private:
  void g() { std::cout << "Derived1 g()" << std::endl; }
public:
  void f(Base* pb) override {
    if (Derived1* d1 = dynamic_cast<Derived1*>(pb)) {
      d1->g();
    }
  }
  ~Derived1() { std::cout << "~Derived1 " << std::endl; }
};

class Derived2 : public Base {
private:
  void h() { std::cout << "Derived2 h()" << std::endl; }
public:
  void f(Base* pb) override {
    if (Derived2* d2 = dynamic_cast<Derived2*>(pb)) {
      d2->h();
    }
  }
  ~Derived2() { std::cout << "~Derived2 " << std::endl; }
};

int main() {
  Base* pd1 = new Derived1();
  Base* pd2 = new Derived2();

  pd1->f(pd1);

  pd2->f(pd2);

  delete pd1;
  delete pd2;

  return 0;
}

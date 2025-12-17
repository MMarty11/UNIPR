#include <iostream>

// Risorsa
class A {
private:
  int _a;
public:
  A(int a) : _a(a) {};
  A() = default;
  A(const A&) = default;
  A(A&&) = default;
  A& operator=(const A&) = default;
  A& operator=(A&&) = default;
  // ...
};


// - Acquisizione
A* new_resource(int a) {
  return new A(a);
}
// - Uso
void process(A* a1, A* a2 = NULL) {
  (void) a1;
  (void) a2;
}
// - Rilascio (non deve lanciare eccezioni)
void release(A* p) {
  delete p;
}


class Gestore_A {
private:
  A* p;
public:
  explicit Gestore_A(int a) : p(new_resource(a)) {};
  A* get() {
    return p;
  }
  ~Gestore_A() {
    release(p);
  }
  Gestore_A(const Gestore_A&) = delete;
  Gestore_A& operator=(Gestore_A&) = delete;
};


int main() {
/*
  A* p_a1 = new_resource(1);
  A* p_a2 = new_resource(2);
  process(p_a1, p_a2);
  release(p_a2);
  A* p_a3 = new_resource(3);
  process(p_a1, p_a3);
  process(p_a3);
  release(p_a3);
  release(p_a1);
*/


/***************************/
// SOL 1: try ... catch

  A* p_a1 = new_resource(1);
  try {
    A* p_a2 = new_resource(2);
    try {
      process(p_a1, p_a2);
      release(p_a2);
    } catch(...) {
      release(p_a2);
      throw;
    }
    A* p_a3 = new_resource(3);
    try {
      process(p_a1, p_a3);
      process(p_a3);
      release(p_a3);
    } catch(...) {
      release(p_a3);
      throw;
    }
    release(p_a1);
  } catch(...) {
    release(p_a1);
    throw;
  }

/***************************/
// SOL 2: RAII

  {
    Gestore_A g_a1(1);
    {
      Gestore_A g_a2(2);
      process(g_a1.get(), g_a2.get());
    } // a_2 released

    {
      Gestore_A g_a3(3);
      process(g_a1.get(), g_a3.get());
      process(g_a3.get());
    } // a_3 released

  } // a_1 released

  return 0;
}


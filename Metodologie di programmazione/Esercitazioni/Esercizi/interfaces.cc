#include <iostream>
#include <list>

/*
template <typename T>
class Set : public std::list<T> {
public:
  // Costruisce l’insieme vuoto.
  Set();
  // Costruisce il singoletto che contiene t.
  Set(T t);
  Set(Set y);
  void operator=(Set y);
  virtual ~Set();

  unsigned int size();
  bool is_empty();
  bool contains(Set y);
  T& min();
  void pop_min();
  void insert(T z);
  void union_assign(Set y);
  void intersection_assign(Set y);
  void swap(Set y);
  std::ostream operator<<(std::ostream os);
private:
  // ...
};
*/


template <typename T>
class Set : private std::list<T> {
public:
  // Costruisce l’insieme vuoto.
  Set();
  // Costruisce il singoletto che contiene t.
  explicit Set(const T& t);
  Set(const Set& y);
  Set& operator=(const Set& y);
  ~Set();

  unsigned int size() const;
  bool is_empty() const;
  bool contains(const Set& y) const;
  const T& min() const;
  void pop_min();
  void insert(const T& z);
  void union_assign(const Set& y);
  void intersection_assign(const Set& y);
  void swap(Set& y);
  std::ostream& print(std::ostream& os) const;
private:
  // ...
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
  return set.print(os);
}




typedef int size_type;
typedef int value_type;
/*
struct Matrix {
  // ...
  size_type num_rows();
  size_type num_cols();
  value_type& get(size_type row, size_type col);
  Matrix& operator-();
  Matrix& operator+=(Matrix y);
  Matrix& operator+(Matrix y);
  void print(ostrem os);
  // ...
};
*/

struct Matrix {
  // ...
  size_type num_rows() const;
  size_type num_cols() const;
  value_type& get(size_type row, size_type col);
  const value_type& get(size_type row, size_type col) const;
  Matrix operator-() const;
  Matrix& operator+=(const Matrix& y);
  Matrix operator+(const Matrix& y) const;
  std::ostream& print(std::ostream& os) const;
  // ...
};

#include <iostream>
#include <iterator>
#include <vector>

template <typename Fwd_It, typename Pred>
Fwd_It
adjacent_find(Fwd_It first, Fwd_It last, Pred p) {
  if (first == last)
    return last;
  Fwd_It next = first;
  ++next;
  while (next != last) {
    if (p(*first, *next))
      return first;
    ++first;
    ++next;
  }
  return last;
}

bool
equals(int x, int y) {
  return x == y;
}

int main() {
  std::vector<int> vi;
  std::vector<int>::iterator res;

  res = adjacent_find(vi.begin(), vi.end(), equals);
  if (res == vi.end()) {
    std::cout << "Sequenza vuota o nessuna coppia adiacente trovata." << std::endl;
  } else {
    std::cout << "Il primo elemento della coppia è: " << *res << std::endl;
  }


  for (int i = 0; i < 6; ++i)
    vi.push_back(i);

  res = adjacent_find(vi.begin(), vi.end(), equals);
  if (res == vi.end()) {
    std::cout << "Sequenza vuota o nessuna coppia adiacente trovata." << std::endl;
  } else {
    std::cout << "Il primo elemento della coppia è: " << *res << std::endl;
  }


  for (int i = 5 ; i < 10; ++i)
    vi.push_back(i);

  res = adjacent_find(vi.begin(), vi.end(), equals);
  if (res == vi.end()) {
    std::cout << "Sequenza vuota o nessuna coppia adiacente trovata." << std::endl;
  } else {
    std::cout << "Il primo elemento della coppia è: " << *res << std::endl;
  }

}

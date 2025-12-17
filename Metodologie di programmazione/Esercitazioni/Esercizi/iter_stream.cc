#include <iostream>
#include <vector>
#include <iterator>

template <typename In, typename Out>
Out
my_copy(In first, In last, Out out) {
  for (; first != last; ++first)
    *out = *first;
  return out;
}

int main() {
  std::vector<int> vi;
  std::vector<int>::iterator vi_it;

  std::istream_iterator<int> i(std::cin);
  std::istream_iterator<int> i_end;

  // std::back_insert_iterator<std::vector<int>> insert_adapter(vi);
  // my_copy(i, i_end, insert_adapter);
  my_copy(i, i_end, std::back_inserter(vi));

  std::ostream_iterator<int> out(std::cout, " ");
  std::cout<<"\nElementi: ";
  my_copy(vi.begin(), vi.end(), out);
  std::cout<<std::endl;

  /*** Warning! ***
   * vi_it = vi.end();
   * vi.push_back(777);
   * my_copy(vi.begin(), vi_it, out);
   */

  return 0;
}

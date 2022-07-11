// c++ templateTest.cpp -o templateTest
#include <iostream>

template <typename T, typename dummy = T>
struct structTest;

template <typename T>
struct structTest<T, typename std::enable_if<std::is_same<T, unsigned char>::value || std::is_same<T, signed char>::value,T>::type> {
    // std::cout << 42;
};

// template <typename T, typename dummy = T>
// int funTest();

// template <typename T>
// int funTest<T, typename std::enable_if<std::is_same<T, unsigned char>::value || std::is_same<T, signed char>::value,T>::type>() {
//     std::cout << 42;
// };

// template <typename T>
// int test() {
//   return 6;
// }

// template <>
// int test<int>() {
//   return 32;
// }

// template <>
// int test<long>() {
//   return 64;
// }

int main() {
  structTest<signed char> a;
  // funTest<signed char>();

  // std::cout << test<char>() << std::endl;
  // std::cout << test<short>() << std::endl;
  // std::cout << test<int>() << std::endl;
  // std::cout << test<long>() << std::endl;
}
#include <iostream>
#include <typeinfo>

#include "MIPP/src/mipp.h"

template<typename T>
void testMippRegType(std::string str, T val) {
  mipp::Reg<T> reg;
  reg.set1(val);
  std::cout << "mipp::Reg<" << str << "> : " << reg << std::endl;
}

int main(int argc, char** argv)
{
  testMippRegType<int8_t>("int8_t", 26);
  testMippRegType<int16_t>("int16_t", 26);
  testMippRegType<int32_t>("int32_t", 26);
  testMippRegType<int64_t>("int64_t", 26);
  testMippRegType<float>("float", 26.8f);
  testMippRegType<double>("double", 26.8);

  // testMippRegType<char>("int8_t", 26);
  testMippRegType<short>("short", 26);
  testMippRegType<int>("int", 26);
  testMippRegType<long>("long", 26);

  // testMippRegType<uint8_t>("uint8_t", 26);
  // testMippRegType<uint16_t>("uint16_t", 26);
  // testMippRegType<uint32_t>("uint32_t", 26);
  // testMippRegType<uint64_t>("uint64_t", 26);

	return 0;
}

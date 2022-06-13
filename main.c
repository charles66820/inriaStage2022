#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[])
{
  printf("int : %ld\n", sizeof(int));
  printf("float : %ld\n", sizeof(float));
  printf("long : %ld\n", sizeof(long));
  printf("double : %ld\n", sizeof(double));
  printf("short : %ld\n", sizeof(short));
  printf("char : %ld\n", sizeof(char));
  printf("std::uint8_t : %ld\n", sizeof(std::uint8_t));
  printf("std::int8_t : %ld\n", sizeof(std::int8_t));
  printf("std::uint16_t : %ld\n", sizeof(std::uint16_t));
  printf("std::int16_t : %ld\n", sizeof(std::int16_t));
  printf("std::uint32_t : %ld\n", sizeof(std::uint32_t));
  printf("std::int32_t : %ld\n", sizeof(std::int32_t));
  printf("std::uint64_t : %ld\n", sizeof(std::uint64_t));
  printf("std::int64_t : %ld\n", sizeof(std::int64_t));
  return 0;
}








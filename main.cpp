#include <stdio.h>
#include <float.h>
#include <limits.h>
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

  bool b = true;
  unsigned char c = UCHAR_MAX;
  unsigned short s = USHRT_MAX;
  unsigned int i = UINT_MAX;
  unsigned long l = ULONG_MAX;

  float f = FLT_MAX;
  double d = DBL_MAX;

  void* p = &c;
  char* str = "toto";
  char charTab[4] = {'t', 'o', 't', 'o'};

  printf("| |%14s|%14s|%14s|%14s|%14s|%14s|%14s|%14s|%14s|\n", "b", "c", "s", "i", "l", "f", "d", "p", "str");
  printf("|i|%14i|%14hhi|%14hi|%14i|%14li|%14i|%14i|%14i|%14i|\n", b, c, s, i, l, f, d, p, str);
  printf("|u|%14u|%14hhu|%14hu|%14u|%14lu|%14u|%14u|%14u|%14u|\n", b, c, s, i, l, f, d, p, str);
  printf("|d|%14d|%14hhd|%14hd|%14d|%14ld|%14d|%14d|%14d|%14d|\n", b, c, s, i, l, f, d, p, str);
  printf("|x|%14x|%14hhx|%14hx|%14x|%14lx|%14x|%14x|%14x|%14x|\n", b, c, s, i, l, f, d, p, str);
  printf("|X|%14X|%14hhX|%14hX|%14X|%14LX|%14X|%14X|%14X|%14X|\n", b, c, s, i, l, f, d, p, str);
  printf("|o|%14o|%14hho|%14ho|%14o|%14lo|%14o|%14o|%14o|%14o|\n", b, c, s, i, l, f, d, p, str);
  // printf("|c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|\n", b, c, s, i, l, f, d, p, str);
  printf("|p|%14p|%14hhp|%14hp|%14p|%14p|%14p|%14p|%14p|%14p|\n", b, c, s, i, l, f, d, p, str);
  printf("|e|%14e|%14hhe|%14he|%14e|%14e|%14e|%14e|%14e|%14e|\n", b, c, s, i, l, f, d, p, str);
  printf("|E|%14E|%14hhE|%14hE|%14E|%14E|%14E|%14E|%14E|%14E|\n", b, c, s, i, l, f, d, p, str);
  printf("|g|%14g|%14hhg|%14hg|%14g|%14g|%14g|%14g|%14g|%14g|\n", b, c, s, i, l, f, d, p, str);
  printf("|G|%14G|%14hhG|%14hG|%14G|%14G|%14G|%14G|%14G|%14G|\n", b, c, s, i, l, f, d, p, str);
  printf("|a|%14a|%14hha|%14ha|%14a|%14a|%14a|%14a|%14a|\n", 2.5f, -2.5f, FLT_MAX, FLT_MIN, 2.5, -2.5, DBL_MAX, DBL_MAX);
  // printf("|f|%14f|%14f|%14f|%14f|%14f|%14f|%14f|%14f|\n", 2.5f, -2.5f, FLT_MAX, FLT_MIN, 2.5, -2.5, DBL_MAX, DBL_MAX);

  printf("|s14  |%14s|%14s|\n", str, charTab);
  printf("|-14  |%-14s|%-14s|\n", str, charTab);
  printf("|s14.2|%14.2s|%14.2s|\n", str, charTab);
  printf("|-14.2|%-14.2s|%-14.2s|\n", str, charTab);

  printf("\n");

  int len;
  printf("test for %%n in this sen%ntence\n", &len);
  printf("%d\n", len);

  return 0;
}








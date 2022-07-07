// c++ -mavx512f intrinsicsTest.cpp -o intrinsicsTest
#include <immintrin.h>
#include <stdio.h>
#include <iostream>

void printVec256i(std::string msg, __m256i vec) {
  int *ptr = (int*)&vec;
  printf("%-22s = %d %d %d %d %d %d %d %d\n", msg.c_str(), ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7]);
}

void printVec256(std::string msg, __m256 vec) {
  float *ptr = (float*)&vec;
  printf("%-22s = %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", msg.c_str(), ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7]);
}

void printVec256d(std::string msg, __m256d vec) {
  double *ptr = (double*)&vec;
  printf("%-22s = %.1lf %.1lf %.1lf %.1lf\n", msg.c_str(), ptr[0], ptr[1], ptr[2], ptr[3]);
}

void printVec512i(std::string msg, __m512i vec) {
  int *ptr = (int*)&vec;
  printf("%-22s = %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", msg.c_str(), ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8], ptr[9], ptr[10], ptr[11], ptr[12], ptr[13], ptr[14], ptr[15]);
}

void printVec512(std::string msg, __m512 vec) {
  float *ptr = (float*)&vec;
  printf("%-22s = %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", msg.c_str(), ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8], ptr[9], ptr[10], ptr[11], ptr[12], ptr[13], ptr[14], ptr[15]);
}

void printVec512d(std::string msg, __m512d vec) {
  double *ptr = (double*)&vec;
  printf("%-22s = %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf\n", msg.c_str(), ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7]);
}

int main(int argc, char const *argv[])
{
  __m512i veci = _mm512_set1_epi32(6);
  __m512 vec = _mm512_set1_ps(6.4f);
  __m512d vecd = _mm512_set1_pd(6.4);

  __m256i cveci = _mm512_castsi512_si256(veci);
  __m256 cvec = _mm512_castps512_ps256(vec);
  __m256d cvecd = _mm512_castpd512_pd256(vecd);


  __m512i rcveci = _mm512_castsi256_si512(cveci);
  __m512 rcvec = _mm512_castps256_ps512(cvec);
  __m512d rcvecd = _mm512_castpd256_pd512(cvecd);

  __m256i rrcveci = _mm512_castsi512_si256(rcveci);
  __m256 rrcvec = _mm512_castps512_ps256(rcvec);
  __m256d rrcvecd = _mm512_castpd512_pd256(rcvecd);

  printVec512i("origin int vec", veci);
  printVec256i("cast256 int vec", cveci);
  printVec512i("recast512 int vec", rcveci);
  printVec256i("rerecast256 int vec", rrcveci);
  printf("\n");
  printVec512("origin float vec", vec);
  printVec256("cast256 float vec", cvec);
  printVec512("recast512 float vec", rcvec);
  printVec256("rerecast256 float vec", rrcvec);
  printf("\n");
  printVec512d("origin double vec", vecd);
  printVec256d("cast256 double vec", cvecd);
  printVec512d("recast512 double vec", rcvecd);
  printVec256d("rerecast256 double vec", rrcvecd);
  printf("\n");

  printVec512("origin float vec", vec);
  __m256 vec2 = *(__m256 *) &vec;
  printVec256("pcast256 float vec", vec2);
  // __m512 vec3 = *((__m512 *) &vec2); // Segfault

  return 0;
}

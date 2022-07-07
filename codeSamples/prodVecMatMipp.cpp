// clang++ -I../MIPP/src prodVecMatMipp.cpp -o prodVecMatMipp
#include <iostream>
#include <random>
#include <algorithm>

#include "mipp.h"

void printTab(const char* msg, float* tab, int height, int width) {
  std::cout << msg;
  for (auto i = 0; i < height * width; i++) {
    if (i % width == 0 && i != 0)
      std::cout << std::endl;
    std::cout << " " << tab[i] << " ";
  }

  std::cout << std::endl;
}

using type = float;

static mipp::Reg<type> in_vec;
static mipp::Reg<type> in_mat;

void scalarProductLine(type *vec, type *mat, type *vecRes, int i, int width) {
  type tmp[mipp::N<type>()];
	for (auto i = 0; i < mipp::N<type>(); i++) tmp[i] = 0;

  auto vecLoopSize = (width / mipp::N<type>()) * mipp::N<type>();
  for (int j = 0; j < vecLoopSize; j += mipp::N<type>()) {
    in_vec.load(&vec[j]);
    in_mat.load(&mat[i * width + j]);

    auto mul_res = in_vec * in_mat;

    auto tmp_red = mipp::Reduction<type, mipp::add>::apply(mul_res);

    tmp_red.store(&tmp[0]);
    vecRes[i] += tmp[0];
  }

  for (int j = vecLoopSize; j < width; j++) {
    vecRes[i] += vec[j] * mat[i * width + j];
  }
}

void outerProduct(type *vec, type *mat, type *vecRes, int height, int width) {
  mipp::Reg<type> reg_1;
  mipp::Reg<type> reg_2;

  auto heightLoopSize = (height / mipp::N<type>()) * mipp::N<type>();
  auto widthLoopSize = (width / mipp::N<type>()) * mipp::N<type>();

  for (auto i = 0; i < heightLoopSize; i += mipp::N<type>()) {
    reg_1.set0();
    for (auto j = 0; j < widthLoopSize; j += mipp::N<type>()) {
      in_vec.load(&vec[j]);

      for (auto k = 0; k < mipp::N<type>(); k++) {
        type matCol[mipp::N<type>()];
        for (auto l = 0; l < mipp::N<type>(); l++)
          matCol[l] = mat[(i + l) * width + j + k];

        in_mat.load(&matCol[0]);

        reg_2.set1(in_vec[k]);
        reg_1 = mipp::fmadd(in_mat, reg_2, reg_1);
      }
    }
    reg_1.store(&vecRes[i]);
    for (int j = widthLoopSize; j < width; j++) {
      for (auto k = 0; k < mipp::N<type>(); k++) {
        vecRes[i + k] += vec[j] * mat[(i + k) * width + j];
      }
    }
  }

  for (int i = heightLoopSize; i < height; i++)
    scalarProductLine(vec, mat, vecRes, i, width);
}

int main(int argc, char** argv)
{
	std::random_device rd;
	std::mt19937 g(rd());

  int height = 2;
  int width = 5;

	type t_1[width];
	for (auto i = 0; i < width; i++) t_1[i] = i+1;
	std::shuffle(t_1, t_1 + width, g);

	type t_2[height * width];
	for (auto i = 0; i < height * width; i++) t_2[i] = i+1;
	std::shuffle(t_2, t_2 + height * width, g);

	type t_3[height];
	for (auto i = 0; i < height; i++) t_3[i] = 0;

  std::cout << "Inputs :" << std::endl;
  printTab("in_vec =\n", t_1, width, 1);
  printTab("in_mat =\n", t_2, height, width);

  uint64_t start_c, end_c;

  start_c = __rdtsc();

  for (int i = 0; i < height; i++)
    scalarProductLine(t_1, t_2, t_3, i, width);

  end_c = __rdtsc();
  std::cout << end_c - start_c << " ticks" << std::endl;

  printTab("out_res scalar prod =\n", t_3, height, 1);

	for (auto i = 0; i < height; i++) t_3[i] = 0;

  start_c = __rdtsc();
  outerProduct(t_1, t_2, t_3, height, width);
  end_c = __rdtsc();
  std::cout << end_c - start_c << " ticks" << std::endl;

  printTab("out_res outer prod =\n", t_3, height, 1);

	return 0;
}

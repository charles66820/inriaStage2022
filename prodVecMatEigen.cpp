#include <iostream>
#include <random>
#include <algorithm>

#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main()
{
	std::random_device rd;
	std::mt19937 g(rd());

  int height = 3;
  int width = 5;

	double t_1[width];
	for (auto i = 0; i < width; i++) t_1[i] = i+1;
	std::shuffle(t_1, t_1 + width, g);

  double t_2[height * width];
	for (auto i = 0; i < height * width; i++) t_2[i] = i+1;
	std::shuffle(t_2, t_2 + height * width, g);

  MatrixXd mat(height, width);
  for (auto i = 0; i < height * width; i++) mat(i / width, i % width) = t_2[i];

  VectorXd vec(width);
  for (auto i = 0; i < width; i++) vec[i] = t_1[i];

  std::cout << "Inputs : " << std::endl;
  std::cout << "in_vec =\n" << vec << std::endl;
  std::cout << "in_mat =\n" << mat << std::endl;

  auto res = mat * vec;

  std::cout << "out_res of mat*vec =\n" << res << std::endl;
}

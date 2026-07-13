#ifndef DEF_OPERATIONS_HPP
#define DEF_OPERATIONS_HPP
#include <ostream>
#include "Matrix.hpp"

std::ostream &operator<<(std::ostream &Out, const Matrix &matrix);

void power(Matrix& A, const double& n);
Matrix transpose(const Matrix& A);
bool square_matrix(const Matrix& A);
bool check_symmetric(const Matrix& A);
bool check_anti_symmetric(const Matrix& A);


//operator arithmetique
Matrix operator+(const Matrix &A, const Matrix &B);
Matrix operator-(const Matrix &A, const Matrix &B);
Matrix operator*(const Matrix &A, const Matrix &B);
Matrix operator*(const Matrix &A, const double& x);

//operator logique
bool operator==(const Matrix &A, const Matrix &B);
bool operator!=(const Matrix &A, const Matrix &B);

#endif // ! DEF_OPERATIONS_HPP

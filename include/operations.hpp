#ifndef DEF_OPERATIONS_HPP
#define DEF_OPERATIONS_HPP
#include <ostream>
#include "Matrix.hpp"

std::ostream &operator<<(std::ostream &Out, const Matrix &matrix);

void power(Matrix& A, const double& n);
void transpose(Matrix& A);


//operator arithmetique
Matrix operator+(const Matrix &A, const Matrix &B);
Matrix operator-(const Matrix &A, const Matrix &B);
Matrix operator*(const Matrix &A, const Matrix &B);
Matrix operator*(const Matrix &A, const double& x);

#endif // ! DEF_OPERATIONS_HPP

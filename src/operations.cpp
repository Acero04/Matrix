#include "../include/operations.hpp"
#include "../include/Matrix.hpp"
#include <algorithm>
#include <iostream>
#include <vector>


std::ostream &operator<<(std::ostream &Out, const Matrix &matrix) {
    matrix.display(Out);
    return Out;
}
void power(Matrix& A, const double& n) {}

Matrix transpose(const Matrix& A) {
    Matrix temp = A;
    temp.transposition();
    return temp;
}
bool square_matrix(const Matrix& A) {
    return (A.getNumberRow() == A.getNumberColumn());
}
bool check_symmetric(const Matrix& A) {
    if (!square_matrix(A)) {
        std::cerr << "la matrice n'est pas carre.";
        return false;
    } else {
        return (transpose(A) == A);
    }
}
bool check_anti_symmetric(const Matrix& A) {
    if (!square_matrix(A)) {
        std::cerr << "la matrice n'est pas carre.";
        return false;
    } else {
        Matrix temp = A * (-1);
        return (transpose(A) == temp);
    }
}
//OPERATEUR ARITHMETIQUE....
Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix temp = A;
    temp += B;
    return temp;
}
Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix temp = A;
    temp -= B;
    return temp;
}
Matrix operator*(const Matrix &A, const Matrix &B) {
    if (A.getNumberColumn() != B.getNumberRow())
        throw std::runtime_error("impossible de calculer le produit");

    auto copie = A;
    copie *= B;

    return copie;
}

Matrix operator*(const Matrix &A, const double& x) {
    //auto rows = A.getAllLine();

    Matrix copie = A;
    std::vector<std::vector<double>> result;

    for (auto i = 0; i < copie.getNumberRow(); i++) {
        std::vector<double> row = copie.getRow(i);
        std::transform(row.begin(), row.end(), row.begin(), [&](double value) {
            return (value * x);
        });  
        result.push_back(row);
    }
    return Matrix(result);
}

bool operator==(const Matrix &A, const Matrix &B) {
    return A.equal(B);
}
bool operator!=(const Matrix &A, const Matrix &B) {
    return !A.equal(B);
}

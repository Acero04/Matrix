#include "../include/operations.hpp"
#include "../include/Matrix.hpp"
#include <algorithm>
#include <vector>


std::ostream &operator<<(std::ostream &Out, const Matrix &matrix) {
    matrix.display(Out);
    return Out;
}
void power(Matrix& A, const double& n) {
    auto i = 0;
    while (i < n)
        A *= A;
}

//OPERATEUR ARITHMETIQUE...
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

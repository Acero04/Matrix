#include "../include/Matrix.hpp"
#include <algorithm>
#include <vector>
#include <ostream>

const std::vector<double> Matrix::getRow(int i) const {
    return matrix_.at(i);
}

const std::vector<double> Matrix::getColumn(size_t j) const {
    std::vector<double> column;
    for (auto i = 0; i < matrix_.size(); i++) {
        column.push_back(getRow(i).at(j));
    }
    return column;
}
const std::size_t Matrix::getNumberRow() const {   return matrix_.size();    }
const std::size_t Matrix::getNumberColumn() const {   return matrix_.at(0).size();    }

void Matrix::display(std::ostream& Out) const {
    for (const auto &rows : matrix_) {
        Out << "|";
        for (const auto &column : rows) {
            Out << "  " << column << "  ";
        }
        Out << "|";
        Out << "\n";
    }
}
bool Matrix::equal(const Matrix& A) const {
    return matrix_ == A.matrix_;
}

void Matrix::transposition() {
    std::vector<std::vector<double>> result;

    for (auto i = 0; i < matrix_.at(0).size(); i++) {
        result.push_back(getColumn(i));
    }
    matrix_ = result;
    line_ = matrix_.size();
    column_ = matrix_.at(0).size();
}
const double& Matrix::operator()(size_t i, size_t j) const {
    return matrix_.at(i).at(j);
}
Matrix& Matrix::operator+=(const Matrix &M) {
    if (column_ == M.line_) {
    for (auto i = 0; i < line_; i++)
        for (auto j = 0; j < M.column_; j++)
            matrix_.at(i).at(j) += M.matrix_.at(i).at(j);
    } else { 
        throw std::runtime_error("impossible de calculer la somme des matrices.");
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix &M) {
    if (column_ == M.line_) {
    for (auto i = 0; i < line_; i++)
        for (auto j = 0; j < M.column_; j++)
            matrix_.at(i).at(j) -= M.matrix_.at(i).at(j);
    } else { 
        throw std::runtime_error("impossible de calculer la somme des matrices.");
    }
    return *this;
}
Matrix& Matrix::operator*=(const Matrix &B) {
    std::vector<std::vector<double>> result;

    for (auto i = 0; i < matrix_.size(); i++) {
        const std::vector<double>& row = matrix_.at(i);
        std::vector<double> rows_result;

        for (auto j = 0; j < B.getNumberColumn(); j++) {
            const std::vector<double>& column = B.getColumn(j);
            rows_result.push_back(findCoefficient(row, column));
        }
        result.push_back(rows_result);
    }
    assert(result.size() == line_ && result.at(0).size() == B.matrix_.at(0).size() && "resultat de la multiplication incorrect.");
    matrix_ = result;
    column_ = B.column_;
    return *this;
}
Matrix& Matrix::operator*=(const double& x) {
    for (auto& row : matrix_) {
        std::transform(row.begin(), row.end(), row.begin(), [&](const double& value) {
            return ((value == 0) ? 0 : (value * x));
        });
    }
    return *this;
}

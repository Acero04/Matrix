#ifndef DEF_MATRIX_HPP
#define DEF_MATRIX_HPP

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <cassert>

class Matrix {
    private:
        std::vector<std::vector<double>> matrix_;
        std::size_t line_;
        std::size_t column_;


        double findCoefficient(const std::vector<double> &line, const std::vector<double> &column) {
            if (line.size() != column.size())
                throw std::runtime_error("Impossible de calculer le produit scalaire.");

            double weight = 0.0;
            for (auto i = 0; i < line.size(); i++)
                weight += (line.at(i) * column.at(i));

            return weight;
        }

    public:
        template <typename... Rows> 
        Matrix(std::initializer_list<Rows>... rows) {
            (matrix_.push_back([](auto element) {
                std::vector<double> temp;
                temp.assign(element.begin(), element.end());
                return temp;
            }(rows)), ...);
            line_ = matrix_.size();
            column_ = line_ > 0 ? matrix_.at(0).size() : 0;

            for (const auto &line : matrix_) {
                if (line.size() != column_)
                    throw std::invalid_argument("nombre de colonnes differentes");
            }
        }
        Matrix(std::vector<std::vector<double>> arg) : line_(arg.size()) {
           
            matrix_ = arg;
            line_ = matrix_.size();
            column_ = line_ > 0 ? matrix_.at(0).size() : 0;
            for (const auto &line : matrix_)
                if (line.size() != column_)
                    throw std::invalid_argument("nombre de colonnes differentes");
        }
        Matrix() : line_(0), column_(0) {};

        Matrix(int line, int column, double defautValue = 0.0) : line_(line), column_(column) {
            int i = 0;
            while (i < line) {
                std::vector<double> temp(column_, defautValue);
                matrix_.push_back(temp);
                i++;
            }
        }

        const std::vector<double>& getRow(int i) const;
        const std::vector<double> getColumn(size_t j) const;

        const std::size_t getNumberRow() const;
        const std::size_t getNumberColumn() const;

        void display(std::ostream& Out) const;
        void transposition();
        const double& operator()(size_t i, size_t j) const;
        Matrix& operator+=(const Matrix &M);
        Matrix& operator-=(const Matrix &M);
        Matrix& operator*=(const Matrix &B);
};

#endif // !DEF_MATRIX_HPe

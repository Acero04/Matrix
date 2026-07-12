#include "../include/Matrix.hpp"
#include "../include/operations.hpp"
#include <iostream>

int main() {
    Matrix A({-6, 0},{1, 0});
    Matrix B({0, 0}, {-2, 2});


    //std::cout << A << "\n";
    //std::cout << B << "\n";
    //Matrix C = B * A;

    Matrix C = A * B;
    std::cout << C << "\n";
    C = B * A;
    std::cout << C << "\n";
    C = A + B;
    std::cout << C << "\n";
    C = A - B;
    std::cout << C << "\n";



    //std::cout << C << std::endl;
}

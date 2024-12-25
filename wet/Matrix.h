#ifndef H_MATRIX_H
#define H_MATRIX_H
#include <iostream>
class Matrix {
public:
    Matrix();

    Matrix(int rows, int cols, int value = 0);

    // Copy constructor: creates a copy of another Matrix object
    Matrix(const Matrix& other);

    // Copy assignment operator: assigns one Matrix to another
    Matrix& operator=(const Matrix& other);

    // Getter and setter using operator()
    int& operator()(int i, int j);  // Non-const version (for writing)
    int operator()(int i, int j) const;  // Const version (for reading)

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
private:
    int row;
    int column;
    int* data;
};

#endif

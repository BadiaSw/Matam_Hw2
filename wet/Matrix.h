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
    Matrix operator-(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix& operator-=(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix operator*(int scalar) const;
   friend Matrix operator*(int scalar, const Matrix& matrix);
    Matrix& operator*=(int scalar);
    Matrix operator-() const;
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
    Matrix rotateClockwise() const;
    Matrix rotateCounterClockwise() const;
    Matrix transpose() const;
    static double CalcFrobeniusNorm(const Matrix& mat);
private:
    int row;
    int column;
    int* data;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif

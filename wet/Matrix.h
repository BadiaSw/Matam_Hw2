#ifndef H_MATRIX_H
#define H_MATRIX_H
#include <iostream>

class Matrix {
public:
    // Default constructor: Initializes a 0x0 matrix (empty matrix).
    Matrix();

    // Destructor: Frees the memory used by the matrix data.
    ~Matrix();

    // Parameterized constructor: Initializes a matrix with given rows, columns, and a default value.
    Matrix(int rows, int cols, int value = 0);

    // Copy constructor: Creates a deep copy of another Matrix object.
    Matrix(const Matrix& other);
   
    // Copy assignment operator: Assigns the content of one Matrix to another.
    Matrix& operator=(const Matrix& other);

    // Accessor and mutator using operator(): 
    int& operator()(int i, int j);  // Non-const version (for setting values)
    int operator()(int i, int j) const;  // Const version (for reading values)

    // Arithmetic operators:
    Matrix operator-(const Matrix& other) const;  // Matrix subtraction
    Matrix operator+(const Matrix& other) const;  // Matrix addition
    Matrix operator*(const Matrix& other) const;  // Matrix multiplication
    Matrix& operator-=(const Matrix& other);  // Subtract and assign
    Matrix& operator+=(const Matrix& other);  // Add and assign
    Matrix& operator*=(const Matrix& other);  // Multiply and assign
    Matrix operator*(int scalar) const;  // Scalar multiplication

    // Friend function for scalar multiplication
    friend Matrix operator*(int scalar, const Matrix& matrix);

    // Scalar multiplication and assignment
    Matrix& operator*=(int scalar);

    // Unary minus operator: Negates all elements of the matrix
    Matrix operator-() const;

    // Comparison operators:
    bool operator==(const Matrix& other) const;  // Check if matrices are equal
    bool operator!=(const Matrix& other) const;  // Check if matrices are not equal

    // Matrix transformations:
    Matrix rotateClockwise() const;  // Rotates the matrix clockwise
    Matrix rotateCounterClockwise() const;  // Rotates the matrix counter-clockwise
    Matrix transpose() const;  // Transposes the matrix

    // Static function: Calculates the Frobenius norm of the matrix
    static double CalcFrobeniusNorm(const Matrix& mat);

private:
    int row;  // Number of rows in the matrix
    int column;  // Number of columns in the matrix
    int* data;  // Pointer to the matrix data (array of integers)

    // Friend function to output the matrix in a readable format
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif

#include "Matrix.h"
#include "Utilities.h"
#include <iostream>
#include <math.h>

// Default constructor: initializes a matrix with 0 rows and 0 columns
Matrix::Matrix() : row(0), column(0), data(nullptr) {
    // No memory allocation, since it's a 0x0 matrix (empty)
}

// Parameterized constructor: initializes the matrix with given rows, columns and value
Matrix::Matrix(int rows, int cols, int value) : row(rows), column(cols) {
    data = new int[row * column];  // Allocate memory for the matrix
    for (int i = 0; i < row * column; ++i) {
        data[i] = value;  // Initialize all elements with the value
    }
}

// Copy constructor: creates a deep copy of another matrix
Matrix::Matrix(const Matrix& other) : row(other.row), column(other.column) {
    if (row * column > 0) {
        data = new int[row * column];  // Allocate memory for the new matrix
        for (int i = 0; i < row * column; ++i) {
            data[i] = other.data[i];  // Copy the data from the other matrix
        }
    } else {
        data = nullptr;  // If the matrix is empty, set data to nullptr
    }
}

// Assignment operator: assigns the values of another matrix to the current matrix
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {  // Check for self-assignment
        return *this;
    }
    delete[] data;  // Free the existing memory
    row = other.row;
    column = other.column;
    data = new int[row * column];  // Allocate new memory
    for (int i = 0; i < row * column; ++i) {
        data[i] = other.data[i];  // Copy the data from the other matrix
    }
    return *this;
}

// Non-const version of operator() (for setting a value)
int& Matrix::operator()(int i, int j) {
    // Bounds check
    if (i < 0 || i >= row || j < 0 || j >= column) {
        exitWithError(MatamErrorType::OutOfBounds);  // Handle out-of-bounds access
    }
    return data[j + column * i];  // Access the element at (i, j)
}

// Const version of operator() (for getting a value)
int Matrix::operator()(int i, int j) const {
    // Bounds check
    if (i < 0 || i >= row || j < 0 || j >= column) {
        exitWithError(MatamErrorType::OutOfBounds);  // Handle out-of-bounds access
    }
    return data[j + column * i];  // Access the element at (i, j)
}

// Overload the << operator to print the matrix
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.row; ++i) {
        os << "|";  // Start each row with a vertical line
        for (int j = 0; j < matrix.column; ++j) {
            os << matrix(i, j);  // Access the element at (i, j)
            if (j < matrix.column - 1) {
                os << "|";  // Place a separator '|' between elements
            }
        }
        os << "|" << std::endl;  // End the row with a vertical line and move to the next line
    }
    return os;  // Return the ostream object for chained usage (like cout << matrix)
}

// Matrix subtraction operator: subtracts another matrix from the current matrix
Matrix Matrix::operator-(const Matrix& other) const {
    if (row != other.row || column != other.column) {
         exitWithError(MatamErrorType::UnmatchedSizes);  // Handle matrix size mismatch
    }
    Matrix result(row, column, 0);  // Create a new matrix to store the result
    for (int i = 0; i < row * column; ++i) {
        result.data[i] = data[i] - other.data[i];  // Subtract corresponding elements
    }
    return result;
}

// Matrix addition operator: adds another matrix to the current matrix
Matrix Matrix::operator+(const Matrix& other) const {
    if (row != other.row || column != other.column) {
        exitWithError(MatamErrorType::UnmatchedSizes);  // Handle matrix size mismatch
    }
    Matrix result(row, column, 0);  // Create a new matrix to store the result
    for (int i = 0; i < row * column; ++i) {
        result.data[i] = data[i] + other.data[i];  // Add corresponding elements
    }
    return result;
}

// Matrix multiplication operator: multiplies the current matrix by another matrix
Matrix Matrix::operator*(const Matrix& other) const {
    if (column != other.row) {
        exitWithError(MatamErrorType::UnmatchedSizes);  // Handle matrix multiplication size mismatch
    }
    Matrix result(row, other.column, 0);  // Create a new matrix to store the result
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.column; ++j) {
            for (int k = 0; k < column; ++k) {
                result(i, j) += (*this)(i, k) * other(k, j);  // Perform matrix multiplication
            }
        }
    }
    return result;
}

// Matrix subtraction assignment operator: subtracts another matrix and assigns the result
Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;  // Use the subtraction operator to perform the operation
    return *this;
}

// Matrix addition assignment operator: adds another matrix and assigns the result
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;  // Use the addition operator to perform the operation
    return *this;
}

// Matrix multiplication assignment operator: multiplies by another matrix and assigns the result
Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;  // Use the multiplication operator to perform the operation
    return *this;
}

// Matrix scalar multiplication operator: multiplies the matrix by a scalar value
Matrix Matrix::operator*(int scalar) const {
    Matrix result(row, column, 0);  // Create a new matrix to store the result
    for (int i = 0; i < row * column; ++i) {
        result.data[i] = data[i] * scalar;  // Multiply each element by the scalar
    }
    return result;
}

// Scalar matrix multiplication operator (non-member): multiplies a matrix by a scalar value
Matrix operator*(int scalar, const Matrix& matrix) {
    return matrix * scalar;  // Use the matrix scalar multiplication operator
}

// Matrix scalar multiplication assignment operator: multiplies by a scalar value and assigns the result
Matrix& Matrix::operator*=(int scalar) {
    for (int i = 0; i < row * column; ++i) {
        data[i] *= scalar;  // Multiply each element by the scalar
    }
    return *this;
}

// Matrix negation operator: negates the matrix (multiplies each element by -1)
Matrix Matrix::operator-() const {
    return *this * -1;  // Multiply the matrix by -1
}

// Matrix equality operator: checks if two matrices are equal
bool Matrix::operator==(const Matrix& other) const {
    if (row != other.row || column != other.column) {
        return false;  // Return false if matrices have different sizes
    }
    for (int i = 0; i < row * column; ++i) {
        if (data[i] != other.data[i]) {
            return false;  // Return false if any corresponding elements are different
        }
    }
    return true;  // Return true if all elements are equal
}

// Matrix inequality operator: checks if two matrices are not equal
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);  // Return true if matrices are not equal
}

// Rotate the matrix 90 degrees clockwise
Matrix Matrix::rotateClockwise() const {
    Matrix result(column, row, 0);  // Create a new matrix with swapped rows and columns
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result(j, row - 1 - i) = (*this)(i, j);  // Perform the rotation
        }
    }
    return result;
}

// Rotate the matrix 90 degrees counter-clockwise
Matrix Matrix::rotateCounterClockwise() const {
    Matrix result(column, row, 0);  // Create a new matrix with swapped rows and columns
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result(column - 1 - j, i) = (*this)(i, j);  // Perform the rotation
        }
    }
    return result;
}

// Transpose the matrix (swap rows and columns)
Matrix Matrix::transpose() const {
    Matrix result(column, row, 0);  // Create a new matrix with swapped rows and columns
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result(j, i) = (*this)(i, j);  // Perform the transposition
        }
    }
    return result;
}

// Calculate the Frobenius norm of the matrix (the square root of the sum of squares of all elements)
double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {
    double sum = 0.0;
    for (int i = 0; i < matrix.row * matrix.column; ++i) {
        sum += matrix.data[i] * matrix.data[i];  // Sum the squares of all elements
    }
    return sqrt(sum);  // Return the square root of the sum
}

// Destructor: deallocates the memory used by the matrix
Matrix::~Matrix() {
    delete[] data;  // Free the allocated memory for the matrix data
}

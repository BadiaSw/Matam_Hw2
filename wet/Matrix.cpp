#include "Matrix.h"
#include "Utilities.h"
#include <iostream>

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

Matrix::Matrix(const Matrix& other) : row(other.row), column(other.column) {
            data = new int[row * column];  // Allocate new memory
        // Copy the data from the original matrix
        for (int i = 0; i < row * column; ++i) {
            data[i] = other.data[i];  // Copy data from the original matrix
        }
    }


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
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return data[j + column * i];  // Access the element at (i, j)
}

// Const version of operator() (for getting a value)
int Matrix::operator()(int i, int j) const {
    // Bounds check
    if (i < 0 || i >= row || j < 0 || j >= column) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return data[j + column * i];  // Access the element at (i, j)
}

// Define the << operator
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


#include "MataMvidia.h"
#include "Matrix.h"



MataMvidia::MataMvidia(string Name, string Producer, Matrix* Frames, int Size):name(Name),producer(Producer),size(Size)
{
   frames = new Matrix[Size];
for (int i = 0; i < Size; ++i) {
    frames[i] = Frames[i];
}
}
MataMvidia::MataMvidia(const MataMvidia& other)
    : name(other.name), producer(other.producer), size(other.size) {
    frames = new Matrix[size];
    for (int i = 0; i < size; ++i) {
        frames[i] = other.frames[i];
    }
}


MataMvidia& MataMvidia::operator+=(const MataMvidia& other) {
    Matrix* newFrames = new Matrix[size + other.size];
    for (int i = 0; i < size; ++i) {
        newFrames[i] = frames[i];
    }
    for (int i = 0; i < other.size; ++i) {
        newFrames[size + i] = other.frames[i];
    }
    delete[] frames;
    frames = newFrames;
    size += other.size;
    return *this;
}

// Operator [] to access individual frames (read and write)
Matrix& MataMvidia::operator[](int index) {
    return frames[index];
}
MataMvidia& MataMvidia::operator+=(const Matrix& matrix) {
    // Allocate a new array with one extra space
    Matrix* newFrames = new Matrix[size + 1];
    
    // Copy the existing frames
    for (int i = 0; i < size; ++i) {
        newFrames[i] = frames[i];
    }
    
    // Add the new matrix at the end
    newFrames[size] = matrix;

    // Delete the old array
    delete[] frames;

    // Update the frames pointer and size
    frames = newFrames;
    size += 1;

    return *this;
}

MataMvidia MataMvidia::operator+(const MataMvidia& other){

MataMvidia result(*this);
return(result+=other);
}
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

MataMvidia::~MataMvidia() {
    delete []frames;
}

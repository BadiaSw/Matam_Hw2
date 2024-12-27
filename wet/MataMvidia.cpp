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
std::ostream& operator<<(std::ostream& os, const MataMvidia& movie) {
    // Print movie name and producer
    os << "Movie Name: " << movie.name << "\n";
    os << "Author: " << movie.producer << "\n";
    os<<"\n";
    // Iterate through all frames and print each one
    for (int i = 0; i < movie.size; ++i) {
        os << "Frame " << i << ":\n";
        os << movie.frames[i]<<"\n";  // Assuming Matrix already implements << operator
    }

    // Print the end of the movie
    os << "-----End of Movie-----\n";
    return os;
}
MataMvidia::~MataMvidia() {
    delete []frames;
}
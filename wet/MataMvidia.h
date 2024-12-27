#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H

#include <string.h>
#include "Matrix.h"
#include <iostream>

using namespace std;

// Class representing a MataMvidia (movie) consisting of frames (Matrix)
class MataMvidia {

public:
    
    // Constructor: Initializes movie with a name, producer, frames, and size.
    MataMvidia(string Name, string Producer, Matrix* Frames, int Size);
    
    // Copy constructor: Creates a deep copy of another MataMvidia object.
    MataMvidia(const MataMvidia& other);
    
    // Destructor: Frees memory for frames array.
    ~MataMvidia();
    
    // Access individual frames by index.
    Matrix& operator[](int index);
    
    // Appends frames from another MataMvidia to this one.
    MataMvidia& operator+=(const MataMvidia& other);
    
    // Adds a single frame to the movie.
    MataMvidia& operator+=(const Matrix& matrix);
    
    // Combines frames of two MataMvidias.
    MataMvidia operator+(const MataMvidia& other);

private:
    string name;  // Movie name
    string producer;  // Movie producer
    Matrix* frames;  // Array of frames
    int size;  // Number of frames

    // Friend function to output the movie's details.
    friend std::ostream& operator<<(std::ostream& os, const MataMvidia& movie);
};

#endif 

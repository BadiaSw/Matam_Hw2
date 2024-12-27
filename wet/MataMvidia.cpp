#include "MataMvidia.h"
#include "Matrix.h"

// Constructor: Initializes a MataMvidia object with a name, producer, an array of frames, and the size of the frames array
MataMvidia::MataMvidia(string Name, string Producer, Matrix* Frames, int Size) : name(Name), producer(Producer), size(Size) {
    frames = new Matrix[Size];  // Allocate memory for the frames array
    for (int i = 0; i < Size; ++i) {
        frames[i] = Frames[i];  // Copy each frame from the provided array
    }
}

// Copy constructor: Creates a deep copy of another MataMvidia object
MataMvidia::MataMvidia(const MataMvidia& other) : name(other.name), producer(other.producer), size(other.size) {
    frames = new Matrix[size];  // Allocate memory for the frames array
    for (int i = 0; i < size; ++i) {
        frames[i] = other.frames[i];  // Copy each frame from the other object
    }
}

// += operator: Appends the frames of another MataMvidia object to the current one
MataMvidia& MataMvidia::operator+=(const MataMvidia& other) {
    Matrix* newFrames = new Matrix[size + other.size];  // Create a new array to hold the combined frames
    for (int i = 0; i < size; ++i) {
        newFrames[i] = frames[i];  // Copy the current frames into the new array
    }
    for (int i = 0; i < other.size; ++i) {
        newFrames[size + i] = other.frames[i];  // Append the frames from the other object
    }
    delete[] frames;  // Delete the old frames array to prevent memory leak
    frames = newFrames;  // Update the frames pointer to the new array
    size += other.size;  // Update the size of the frames array
    return *this;  // Return the updated object
}

// [] operator: Allows access to individual frames by index (read and write)
Matrix& MataMvidia::operator[](int index) {
    return frames[index];  // Return the frame at the specified index
}

// += operator: Adds a new frame (Matrix) to the current MataMvidia object
MataMvidia& MataMvidia::operator+=(const Matrix& matrix) {
    Matrix* newFrames = new Matrix[size + 1];  // Create a new array with one extra space for the new frame
    
    for (int i = 0; i < size; ++i) {
        newFrames[i] = frames[i];  // Copy the existing frames into the new array
    }
    
    newFrames[size] = matrix;  // Add the new frame at the end of the array
    
    delete[] frames;  // Delete the old frames array to prevent memory leak
    
    frames = newFrames;  // Update the frames pointer to the new array
    size += 1;  // Increase the size of the frames array by 1
    
    return *this;  // Return the updated object
}

// + operator: Adds the frames of two MataMvidia objects together and returns the result
MataMvidia MataMvidia::operator+(const MataMvidia& other) {
    MataMvidia result(*this);  // Create a copy of the current object
    return result += other;  // Use the += operator to combine the frames of the two objects and return the result
}

// << operator: Overloads the output stream operator to print the details of the MataMvidia object
std::ostream& operator<<(std::ostream& os, const MataMvidia& movie) {
    os << "Movie Name: " << movie.name << "\n";  // Print the name of the movie
    os << "Author: " << movie.producer << "\n";  // Print the name of the producer
    os << "\n";
    
    // Iterate through all frames and print each one
    for (int i = 0; i < movie.size; ++i) {
        os << "Frame " << i << ":\n";
        os << movie.frames[i] << "\n";  // Assuming the Matrix class already implements the << operator
    }
    
    // Print the end of the movie
    os << "-----End of Movie-----\n";
    return os;  // Return the ostream object for chained usage
}

// Destructor: Deallocates memory for the frames array when the object is destroyed
MataMvidia::~MataMvidia() {
    delete[] frames;  // Free the allocated memory for frames
}

#include "MataMvidia.h"
#include "Matrix.h"



MataMvidia::MataMvidia(string Name, string Producer, Matrix* Frames, int Size):name(Name),producer(Producer),size(Size)
{
    frames = new Matrix(*Frames);
}
MataMvidia::MataMvidia(const MataMvidia& other):name(other.name),producer(other.producer),size(other.size)
{
    frames=new Matrix(*other.frames);
}
// Operator [] to access individual frames (read and write)
Matrix& MataMvidia::operator[](int index) {
    return frames[index];
}
MataMvidia& MataMvidia::operator+=(const MataMvidia& other) {
    // Concatenate frames from `other` at the end of current `frames`
    size+=other.size;
    *frames+=*other.frames;
    
    return *this;
}
MataMvidia& MataMvidia::operator+=(const Matrix& matrix) {
    size+=1;
    *frames+=matrix;
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

    // Iterate through all frames and print each one
    for (int i = 0; i < movie.size; ++i) {
        os << "Frame " << i << ":\n";
        os << movie.frames[i];  // Assuming Matrix already implements << operator
    }

    // Print the end of the movie
    os << "-----End of Movie -----\n";
    return os;
}
MataMvidia::~MataMvidia() {
    delete frames;
}
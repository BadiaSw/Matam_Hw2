#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H
#include <string.h>
#include "Matrix.h"
#include <iostream>

using namespace std;
class MataMvidia{

public:
    MataMvidia(string Name,string Producer,Matrix* Frames,int Size);
     MataMvidia(const MataMvidia& other);
     ~MataMvidia();
    Matrix& operator[](int index);
    MataMvidia& operator+=(const MataMvidia& other);
     MataMvidia& operator+=(const Matrix& matrix);
     MataMvidia operator+(const MataMvidia& other);
    




private:
 string name;
 string producer;
 Matrix* frames;
 int size;
friend std::ostream& operator<<(std::ostream& os, const MataMvidia& MataMvidia);





};























#endif//MATAMVIDIA_H;
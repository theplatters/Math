#include <iostream>
#include "Z.h"
#include "Polynomial.h"
int main() {
    Polynomial<int> a = {{0,1},{1,2},{2,1}};
    Polynomial<int> b = {{0,-1},{2,1}};


    std::cout << a % b;
}

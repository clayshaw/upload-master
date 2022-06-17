#include"matrix.h"
#include<iostream>

int main(){
    using namespace _matrix;
    int a[12]{1,2,3,4,5,6,7,8,9,10,11,12};
    matrix m = matrix(3,4,a);
    matrix n = matrix(3,4,a);
    matrix b = (m-n);
    matrix c = (m+n);
    std::cout<<"m="<<m<<" n="<<m<<"\n";
    std::cout<<"b="<<b<<" c="<<c<<"\n";

    return 0;
}
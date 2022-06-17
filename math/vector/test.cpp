#include<iostream>
#include"vector.h"


int main(){
    using namespace _vector;

    vector a(1,-1,3);
    vector b(1,2,3);
    vector c(5,-1,6);
    std::cout<<a<<"\n";
    std::cout<<b<<"\n";
    
    std::cout<<"a.length() = "<<a.length()<<"\n";
    std::cout<<"a.angle(b) = "<<a.angle(b)<<"\n";
    std::cout<<"a.radius(b) = "<<a.radius(b)<<"\n";
    std::cout<<"a.cos(b) = "<<a.cos(b)<<"\n";
    std::cout<<"a.sin(b) = "<<a.sin(b)<<"\n\n";
    std::cout<<"a.tan(b) = "<<a.tan(b)<<"\n";

    std::cout<<"b.length() = "<<b.length()<<"\n";
    std::cout<<"b.angle(a) = "<<b.angle(a)<<"\n";
    std::cout<<"b.radius(a) = "<<b.radius(a)<<"\n";
    std::cout<<"b.cos(a) = "<<b.cos(a)<<"\n";
    std::cout<<"b.sin(a) = "<<b.sin(a)<<"\n";
    std::cout<<"b.tan(a) = "<<b.tan(a)<<"\n";
    
    return 0;
}
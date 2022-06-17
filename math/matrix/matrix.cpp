#include"matrix.h"
#include<iostream>

using namespace _matrix;

matrix::matrix(){
    this->top = nullptr;
    this->m = 0;
    this->n = 0;
}

matrix::matrix(int m,int n,int *val){
    
    if(m==0 || n==0 || val==nullptr){
        this->top = nullptr;
        this->m = 0;
        this->n = 0;
        return;
    }
    this->m = m;
    this->n = n;  

    this->top = new matrix_data;
    matrix_data *cur = this->top;
    cur->down = nullptr;
    cur->right = nullptr;
    for(int i=0;i<m;i++){
        matrix_data *tmp = cur;
        for(int j=0;j<n;j++){
            tmp->val = val[n*i+j];
            // std::cout<<tmp->val<<" ";
            if(j!=n-1){
                tmp->right = new matrix_data;
                tmp->right->right = nullptr;
                tmp->right->down = nullptr;
                tmp = tmp->right;
            }
            
        }
        // std::cout<<"\n";
        if(i!=m-1){
            cur->down = new matrix_data;
            cur->down->right = nullptr;
            cur->down->down = nullptr;
            cur = cur->down;
        }
        
    }
}

matrix::matrix(const matrix &a){
    // std::cout<<"use\n";
    this->m = a.m;
    this->n = a.n;
    this->top = nullptr;
    
    // std::cout<<"*this="<<*this<<"\n";
    // std::cout<<"a="<<a<<"\n";
    this->top = new matrix_data;
    this->top->down = nullptr;
    this->top->right = nullptr;

    matrix_data * cur = this->top;
    matrix_data * cur2 = a.top;
    

    while(cur2 != nullptr){
        matrix_data *tmp = cur;
        matrix_data *tmp2 = cur2;
        while(tmp2 != nullptr){

            tmp->val = tmp2->val;
            // std::cout<<tmp2<<" and "<<tmp<<"     ";
            // std::cout<<tmp->val<<" ";
            if(tmp2->right != nullptr){
                tmp->right = new matrix_data;
                tmp = tmp->right;
                tmp->down = nullptr;
                tmp->right = nullptr;
                tmp2 = tmp2->right;
            } else {
                break;
            }

        }
        // std::cout<<"\n";
        if(cur2->down != nullptr){
            cur->down = new matrix_data;
            cur = cur->down;
            cur->right = nullptr;
            cur->down = nullptr;
            cur2 = cur2->down;
        } else {
            break;
        }
        // std::cout<<"\n";
    }
    // std::cout<<this->top<<"\n";
    

}

matrix::~matrix(){
    matrix_data * cur = this->top;
    while(cur != nullptr){
        matrix_data *tmp = cur;
        while(tmp != nullptr){
            // std::cout<<tmp->val<<" ";
            matrix_data *del = tmp;
            tmp = tmp->right;
            delete del;
        }
        // std::cout<<"\n";
        cur = cur->down;
    }
}

int matrix::linear_search(int a,int b){
    if(a>this->m || b>this->n){
        // std::cout<<"m="<<this->m<<" n="<<this->n<<"\n";
        // std::cout<<(int)(a>this->m)<<" "<<(int)(b>this->n)<<"\n";
        return -1;
    }
    matrix_data *cur = this->top;
    for(int i=0;i<a-1;i++){
        cur = cur->down;
    }
    for(int i=0;i<b-1;i++){
        cur = cur->right;
    }
    return cur->val;
}

matrix matrix::operator*(matrix &a){
    // std::cout<<"this="<<(*this)<<"a="<<a<<"\n";
    // std::cout<<"this->n="<<this->n<<" a.m="<<a.m<<"\n";
    if(this->n != a.m){
        std::cout<<"error\n";
        return matrix(0,0,nullptr);
    }
    matrix res(this->m,a.n,nullptr);
    // std::cout<<"res="<<res<<"\n"; 
    res.top = new matrix_data;
    matrix_data *cur = res.top;
    matrix_data *tt = this->top;
    for(int i=0;i<this->m;i++){
        matrix_data *tmp = cur; 
        for(int j=0;j<a.n;j++){
            tmp->val = 0;
            matrix_data *tmp2 = tt;
            for(int k=0;k<this->n;k++){
                tmp->val += tmp2->val * a.linear_search(k+1,j+1);
                tmp2 = tmp2->right;
            }
            
            if(j!=a.n-1){
                tmp->right = new matrix_data;
                tmp->right->right = nullptr;
                tmp->right->down = nullptr;
                tmp = tmp->right;
            }
        }
        if(i!=this->m-1){
            cur->down = new matrix_data;
            cur->down->right = nullptr;
            cur->down->down = nullptr;
            cur = cur->down;
        }
        tt = tt->down;
    }
    // std::cout<<"res="<<res<<"\n";
    return res;
}

matrix matrix::operator=(const matrix &a){
    this->m = a.m;
    this->n = a.n;
    this->top = nullptr;
    
    // std::cout<<"*this="<<*this<<"\n";
    // std::cout<<"a="<<a<<"\n";
    this->top = new matrix_data;
    this->top->down = nullptr;
    this->top->right = nullptr;

    matrix_data * cur = this->top;
    matrix_data * cur2 = a.top;
    

    while(cur2 != nullptr){
        matrix_data *tmp = cur;
        matrix_data *tmp2 = cur2;
        while(tmp2 != nullptr){

            tmp->val = tmp2->val;
            // std::cout<<tmp2<<" and "<<tmp<<"     ";
            // std::cout<<tmp->val<<" ";
            if(tmp2->right != nullptr){
                tmp->right = new matrix_data;
                tmp = tmp->right;
                tmp->down = nullptr;
                tmp->right = nullptr;
                tmp2 = tmp2->right;
            } else {
                break;
            }

        }
        // std::cout<<"\n";
        if(cur2->down != nullptr){
            cur->down = new matrix_data;
            cur = cur->down;
            cur->right = nullptr;
            cur->down = nullptr;
            cur2 = cur2->down;
        } else {
            break;
        }
        // std::cout<<"\n";
    }
    return *this;
}

matrix matrix::operator+(matrix &a){
    if(this->m != a.m || this->n != a.n){
        std::cout<<"error\n";
        return matrix(0,0,nullptr);
    }
    matrix res(this->m,this->n,nullptr);
    res.top = new matrix_data;
    matrix_data *cur = res.top;
    matrix_data *tt = this->top;
    matrix_data *tmp2 = tt;
    for(int i=0;i<this->m;i++){
        matrix_data *tmp = cur; 
        for(int j=0;j<this->n;j++){
            tmp->val = tt->val + a.linear_search(i+1,j+1);
            if(j!=this->n-1){
                tmp->right = new matrix_data;
                tmp->right->right = nullptr;
                tmp->right->down = nullptr;
                tmp = tmp->right;
                
            }
            tt = tt->right;
        }
        if(i!=this->m-1){
            cur->down = new matrix_data;
            cur->down->right = nullptr;
            cur->down->down = nullptr;
            cur = cur->down;
        }
        tt = tmp2->down;
        tmp2 = tmp2->down;
    }
    return res;
}

matrix matrix::operator-(matrix &a){
    if(this->m != a.m || this->n != a.n){
        std::cout<<"error\n";
        return matrix(0,0,nullptr);
    }
    matrix res(this->m,this->n,nullptr);
    res.top = new matrix_data;
    matrix_data *cur = res.top;
    matrix_data *tt = this->top;
    matrix_data *tmp2 = tt;
    for(int i=0;i<this->m;i++){
        matrix_data *tmp = cur; 
        for(int j=0;j<this->n;j++){
            tmp->val = tt->val - a.linear_search(i+1,j+1);
            if(j!=this->n-1){
                tmp->right = new matrix_data;
                tmp->right->right = nullptr;
                tmp->right->down = nullptr;
                tmp = tmp->right;
                
            }
            tt = tt->right;
        }
        if(i!=this->m-1){
            cur->down = new matrix_data;
            cur->down->right = nullptr;
            cur->down->down = nullptr;
            cur = cur->down;
        }
        tt = tmp2->down;
        tmp2 = tmp2->down;
    }
    return res;
}

matrix matrix::operator*=(matrix &a){
    *this = *this * a;
    return *this;
}

matrix matrix::operator+=( matrix &a){
    *this = *this + a;
    return *this;
}

matrix matrix::operator-=( matrix &a){
    *this = *this - a;
    return *this;
}


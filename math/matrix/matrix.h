#include<iostream>

namespace _matrix
{
    typedef struct matrix_data
    {
        /* data */
        int val;
        struct matrix_data *right;
        struct matrix_data *down;
        
    }matrix_data;
    
    class matrix
    {
    private:
        /* data */
        int m,n;
        matrix_data *top;
    public:
        matrix(/* args */);
        matrix(int ,int ,int *);
        matrix(const matrix &);
        ~matrix();

        int linear_search(int,int);

        matrix operator*( matrix &);
        matrix operator+( matrix &);
        matrix operator-( matrix &);
        matrix operator=(const matrix &);
        matrix operator+=( matrix &);
        matrix operator-=( matrix &);
        matrix operator*=( matrix &);

        matrix_data *get_top(){return this->top;}

        friend std::ostream & operator<<(std::ostream &os,const matrix &a){
            if(a.top == nullptr){
                os<<"Empty\n";
                os<<"m="<<a.m<<" n="<<a.n<<"\n";
                return os;
            }
            matrix_data * cur = a.top;
            while(cur != nullptr){
                matrix_data *tmp = cur;
                while(tmp != nullptr){
                    std::cout<<tmp->val<<" ";
                    tmp = tmp->right;
                }
                std::cout<<"\n";
                cur = cur->down;
            }
            return os;
        }
    };
    
} // namespace matrix

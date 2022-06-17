#include"big_int.h"
#include<iostream>


using namespace _big_int;
using std::getline;
using std::cout;


int main(){
    
    std::string s;


    while(getline(std::cin,s)){
        int i=1;
        std::string tmp;
        tmp+=s.at(0);
        big_int m;
        char p;
        while(s.at(i)<='9' && s.at(i)>='0'){
            tmp+=s.at(i);
            i++;
        }
        // cout<<"tmp="<<tmp<<"\n";
        m = big_int(tmp);
        tmp = "";
        p=s.at(i);
        i++;
        // cout<<"i="<<i<<"\n";
        // cout<<s<<"\n";
        s.erase(0,i);
        // cout<<s<<"\n";
        big_int n = big_int(s);
        
        

        // cout<<m<<p<<n;

        cout<<"=";
        switch (p)
        {
        case '+':
            cout<<(m+n);
            /* code */
            break;
        case '-':
            cout<<m-n;
            /* code */
            break;
        case '*':
            cout<<m*n;
            /* code */
            break;
        case '/':
            cout<<m/n;
            /* code */
            break;
        case '%':
            cout<<m%n;
            /* code */
            break;
        case '^':
            cout<<(m^n);
            /* code */
            break;
        default:
            std::cout<<"enter right charest";
            break;
        }
        cout<<"\n";
        s="";
    }
    return 0;
}
#include"big_int.h"
#include<algorithm>
#include<vector>
#include"other.h"

using namespace _big_int;

big_int::big_int():num(""){
    pos = true;
    fraciton = false;
}

big_int::big_int(std::string s){
    pos=true;
    fraciton = false;
    num = s;
    // std::cout<<"s="<<s<<" num="<<num<<"\n";
    if(s[0]=='-'){
        num.erase(num.begin());
        pos = false;
    }
    // std::cout<<"num="<<num<<"\n";
}

big_int::big_int(const big_int& s){
    num = s.num;
    pos = s.pos;
    fraciton = s.fraciton;
}

big_int::big_int(int s){
    fraciton = false;
    pos=true;
    if(s<0){
        s = -s;
        pos = false;
    }
    while(s>0){
        num+=s%10+'0';
        s/=10;
    }
    std::reverse(num.begin(),num.end());
}


bool big_int::operator<(big_int num1){
    if(num == num1.get())
        return false;
    if(pos==false && num1.pos == true){

        return true;
    } else if(pos==true && num1.pos == false){

        return false;
    } else if(pos==false && num1.pos == false){

        if(num == num1.get()){
            return false;
        }
        std::string tmp = num1.get();
        // std::cout<<"tmp="<<tmp<<" num="<<num<<"\n";
        switch (judge(num,tmp)) {
            case 1:
                return true;
                break;
            case -1:
                return false;
                break;
            default:
                return true;
                break;
        }
    } else {

        if(num == num1.get()){
            return false;
        }
        std::string tmp = num1.get();
        // std::cout<<"tmp="<<tmp<<" num="<<num<<"\n";
        switch (judge(num,tmp)) {

            case 1:
                return false;
                break;
            case -1:
                return true;
                break;
            default:
                return false;
                break;
        }
    }
}

bool big_int::operator>(big_int num1){
    // std::cout<<"num="<<num<<" num1.get()="<<num1.get()<<"\n";
    if(judge(num,num1.get())==1){
        return true;
    }
    return false;
}

bool big_int::operator<=(big_int num1){
    if(judge(this->num,num1.get())==-1 || this->num == num1.get()){
        return true;
    }
    return false;
}

bool big_int::operator>=(big_int num1){
    if(judge(this->num,num1.get())==1 || this->num == num1.get()){
        return true;
    }
    return false;
}

bool big_int::operator==(big_int num1){
    if(num==num1.get() && pos==num1.pos){
        return true;
    }
    return false;
}

std::string big_int::get(){
    return num;
}

void big_int::chg_pos(bool op){
    pos = op;
}

void big_int::chg_pos(){
    pos = !pos;
}

bool big_int::get_pos(){
    return pos;
}

int big_int::length(){
    return num.length();
}

big_int big_int::operator+(big_int num1){

    if(pos && !num1.get_pos()){
        // std::cout<<"add(+-)\n";
        // std::cout<<num1<<"\n";
        num1.chg_pos();
        return (*this)-num1;
    } else if(!pos && num1.get_pos()){
        // std::cout<<"add(-+)\n";
        this->chg_pos();
        big_int tmp = big_int(num1-(*this));
        this->chg_pos();
        return tmp;
    }

    std::string ret;
    std::string tmp = num;

    short i_tmp=0,j_tmp=0;
    short a=0;
    int i =0,j=0;
    int i_len = tmp.length(),j_len = num1.get().length();

    std::reverse(tmp.begin(),tmp.end());
    std::string num2 = num1.get();
    std::reverse(num2.begin(),num2.end());

    // std::cout<<"After reverse :"<<tmp<<"  and   "<<num2<<"\n";
    
    while(i<i_len || j<j_len){
        i_tmp = i<i_len?tmp[i]-'0':0;
        j_tmp = j<j_len?num2[j]-'0':0;
        short t = a + i_tmp + j_tmp;
        a = t/10;
        ret+=t%10+'0';

        // std::cout<<i_tmp<<"+"<<j_tmp<<"+"<<a<<"="<<t<<"..."<<a<<" and string = "<<ret<<"\n";
        i++,j++;
    }
    if(a!=0){
        ret+=a+'0';
    }
    
    if((pos == false && num1.pos == false)){
        // std::cout<<"add(--)\n";
        ret+='-';
    }
    // std::cout<<"The ans is :"<<ret<<"\n";
    std::reverse(ret.begin(),ret.end());

    return big_int(ret);
}

big_int big_int::operator-(big_int num1){

    if(num1 == big_int("0")) return *this;

    if(pos && !num1.get_pos()){
        // std::cout<<"sub(+-)\n";
        num1.chg_pos();
        // std::cout<<num1<<"\n";
        return (*this)+num1;
    } else if(!pos && !num1.get_pos()){
        // std::cout<<"sub(--)\n";
        this->chg_pos();
        num1.chg_pos();
        big_int tmp = big_int(num1-(*this));
        this->chg_pos();
        return tmp;
    } else if(!pos && num1.get_pos()){
        this->chg_pos();
        big_int tmp = big_int((*this)+num1);
        this->chg_pos();
        tmp.chg_pos();
        // std::cout<<"sub(-+)\n";
        return tmp;
    }

    std::string ret;
    std::string tmp = num;
    std::string num2 = num1.get();

    int i_tmp=0,j_tmp=0;
    int a=0;
    int i =0,j=0;
    int i_len = tmp.length(),j_len = num2.length();

    bool ispos = true;
    if(*this<num1){
        std::swap(i_len,j_len);
        std::swap(tmp,num2);
        ispos = false;
    }

    std::reverse(tmp.begin(),tmp.end());
    std::reverse(num2.begin(),num2.end());

    

    while(i<i_len || j<j_len){
        i_tmp = i<i_len?tmp[i]-'0':0;
        j_tmp = j<j_len?num2[j]-'0':0;
        int t = 0;
        if((i_tmp==0 || i_tmp < j_tmp) && a==-1){
            i_tmp += 10;
            t = a + i_tmp - j_tmp;
            // std::cout<<i_tmp<<"-"<<j_tmp<<"+"<<a<<"=";
            a = -1;
        } else if(i_tmp<j_tmp){
            // std::cout<<i_tmp+10<<"-"<<j_tmp<<"+"<<a<<"=";
            t = a + i_tmp + 10 - j_tmp; 
            a=-1;
        } else {
            t = a + i_tmp - j_tmp;
            // std::cout<<i_tmp<<"-"<<j_tmp<<"+"<<a<<"=";
            a=0;
        }

        ret+=t+'0';

        // std::cout<<t<<"..."<<a<<" and string = "<<ret<<"\n";
        i++,j++;
    }
    
    int cnt= 0;
    std::reverse(ret.begin(),ret.end());
    ret = dezero(ret);
    std::reverse(ret.begin(),ret.end());
    if(ispos==false){
        ret+='-';
    }
    std::reverse(ret.begin(),ret.end());
    
    return big_int(ret);
}

big_int big_int::operator*(big_int num1){

    

    big_int ret=big_int();
    std::string tmp = num;
    std::string num2 = num1.get();
    

    short i_tmp=0,j_tmp=0;
    short a=0;
    int i =0,j=0;
    int i_len = tmp.length(),j_len = num1.get().length();
    std::string zero="";
    std::string z="";
    std::reverse(tmp.begin(),tmp.end());
    std::reverse(num2.begin(),num2.end());

    while((i<i_len && tmp[i]=='0') || (j<j_len && num2[j]=='0')){
        if(i<i_len && tmp[i]=='0'){
            z+='0';
            i++;
        }
        if(j<j_len && num2[j]=='0'){
            z+='0';
            j++;
        }
    }
    int jj=j;

    // std::cout<<"jj="<<jj<<"\n";
    // std::cout<<"num<"<<i<<"> "<<"num2<"<<jj<<">\n";
    

    while(i<i_len){
        std::string temp="";
        i_tmp = i<i_len?tmp[i]-'0':0;
        if(tmp[i]=='0'){
            zero+='0';
            i++;
            continue;
        }
        while(j<j_len){
            j_tmp = j<j_len?num2[j]-'0':0;
            short t = a + i_tmp * j_tmp;
            a = t/10;

            temp+=t%10+'0';
            j++;
            // std::cout<<i_tmp<<"*"<<j_tmp<<"+"<<a<<"="<<t<<"..."<<a<<"\n";
        }
        if(a!=0){
            temp+=a+'0';
        }
        std::reverse(temp.begin(),temp.end());
        
        temp+=zero;
        zero+='0';
        
        ret = ret + big_int(temp);
        j=jj;i++;a=0;
        // std::cout<<"temp : "<<temp<<"  zero : "<<zero<<"\n\n";
    }
    ret = big_int(dezero(ret.get()));
    // std::cout<<"ans="<<ret.get()+z<<"\n";
    ret = big_int(ret.get()+z);
    if((!pos && num1.get_pos()) || (pos && !num1.get_pos())){
        ret.chg_pos();
    }
    return ret;
}

big_int big_int::operator+=(big_int num1){
    *this = *this + num1;
    return *this;
}

big_int big_int::operator-=(big_int num1){
    *this = *this - num1;
    return *this;
}

big_int big_int::operator*=(big_int num1){
    *this = *this * num1;
    return *this;
}

big_int big_int::operator=(big_int num1){
    num = num1.get();
    pos=num1.get_pos();
    fraciton = num1.fraciton;
    return *this;
}

big_int big_int::operator=(std::string num1){
    num = num1;
    pos=true;
    fraciton=false;
    if(num1[0]=='-'){
        num.erase(num.begin());
        pos = false;
    }
    return *this;
}

big_int big_int::operator/(big_int num1){

    bool ispos=true;
    if((pos != num1.get_pos())){
        ispos=false;
    }
    
    if(num1.get()=="0"){
        return big_int("not allow integer");
    }
    using std::string;
    if(num==num1.get()){
        return big_int(1);
    }

    big_int a = big_int(num),b=big_int(num1.get());
    // std::cout<<"a="<<a.get()<Wn";
    if(a<b) return big_int(0);

	long int i,j;
    big_int e = big_int();

    while(a.length()>b.length()+1){
        b = b*10;
    }
    // std::cout<<"a="<<a.get()<<"\n";
    // std::cout<<"b="<<b.get()<<"\n";

	while(!(b==big_int(num1.get())))
	{
		j=0;

        while(a>=b){
            a = big_int(a-b);
            // std::cout<<"a="<<a.get()<<"\n";
            j++;
        }
        
        e.num+=j+'0';
        b.num.erase(b.num.end()-1);
        // std::cout<<"e="<<e.get()<<"\n";std::cout<<"j="<<j<<"\n";
	}
    
    j=0;
    
    while(a>=b){
        
        a = big_int(a-b);
        // std::cout<<"a="<<a.get()<<"\n";
        j++;
    }
        
    e.num+=j+'0';
    
    e.num = dezero(e.get());
    if(!ispos){
        e.pos = false;
    }
    j=0;
    
	return e;
}

big_int big_int::operator%(big_int num1){

    if(!pos || !num1.get_pos()){
        return std::string("not allow integer");
    }
    // std::cout<<((*this)/num1)<<" "<<(((*this)/num1)*num1)<<" "<<*this<<"\n";
    big_int tmp = (((*this)/num1)*num1);
    if(*this == tmp){
        return big_int("0");
    }
    big_int aa = big_int(*this);
    // std::cout<<*this<<"-"<<tmp<<"="<<(*this-tmp)<<"\n";
    return (aa-tmp);
}

big_int big_int::operator^(big_int num1){
    if(num1<big_int(0)){
        return big_int("not allow integer");
    }
    big_int tmp = *this;
    if(num1==1){
        return tmp;
    }
    big_int ans;

    if(num1%2==big_int("0")){
        num1=num1/2;
        ans = (tmp^num1);
        ans = ans*ans;
    } else {
        num1 = (num1 - 1)/2;
        ans = (tmp^num1);
        ans = ans * ans * tmp;
    }
    
    return ans;
}


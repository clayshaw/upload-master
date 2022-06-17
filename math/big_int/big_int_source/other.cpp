#include"other.h"
#include<algorithm>

void boublesort(std::vector<std::string> &val){
    int len=val.size();
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(val.at(j).length()>val.at(j+1).length()){
                swap(val.at(j),val.at(j+1));
            }
        }
    }
}

void sort_vec(std::vector<std::string> &val){
    std::sort(val.begin(),val.end(),std::less<std::string>());
    boublesort(val);
}

bool big_int_cmp(std::string s1,std::string s2){
    std::vector<std::string> val;
    val.push_back(s1);
    val.push_back(s2);
    sort_vec(val);
    if(val.at(0)==s1){
        return true;
    } else {
        return false;
    }
}

std::string dezero(std::string a)//用來去掉正數前面的0，也就是說可以輸入000001類似這樣的數字
{
	long int i;
	for(i=0;i<a.length();i++)
	{
		if(a.at(i)>48) break;
	}
	if(i==a.length()) return "0";
	a.erase(0,i);
	return a;
}

int judge(std::string a,std::string b)//判斷兩個正數的大小
{
	if(a.length()>b.length()) return 1;
	if(a.length()<b.length()) return -1;
	long int i;
	for(i=0;i<a.length();i++)
	{
		if(a.at(i)>b.at(i)) return 1;
		if(a.at(i)<b.at(i)) return -1;
	}
	return 0;
}

std::string minus(std::string a,std::string b)//輸入兩個正數，輸出其相減的結果
{
    using std::string;
	a=dezero(a);
	b=dezero(b);
	long int i,j=0;
	string c="0";
	string c1,c2;
	string d="-";
	if(judge(a,b)==0) return c;
	if(judge(a,b)==1)
	{
		c1=a;
		c2=b;
	}
	if(judge(a,b)==-1)
	{
		c1=b;
		c2=a;
		j=-1;
	}
	reverse(c1.begin(),c1.end());
	reverse(c2.begin(),c2.end());
	for(i=0;i<c2.length();i++)
	{
		if(c2.at(i)>=48&&c2.at(i)<=57) c2.at(i)-=48;
		if(c2.at(i)>=97&&c2.at(i)<=122) c2.at(i)-=87;
	}
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=48&&c1.at(i)<=57) c1.at(i)-=48;
		if(c1.at(i)>=97&&c1.at(i)<=122) c1.at(i)-=87;
	}
	for(i=0;i<c2.length();i++)
	{
		c1.at(i)=c1.at(i)-c2.at(i);
	}
	for(i=0;i<c1.length()-1;i++)
	{
		if(c1.at(i)<0)
		{
			c1.at(i)+=10;
			c1.at(i+1)--;
		}
	}
	for(i=c1.length()-1;i>=0;i--)
	{
		if(c1.at(i)>0) break;
	}
	c1.erase(i+1,c1.length());
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=10) c1.at(i)+=87;
		if(c1.at(i)<10) c1.at(i)+=48;
	}
	reverse(c1.begin(),c1.end());
	if(j==-1) c1.insert(0,d);
	return c1;
}
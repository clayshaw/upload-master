#include "other.h"
#include<iostream>

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



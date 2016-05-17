#include <iostream>
#include "lab5.h"

using namespace std;

ostream & operator << (ostream & out, HugeInt & num)
{
	int nonZeroPos = 0;
	
	while(num.ptr[nonZeroPos] == 0)
	{
		nonZeroPos++;
	}

	for(int i = nonZeroPos ; i < num.size ; i++)
	{
		out << num.ptr[i];
	}
	
	return out;
}

istream & operator >> (istream & in, HugeInt & num)
{
	string tmp("0000000000000000000000000"), a;
	in >> a;
	
	int now = num.size - 1;
	for(int i = a.size() - 1 ; i >= 0 ; i--)
	{
		tmp[now--] = a[i];
	}
	for(int i = num.size - 1 ; i >= 0 ; i--)
	{
		num.ptr[i] = tmp[i] - '0';
	}

	return in;
}

HugeInt::HugeInt()
{
	ptr = new int[size];
	
	for(int i = 0 ; i < size ; i++)
	{
		ptr[i] = 0;
	}
}

HugeInt::HugeInt(int in)
{
	ptr = new int[size];

	for(int i = size - 1 ; i >= 0 ; i--)
	{
		ptr[i] = in % 10;
		in /= 10;
	}
}

HugeInt::HugeInt(const string &s)
{
	ptr = new int[size];
	string tmp("0000000000000000000000000");
	
	int now = size - 1;
    for(int i = s.size()-1 ; i >= 0 ; i--)
	{
		tmp[now--] = s[i];
	}	
	
	for(int i = size - 1 ; i >= 0 ; i--)
	{
		ptr[i] = tmp[i] - '0';
	}
}

HugeInt::~HugeInt()
{
	delete [] ptr;
}

const HugeInt HugeInt::operator + (const HugeInt & right)
{
	HugeInt tmp;
	int carry=0;
	
	for(int i=size-1;i>=0;i--)
	{
		tmp.ptr[i] = (*this).ptr[i] + right.ptr[i] + carry;
		
		if(tmp.ptr[i]>9)
		{
			tmp.ptr[i] %= 10;
			carry = 1;
		}
		
		else
		{
			carry = 0;
		}
	}
	return tmp;
}

const HugeInt HugeInt::operator - (const HugeInt &right)
{
	HugeInt tmp;
	int carry = 0;
	
	for(int i=size-1;i>=0;i--)
	{
		tmp.ptr[i] = (*this).ptr[i] - right.ptr[i] - carry;
		
		if(tmp.ptr[i]<0) 
		{
			tmp.ptr[i] +=10;
			carry = 1;
		}
		
		else 
		{
			carry = 0;
		}
	}
	return tmp;
}

const HugeInt & HugeInt::operator = (const HugeInt &right)
{
	for(int i=0;i<size;i++)
	{
		(*this).ptr[i] = right.ptr[i];
	}
	return *this;
}


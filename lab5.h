#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <string>

using namespace std;

class HugeInt
{
	friend istream &operator >> (istream &, HugeInt &);
	friend ostream &operator << (ostream &, HugeInt &);

public:
	HugeInt();
	HugeInt(int);
	HugeInt(const string &);
	~HugeInt();

	const HugeInt operator + (const HugeInt &);
	const HugeInt operator - (const HugeInt &);
	const HugeInt & operator = (const HugeInt &);

	static const int size = 25;
	int *ptr;

};

#endif

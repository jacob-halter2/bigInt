#pragma once

#include <vector>

class bigInt
{
public:
	bigInt(int x);
	bigInt();
	~bigInt();
	
	bigInt operator+(bigInt& rhs);
	//bigInt operator=(bigInt& lhs) { lhs.data = this->data; }

	void printBigInt();

private:
	vector<int> data;
};

bigInt::bigInt(int x)
{
	data.clear();
	while (x)
	{
		data.push_back(x % 1000);
		x = x / 1000;
	}
}

bigInt::bigInt()
{
	data.clear();
}

bigInt::~bigInt()
{
}

bigInt bigInt::operator+(bigInt& rhs)
{
	bigInt newBigInt;
	int remainder = 0;
	int sum = 0;
	for (int i = 0; i < data.size() || i < rhs.data.size() || remainder >= 1 ; i++)
	{
		if (i < data.size())
		{
			if (i < rhs.data.size())
				sum = data[i] + rhs.data[i] + remainder;
			else
				sum = data[i] + remainder;
		}
		else
		{
			if (i < rhs.data.size())
				sum = rhs.data[i] + remainder;
			else
				sum = remainder;
		}
		newBigInt.data.push_back(sum % 1000);
		remainder = sum / 1000;
	}
	return newBigInt;
}

void bigInt::printBigInt()
{
	for (int i = data.size()-1; i >= 0; i--)
	{
		cout << data[i];
	}
}
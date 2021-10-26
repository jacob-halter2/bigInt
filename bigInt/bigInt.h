#pragma once

#include <vector>

class bigInt
{
public:
	bigInt();
	~bigInt();
	
	bigInt operator+(bigInt& rhs);

private:
	vector<int> data;
};

bigInt::bigInt()
{
	data.clear();
	
}

bigInt::~bigInt()
{
}

inline bigInt bigInt::operator+(bigInt& rhs)
{
	bigInt newBigInt;
	int remainder = 0;
	int sum = 0;
	for (int i = 0; i < this->data.size() && i < rhs.data.size(); i++)
	{
		if (this->data[i])
		{
			if (rhs.data[i])
			{
				sum = this->data[i] + rhs.data[i] + remainder;
				newBigInt.data[i] = sum % 1000;
				remainder = sum / 1000;
			}
			else
			{
				
			}
		}
	}
	return newBigInt;
}

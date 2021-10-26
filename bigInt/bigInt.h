#pragma once

#include <vector>

class bigInt
{
public:
	bigInt(int x);
	bigInt();
	~bigInt();
	
	int getDataAt(int i) { return data[i]; }
	int getSize() { return data.size(); }

	bigInt operator+(bigInt& rhs);
	friend std::ostream& operator<< (std::ostream& o,bigInt &rhs);

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

std::ostream& operator<<(std::ostream& out,bigInt& rhs)
{
	for (int i = rhs.getSize() - 1; i >= 0; i--)
	{
		out << rhs.getDataAt(i);
	}
	return out;
}


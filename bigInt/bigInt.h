#pragma once

#include <vector>

class bigInt
{
public:
	bigInt(int x);
	bigInt(long long x);
	bigInt();
	~bigInt();
	
	int getDataAt(int i) { return data[i]; }
	int getSize() { return data.size(); }

	//comparisons
	bool   operator< (bigInt& rhs);
	bool   operator<=(bigInt& rhs);
	bool   operator> (bigInt& rhs) { return !(*this <=rhs); }
	bool   operator>=(bigInt& rhs) { return !(*this < rhs); }
	bool   operator==(bigInt& rhs) { return (*this <= rhs && *this >= rhs); }
	bool   operator!=(bigInt& rhs) { return !(*this == rhs); }

	//arithmetic + & *
	bigInt operator+ (bigInt& rhs);
	bigInt operator+ (int& rhs) { bigInt a(rhs); return (*this + a); }
	bigInt operator+ (long long& rhs) { bigInt a(rhs); return (*this + a); }
	bigInt operator* (bigInt& rhs);
	bigInt operator* (int& rhs) { bigInt a(rhs); return (*this * a); }
	bigInt operator* (long long& rhs) { bigInt a(rhs); return (*this * a); }

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

bigInt::bigInt(long long x)
{
	data.clear();
	while (x)
	{
		data.push_back((int)(x % 1000));
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

bool bigInt::operator<(bigInt& rhs)
{
	if (this->getSize() < rhs.getSize())
		return true;
	else if (this->getSize() > rhs.getSize())
		return false;
	else if (this->getSize() == rhs.getSize())
	{
		for(int i = getSize() - 1; i >= 0; i--)
		{
			if (this->data[i] < rhs.data[i])
				return true;
			else if (this->data[i] > rhs.data[i])
				return false;
			//if equal go deeper and try again
		}
		return false;//made it all the way through, they are equal
	}
}

bool bigInt::operator<=(bigInt& rhs)
{
	if (this->getSize() < rhs.getSize())
		return true;
	else if (this->getSize() > rhs.getSize())
		return false;
	else if (this->getSize() == rhs.getSize())
	{
		for (int i = getSize() - 1; i >= 0; i--)
		{
			if (this->data[i] < rhs.data[i])
				return true;
			else if (this->data[i] > rhs.data[i])
				return false;
			//if equal go deeper and try again
		}
		return true;//made it all the way through, they are equal
	}
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

bigInt bigInt::operator*(bigInt& bottom)
{
	bigInt newBigInt(0);
	bigInt currentRow;
	int remainder = 0;
	int prod = 0;
	for (int bot = 0; bot < bottom.getSize(); bot++)
	{
		remainder = 0;
		prod = 0;
		currentRow.data.clear();
		for (int i = 0; i < bot; i++)
		{
			currentRow.data.push_back(0);
		}
		for(int top = 0; top < this->getSize(); top++)
		{
			prod = (this->data[top] * bottom.data[bot]) + remainder;
			currentRow.data.push_back(prod % 1000);
			remainder = prod / 1000;
		}
		if(remainder > 0)
			currentRow.data.push_back(remainder);
		newBigInt = currentRow + newBigInt;
	}
	return newBigInt;
}

std::ostream& operator<<(std::ostream& out,bigInt& rhs)
{
	out << rhs.getDataAt(rhs.getSize()-1);
	for (int i = rhs.getSize() - 2; i >= 0 && i>= rhs.getSize()-12; i--)
	{
		int x = rhs.getDataAt(i);
		if (x < 100)
			out << '0';
		if (x < 10)
			out << '0';
		out << rhs.getDataAt(i);
	}
	return out;
}


#pragma once
#include <iomanip>
#include <vector>
#define T32 4294967296
#define T16 65536

class bigInt2
{
public:
	bigInt2() { data.clear(); }
	//bigInt2(unsigned int x);
	bigInt2(unsigned long long x);
	unsigned int getDataAt(unsigned int i) { if( i < getSize()) return data[i]; }
	int getSize() { return data.size(); }

	bigInt2 operator+ (bigInt2& rhs);
	bigInt2 operator+ (unsigned int& rhs) { bigInt2 a(rhs); return (*this + a); }
	bigInt2 operator+ (unsigned long long& rhs) { bigInt2 a(rhs); return (*this + a); }

	bigInt2 operator* (bigInt2& rhs);
	bigInt2 operator* (unsigned int& rhs) { bigInt2 a(rhs); return (*this * a); }
	bigInt2 operator* (unsigned long long& rhs) { bigInt2 a(rhs); return (*this * a); }

	friend std::ostream& operator<< (std::ostream& o, bigInt& rhs);

private:
	vector<unsigned int> data;
};

/*
bigInt2::bigInt2(unsigned int x)
{
	data.clear();
	data.push_back(x);
}
*/

bigInt2::bigInt2(unsigned long long x)
{
	data.clear();
	while (x)
	{
		data.push_back((int)(x % T32));
		x = x / T32;
	}
}

bigInt2 bigInt2::operator+(bigInt2& rhs)
{
	bigInt2 newBigInt2;
	unsigned int remainder = 0;
	unsigned long sum = 0;
	for (int i = 0; i < data.size() || i < rhs.data.size() || remainder >= 1; i++)
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
		newBigInt2.data.push_back(sum % T32);
		remainder = sum / T32;
	}
	return newBigInt2;
}

int getProd(unsigned int m[], unsigned int &remainder)
{
	unsigned int prod20 = m[2] * m[0];
	unsigned int prod21 = m[2] * m[1];
	unsigned int prod30 = m[3] * m[0];
	unsigned int prod31 = m[3] * m[1];
	/*		[1] [0]
	*	 x	[3] [2]
	* ===============
	*		[21][20]
	* + [31][30]	
	*/
	unsigned int low = (prod21+prod30)*T16 + prod20 + remainder;
	unsigned int carry = (prod21 + prod30 + (prod20/T16))/T16;
	unsigned int high = prod31 + carry;

	remainder = high;
	return low;
}

bigInt2 bigInt2::operator*(bigInt2& bottom)
{
	bigInt2 newBigInt2(0);
	bigInt2 currentRow;
	unsigned int remainder = 0;
	unsigned int prod = 0;
	unsigned int productHandle[4] = { 0,0,0,0 };
	for (int bot = 0; bot < bottom.getSize(); bot++)
	{
		remainder = 0;
		prod = 0;
		currentRow.data.clear();
		for (int i = 0; i < bot; i++)
		{
			currentRow.data.push_back(0);
		}
		for (int top = 0; top < this->getSize(); top++)
		{
			productHandle[0] = (this->data[top] % T16);
			productHandle[1] = (this->data[top] / T16);

			productHandle[2] = (bottom.data[bot] % T16);
			productHandle[3] = (bottom.data[bot] / T16);

			prod = getProd(productHandle, remainder);
			//prod = (this->data[top] * bottom.data[bot]) + remainder;
			currentRow.data.push_back(prod % T32);
		}
		if (remainder > 0)
			currentRow.data.push_back(remainder);
		newBigInt2 = currentRow + newBigInt2;
	}
	return newBigInt2;
}

int getZeros(unsigned int x)
{
	if (x < 10)
		return 9;
	else
		return getZeros(x / 10) - 1;
}



std::ostream& operator<<(std::ostream& out, bigInt2& rhs)
{
	out << setw(10) << rhs.getDataAt(rhs.getSize() - 1);
	for (int i = rhs.getSize() - 2; i >= 0 && i >= rhs.getSize() - 3; i--)
	{
		out << " , ";
		unsigned int x = rhs.getDataAt(i);
		for (int z = 0; z < getZeros(x); z++)
		{
			out << "0";
		}
		out << x;
	}
	return out;
}
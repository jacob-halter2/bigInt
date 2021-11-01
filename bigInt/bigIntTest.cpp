#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

#include "bigInt.h"
#include "bigInt2.h"

bigInt get2pow(int p);
bigInt getFactorial(int q);

void comparisonTests()
{
	bigInt a(99999999999999);
	bigInt b(12345678);

	if (a < b)
		cout << "a<b\n";
	else
		cout << "!a<b\n";
	if (a <= b)
		cout << "a<=b\n";
	else
		cout << "!a<=b\n";
	if (a > b)
		cout << "a>b\n";
	else
		cout << "!a>b\n";
	if (a >= b)
		cout << "a>=b\n";
	else
		cout << "!a>=b\n";

	if (b < a)
		cout << "b<a\n";
	else
		cout << "!b<a\n";
	if (b <= a)
		cout << "b<=a\n";
	else
		cout << "!b<=a\n";
	if (b > a)
		cout << "b>a\n";
	else
		cout << "!b>a\n";
	if (b >= a)
		cout << "b>=a\n";
	else
		cout << "!b>=a\n";

	if (a == b)
		cout << "a == b\n";
	else
		cout << "a != b\n";
	if (b == a)
		cout << "b == a\n";
	else
		cout << "b != a\n";
	if (a != b)
		cout << "a != b\n";
	else
		cout << "a == b\n";
	if (b != a)
		cout << "b != a\n";
	else
		cout << "b == a\n";
}
void addTests() 
{
	bigInt a(9999999999999999);
	bigInt b(12345678);
	bigInt c = a + b;
	cout << c << endl;
	c = c + c;
	cout << c << endl;
	
	int x = 99;
	c = c + x;
	cout << c << endl;
	long long y = 99999999999999;
	c = c + y;
	cout << c << endl;
}

void multTests()
{
	bigInt a(99999999999999);
	bigInt b(12345678);
	bigInt c = a * b;
	cout << c << endl;
	c = c * c;
	cout << c << endl;

	int x = 99;
	c = c * x;
	cout << c << endl;
	long long y = 99999999999999;
	c = c * y;
	cout << c << endl;
}

void facandpowTests()
{
	bigInt a;
	a = getFactorial(10);
	cout << a << endl;
	a = getFactorial(5);
	cout << a << endl;
	a = getFactorial(1);
	cout << a << endl;

	bigInt b;
	b = get2pow(10);
	cout << b << endl;
	b = get2pow(5);
	cout << b << endl;
	b = get2pow(1);
	cout << b << endl;

}

bigInt getFactorial(int q)
{
	bigInt qFact(1);
	for (int i = q; i > 0; i--)
	{
		qFact = qFact * i;
	}
	return qFact;
}

bigInt get2pow(int p)
{
	bigInt p2pow(1);
	int a = 2;
	for (int i = p; i > 0; i--)
	{
		p2pow = p2pow * a;
	}
	return p2pow;
}

void factorialProblem(long p, long q)
{
	bigInt a = getFactorial(q);
	bigInt b = get2pow(p);

	cout << "p = " << p << "\t q = " << q << endl;

	cout << b << endl;
	cout << a << endl;
}

int remove2s(int fCount,int &tCount)
{
	if (fCount % 2 == 0)
	{
		tCount++;
		return remove2s(fCount / 2,tCount);
	}
	else
		return fCount;
}

void factTest()
{
	int one = 1;
	int two = 2;
	int fCount = 6;
	int tCount = 9;
	bigInt F(720);
	bigInt T(512);
	while (fCount < 1000000)
	{
		if (T < F)
		{
			T = T * two;
			tCount++;
		}
		else	// F <= T
		{
			//check if they are close
			if (F.getDataAt(F.getSize() - 1) == T.getDataAt(T.getSize() - 1))
			{
				if (F.getDataAt(F.getSize() - 2) == T.getDataAt(T.getSize() - 2))
				{
					cout << "p = " << tCount << "\t q = " << fCount << endl;
					cout << T << endl;
					cout << F << endl;
				}
			}
			if (fCount%100 == 0)
			{
				cout << fCount << endl;
			}
			fCount++;
			//F = F * fCount;
			int highestOddFactor = remove2s(fCount,tCount);
			F = F * highestOddFactor;
		}
	}
}

int getBytes(unsigned int x)
{
	if (x / 2 == 0)
		return 1;
	else
		return getBytes(x / 2) + 1;
}

int getP(bigInt2 F,unsigned int t)
{
	return(32 * (F.getSize() - 1) + getBytes(F.getDataAt(F.getSize() - 1)) + t);
}

int getP(bigInt2 F)
{
	return((32 * (F.getSize() - 1)) + getBytes(F.getDataAt(F.getSize() - 1)));
}

bool checkBytes(int j, unsigned int k)
{
	if (j == 1)
		return true;
	else if (k % 2 == 1)
		return checkBytes(j-1, k / 2);
	else 
		return false;

}

bool frsones(int j, bigInt2 F)
{
	if (j > 20 || j <=0)
	{
		cout << "invalid value, setting value to 32";
		j = 20;
	}
	if(F.getSize() < 2)
	{
		cout << "do this by hand, you lazy.\n";
		return false;
	}
	unsigned int k = F.getDataAt(F.getSize() - 1);
	short b = getBytes(k)-1;
	if (k == (int)pow(2, j) - 1)	//k = 11111111111111111111
		return true;
	if (k < (int)pow(2, j) - 1)
	{
		if (k % 2 == 0)
			return false;
		if (k < 15)
		{
			//get next k
			if (k == 7 || k == 3 || k == 1)
				k = (k * (int)pow(2, 28) + (F.getDataAt(F.getSize() - 2) / 16));
			else
				return false;
		}
		else
		{
			//get the top 16 bits of next k
			k = (k * (int)pow(2,16)) + (F.getDataAt(F.getSize() - 2) / (int)pow(2,16));
		}
	}
	while (k > ((int)pow(2, j) - 1))
		k = k / 2;
	return checkBytes(j, k);	//k has enough to check
}

unsigned int remove2s(int x, unsigned int &removed)
{
	if (x % 2 == 0)
	{
		return remove2s(x / 2,removed);
		removed++;
	}
	else
		return x;
}


void factTest2()
{
	clock_t t_start = clock();
	clock_t t_lap = clock();
	int one = 1;
	int two = 2;
	unsigned int fCount = 6;
	unsigned int removed2s = 0;
	bigInt2 F(720);
	while (fCount < 60000)
	{
		if (frsones(16, F))
		{
			cout << "p = " << getP(F) << "\t q = " << fCount << endl;
			cout << F << endl;
		}

		
		if (fCount % 1000 == 0)
		{
			cout << fCount <<" took: " << clock() - t_lap << "ms" << endl;
			t_lap = clock();
		}
		fCount++;
		//F = F * fCount;
		unsigned int highestOddFactor = remove2s(fCount, removed2s);
		F = F * fCount;
	}
	cout << "Total time: " << clock() - t_start << "ms" << endl;
}

int main()
{
	//addTests();
	//multTests();
	//facandpowTests();
	//factTest();	//with bigInt
	factTest2();	//with bigInt2

	char x;
	cin >> x;
	return 0;
}
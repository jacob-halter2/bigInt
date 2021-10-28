#include <iostream>

using namespace std;

#include "bigInt.h"

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
			//
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

int main()
{
	//addTests();
	//multTests();
	//facandpowTests();
	factTest();
	int i = 9;
	

	char x;
	cin >> x;
	return 0;
}
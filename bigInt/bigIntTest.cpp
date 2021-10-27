#include <iostream>

using namespace std;

#include "bigInt.h"

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
}
int main()
{
	addTests();

	char x;
	cin >> x;
	return 0;
}
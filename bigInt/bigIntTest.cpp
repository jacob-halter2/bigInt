#include <iostream>

using namespace std;

#include "bigInt.h"

int main()
{
	bigInt num1(1234567890);
	bigInt num2(12345678);
	bigInt num3; 
	num3 = num1 + num2;
	cout << "addition test: " << num3 << endl;
	num3 = num1 * num2;
	cout << "multiplication test: " << num3 << endl;
	char x;
	cin >> x;
	return 0;
}
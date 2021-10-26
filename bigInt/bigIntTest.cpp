#include <iostream>

using namespace std;

#include "bigInt.h"

int main()
{
	bigInt num1(123450);
	bigInt num2(35);
	bigInt num3; 
	num3 = num1 + num2;
	cout << num3 << endl;

	return 0;
}
#include <iostream>

using namespace std;

#include "bigInt.h"

int main()
{
	bigInt num1(123450);
	bigInt num2(35);
	bigInt num3; 
	num3 = num1 + num2;
	num1.printBigInt();
	num2.printBigInt();
	num3.printBigInt();

	return 0;
}
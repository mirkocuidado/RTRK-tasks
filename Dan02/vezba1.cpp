#include "MyBigInt.h"

#include <iostream>

// Овде написати следећу функцију:
// MyBigInt fibo(int n);

MyBigInt fibo(int n){
	MyBigInt number1 = 0;
	MyBigInt number2 = 1;
	MyBigInt next = 1;

	for (int i = 0; i < n - 1; ++i)
	{
		next = number1 + number2;
		number1 = number2;
		number2 = next;
		cout <<next<<endl;
	}
	return next;
}

int main()
{
	MyBigInt k{ 7 };
	k = fibo(9);
	k = k + 5;
	std::cout << k << std::endl;
	k = 7 + fibo(11);
	std::cout << k << std::endl;
	k = 13_mbi;
	std::cout << k << std::endl;

	MyBigInt l = fibo(300);
	if (l != 222232244629420445529739893461909967206666939096499764990979600_mbi) {
		std::cout << "Greska!" << std::endl;
		return 1;
	}
	std::cout << l << std::endl;
	int a; cin >> a;
	return 0;
}

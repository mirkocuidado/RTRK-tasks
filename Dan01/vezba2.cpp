#include <iostream>

// Овде написати следећу функцију:
// int fibo(int n)


int main()
{
	static_assert(fibo(7) == 34);
	const int k = fibo(9);
	std::cout << k << std::endl;
	const int l = fibo(300); // 300. Финоначијев број је превелик за int
}

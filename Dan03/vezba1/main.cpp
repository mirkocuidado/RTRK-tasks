#include <stdio.h>
#include "MyBigInt.h"   //Dodati implementaciju MyBigInt korisničkog tipa.

void printMBI(MyBigInt mbi) {
    std::cout << "printMBI " << mbi << std::endl;
}

int main()
{
	MyBigInt k(7);
	MyBigInt z(3);
	
	z = MyBigInt(100) + MyBigInt("922"); // Assign move called

    MyBigInt x(k); // Copy constructor called
    
    printMBI(k); // Copy constructor called
    
    z = k; // Assign copy called
    
    MyBigInt y = std::move(k); // Move constructor called
	
	return 0;
}

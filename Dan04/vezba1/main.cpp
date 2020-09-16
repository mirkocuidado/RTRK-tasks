#include <iostream>

#include<memory>
#include "MyUniquePtr.h"

using std::cout;


#define myUP std::unique_ptr
//#define myUP MyUniquePtr


struct MojaKlasa {
	MojaKlasa(int a, int b, int c) : x(a), y(b), z(c) {}
	int x, y, z;
};


void foo(const MojaKlasa& x) {
	cout << x.x;
}

void bar(const MojaKlasa* x) {
	cout << x->y;
}

myUP<MojaKlasa> makeObjectUP()
{
	//return std::make_unique<myClass>();
	return myUP<MojaKlasa>(new MojaKlasa(1, 2, 3));
}


int main()
{
	myUP<MojaKlasa> p;
	p = makeObjectUP();
	foo(*p);
	bar(p.get());
	cout << p->z; // NAPOMENA: ovo uradite poslednje, uz konsultaciju sa predavacima

	// GRESKE: ovo da se onemoguci
	//myUP<MojaKlasa> q{p};
	//myUP<MojaKlasa> r;
	//r = q;

	// @TODO: iz destruktora ispisati pozdrav na ekran
	return 0;
}

#ifndef _MY_COM_
#define _MY_COM_

#include "MyBigInt.h"

#include <cstdint>
#include <array>
#include <string>
#include <iostream>

using namespace std;

struct MyComplex {
private:
	MyBigInt r;
	MyBigInt i;


public:
	MyComplex(MyBigInt rr, MyBigInt ii) {
		r = rr; i = ii;
	}

	MyComplex() = delete;
	~MyComplex() = default;

	MyComplex& operator = (const MyComplex& mbi) {
		r = mbi.r;
		i = mbi.i;
		return *this;
	}

	friend ostream& operator << (ostream& out, const MyComplex& mc);
	friend MyComplex operator + (const MyComplex& mbi1, const MyComplex& mbi2);
}


ostream& operator <<(ostream& out, const MyComplex& mc) {
	out << mc.r << " + " << mc.i << "i" << endl;
	return out;
}

MyComplex operator + (const MyComplex& mbi1, const MyComplex& mbi2) {
	MyComplex pom = MyComplex(mbi1.r + mbi2.r, mbi1.i + mbi2.i);
	return pom;
}

#endif
#ifndef _MY_BIG_INT_
#define _MY_BIG_INT_

#include <cstdint>
#include <array>
#include <string>
#include <iostream>

using namespace std;

struct MyBigInt {

public:
	char* digits;

	int num_of_elems;
public:

	MyBigInt() :digits{} {
		num_of_elems = 0;
	}
	~MyBigInt() {
		delete[] digits;
	}

	// konstruktori
	MyBigInt(int d){
		string s = to_string(d);
		num_of_elems = s.size();

		digits = new char[num_of_elems];

		for (int i = 0, j = 0; i < num_of_elems; i++) {
			digits[i] = s[j] - '0';
			j++;
		}
	}
	MyBigInt(const char* d){
		string s = d;
		num_of_elems = s.size();

		digits = new char[num_of_elems];

		for (int i = 0, j = 0; i < num_of_elems; i++) {
			digits[i] = s[j] - '0';
			j++;
		}
	}
	MyBigInt(string s){
		num_of_elems = s.size();

		digits = new char[num_of_elems];

		for (int i = 0, j = 0; i < num_of_elems; i++) {
			digits[i] = s[j] - '0';
			j++;
		}
	}

	// kopirajuci konstuktor
	MyBigInt(const MyBigInt& mbi) {
		cout << "Kopirajuci konstuktor" << endl;
		num_of_elems = mbi.num_of_elems;
		digits = new char[num_of_elems];

		for (int i = 0; i < mbi.num_of_elems; i++) {
			digits[i] = mbi.digits[i];
		}
	}

	// kopirajuci operator dodele vrednosti
	MyBigInt& operator = (const MyBigInt& mbi) {
		cout << "Kopirajuci operator dodele vrednosti" << endl;
		num_of_elems = mbi.num_of_elems;
		digits = new char[num_of_elems];

		for (int i = 0; i < mbi.num_of_elems; i++)
			digits[i] = mbi.digits[i];

		return *this;
	}

	// premestajuci konsturktor
	MyBigInt(MyBigInt&& mbi) {
		cout << "Premestajuci konsturktor" << endl;
		num_of_elems = mbi.num_of_elems;
		digits = mbi.digits;
		mbi.digits = nullptr;
	}

	// premestajuci operator dodele vrednosti
	MyBigInt& operator=(MyBigInt&& mbi) {
		cout << "Premestajuci operator dodele vrednosti" << endl;
		delete[] digits;
		num_of_elems = mbi.num_of_elems;
		digits = mbi.digits;
		mbi.digits = nullptr;
		return *this;
	}

	friend ostream& operator << (ostream& out, const MyBigInt& mbi);
	friend bool operator != (const MyBigInt& mbi1, const MyBigInt& mbi2);
	friend MyBigInt operator""_mbi(const char* ss);
	friend MyBigInt operator + (const MyBigInt& mbi1, const MyBigInt& mbi2);

};

MyBigInt operator + (const MyBigInt& mbi1, const MyBigInt& mbi2) {
	MyBigInt pom = MyBigInt();
	int manje_elem = 0;

	int n = mbi1.num_of_elems;
	int m = mbi2.num_of_elems;

	if (mbi1.num_of_elems > mbi2.num_of_elems) {
		pom.num_of_elems = mbi1.num_of_elems;
		manje_elem = 1;
	}
	else {
		pom.num_of_elems = mbi2.num_of_elems;
		manje_elem = 2;
	}

	if (manje_elem == 1) {
		pom.digits = new char[n];
		int i = n - 1, j = m - 1, k = n - 1;
		int c = 0, s = 0;
		while (j >= 0) {
			s = mbi1.digits[i] + mbi2.digits[j] + c;
			pom.digits[k] = (s % 10);
			c = s / 10;
			k--;
			i--;
			j--;
		}
		while (i >= 0) {
			s = mbi1.digits[i] + c;
			if (k == 0 && s >= 10) {
				char* niz = new char[pom.num_of_elems];
				for (int i = 1, j=0; i < pom.num_of_elems; i++, j++)
					niz[j] = pom.digits[i];

				pom.num_of_elems++;
				pom.digits = new char[pom.num_of_elems];
				pom.digits[0] = (s / 10);
				pom.digits[1] = (s % 10);
				for (int i = 0, j = 2; i < pom.num_of_elems - 1; i++, j++)
					pom.digits[j] = niz[i];
			}
			else { 
				pom.digits[k] = (s % 10); 
			}
			c = s / 10;
			i--;
			
			k--;
		}
	}
	else {
		pom.digits = new char[m];
		int i = m - 1, j = n - 1, k = m - 1;
		int c = 0, s = 0;
		while (j >= 0) {
			s = mbi1.digits[j] + mbi2.digits[i] + c;
			
			c = s / 10;
			if (k == 0 && s >= 10) {
				char* niz = new char[pom.num_of_elems];
				for (int i = 1, j = 0; i < pom.num_of_elems; i++, j++)
					niz[j] = pom.digits[i];

				pom.num_of_elems++;
				pom.digits = new char[pom.num_of_elems];
				pom.digits[0] = (s / 10);
				pom.digits[1] = (s % 10);
				for (int i = 0, j = 2; i < pom.num_of_elems - 1; i++, j++)
					pom.digits[j] = niz[i];
			}
			else {
				pom.digits[k] = (s % 10);
			}
			k--;
			i--;
			j--;
		}
		while (i >= 0) {
			s = mbi2.digits[i] + c;
			if (k == 0 && s >= 10) {
				char* niz = new char[pom.num_of_elems];
				for (int i = 1, j = 0; i < pom.num_of_elems; i++, j++)
					niz[j] = pom.digits[i];

				pom.num_of_elems++;
				pom.digits = new char[pom.num_of_elems];
				pom.digits[0] = (s / 10);
				pom.digits[1] = (s % 10);
				for (int i = 0, j = 2; i < pom.num_of_elems - 1; i++, j++)
					pom.digits[j] = niz[i];
			}
			else {
				pom.digits[k] = (s % 10);
			}
			c = s / 10;
			i--;
			k--;
		}
	}
	return pom;
}

bool operator != (const MyBigInt& mbi1, const MyBigInt& mbi2) {
	if (mbi1.num_of_elems != mbi2.num_of_elems) return true;
	else {
		for (int i = 0; i < mbi1.num_of_elems; i++) {
			if (mbi1.digits[i] != mbi2.digits[i]) return false;
		}
		return false;
	}
}

MyBigInt operator""_mbi(const char* ss) {

	MyBigInt mbii = MyBigInt();

	string s = ss;
	mbii.num_of_elems = s.size();
	mbii.digits = new char[mbii.num_of_elems];

	for (int i = 0, j = 0; i < mbii.num_of_elems; i++) {
		mbii.digits[i] = s[j] - '0';
		j++;
	}

	return mbii;
}

ostream& operator << (ostream& out, const MyBigInt& mbi) {
	for (int i = 0, j = 0; i < mbi.num_of_elems ; i++) {
		out << (int)mbi.digits[i];
	}
	return out;
}

#endif

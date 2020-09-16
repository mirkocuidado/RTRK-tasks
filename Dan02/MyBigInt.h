#ifndef _MY_BIG_INT_
#define _MY_BIG_INT_

#include <cstdint>
#include <array>
#include <string>
#include <iostream>

using namespace std;

struct MyBigInt {
	
private:
	static constexpr int size{70};
	std::array<int_least8_t, size> digits;

	int num_of_elems;
public:

	MyBigInt() :digits{} {
		num_of_elems = 0;
	}
	~MyBigInt() = default;

	MyBigInt(int d) :digits{} {
		string s = to_string(d);
		num_of_elems = s.size();

		for (int i = size - num_of_elems, j=0; i < size; i++) {
			digits[i] = s[j]-'0';
			j++;
		}
	}

	MyBigInt& operator = (const MyBigInt& mbi) {
		for(int i=0; i<mbi.size; i++)
			digits[i] = mbi.digits[i];

		num_of_elems = mbi.num_of_elems;
		return *this;
	}

	friend ostream& operator << (ostream& out, const MyBigInt& mbi);
	friend MyBigInt operator + (const MyBigInt& mbi1, const MyBigInt& mbi2);
	friend bool operator != (const MyBigInt& mbi1, const MyBigInt& mbi2);
	friend MyBigInt operator""_mbi(const char* ss);

};

	MyBigInt operator + (const MyBigInt& mbi1, const MyBigInt& mbi2) {
		MyBigInt pom = MyBigInt();

		if (mbi1.num_of_elems > mbi2.num_of_elems) pom.num_of_elems = mbi1.num_of_elems;
		else pom.num_of_elems = mbi2.num_of_elems;

		int ccc = 0;
		for (int i = mbi1.size - 1; i >= 0; i--) {
			int ddd = mbi1.digits[i] + mbi2.digits[i] + ccc;
			ccc = 0;
			if (ddd >= 10) {
				if (i == mbi1.size - pom.num_of_elems) pom.num_of_elems++;
				if (i == 0) {
					pom.num_of_elems = 0; cout << "ERROR!" << endl; break;
				}
				ccc = 1;
				pom.digits[i] = ddd - 10;
			}
			else {
				ccc = 0;
				pom.digits[i] = ddd;
			}
		}

		return pom;
	}

	bool operator != (const MyBigInt& mbi1, const MyBigInt& mbi2) {
		if (mbi1.num_of_elems != mbi2.num_of_elems) return false;
		else return mbi1.digits != mbi2.digits;
	}

	MyBigInt operator""_mbi(const char* ss) {

		MyBigInt mbii = MyBigInt();

		string s = ss;
		mbii.num_of_elems = s.size();

		for (int i = mbii.size - mbii.num_of_elems, j = 0; i < mbii.size; i++) {
			mbii.digits[i] = s[j] - '0';
			j++;
		}

		return mbii;
	}

	ostream& operator << (ostream& out, const MyBigInt& mbi) {
		for (int i = mbi.size - mbi.num_of_elems, j = 0; i < mbi.size; i++) {
			out << (int)mbi.digits[i];
		}
		return out;
	}
	

#endif

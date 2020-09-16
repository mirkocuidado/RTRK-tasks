#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "BigData.h"

using namespace std;

BigData BigDataFactory(unsigned int size) {
	return BigData(size);
}

BigData operator+(const BigData &_bd1, const BigData &_bd2) {
	return BigData(_bd1.GetData().size + _bd2.GetData().size);
}

int main() {
	
	Data d1(500);
	Data d2 = move(d1);
	cout << "size: " << d1.size << endl;
	cout << "data: " << d1.data << endl;
	cout << "size: " << d2.size << endl;
	cout << "data: " << d2.data << endl;	

	BigData t1;
	BigData t2;
	BigData t3;

	t1 = BigDataFactory(500);
	t2 = BigDataFactory(500);
	t3 = t1 + t2;

	BigData bd1(500);
	BigData bd2 = move(bd1);
	cout << "size: " << bd1.GetData().size << endl;
	cout << "data: " << bd1.GetData().data << endl;
	cout << "size: " << bd1.GetCrc() << endl;
	cout << "size: " << bd2.GetData().size << endl;
	cout << "data: " << bd2.GetData().data << endl;
	cout << "size: " << bd2.GetCrc() << endl;
	
	// ToDo: Profile function execution time using std::chrono
	/*
	vector<BigData> v;
	int elems = 1000;
	while (elems--) {
		v.push_back(BigData(elems));
	}
	*/
	
	return 0;
}
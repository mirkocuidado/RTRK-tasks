// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_map>
#include <map>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	if (A.size() != B.size()) return -1;

	map <int, vector<int>> m;

	for (unsigned int i = 0; i < A.size(); i++) {
		m[A[i]].push_back(B[i]);
		if (m.find(B[i]) == m.end()) {
			m[B[i]] = {};
		}
	}

	bool at_least_one = true;
	while (at_least_one) {
		at_least_one = false;
		map<int, vector<int>>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {  //kroz mapu preko kljuceva
			int a = it->second.size();
			for (int i = 0; i < a; i++) { // kroz niz za svaki kljuc
				map<int, vector<int>>::iterator it2;
				it2 = m.find(it->second[i]); // ako nadjemo za neki elem niza kljuc mape
				bool found = false;
				for (int i = 0; i < it->second.size(); i++)
					for (int j = 0; j < it2->second.size(); j++)
						if (it->second[i] == it2->second[j]) {
							found = true;
							break;
						}
				if (it2 != m.end() && found == false) {
					at_least_one = true;
					for (int i = 0; i < it2->second.size(); i++)
						it->second.push_back(it2->second[i]);
				}
			}
		}
	}

	return 0;
}

int main() {
	vector<int> a = { 0,1,2,4,5 };
	vector<int> b = { 2,3,3,3,2 };
	int aa = solution(a,b);
	std::cout << aa << endl;
	return 0;
}
#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Node {
	string name;
	shared_ptr<Node> left = nullptr;
	shared_ptr<Node> right = nullptr;
	//Note: "parent Node"; ToDo: Ovde napraviti pokazivac

	Node(string x) : name(x) { cout << "Konstruktor " << name << endl; }
	~Node() { cout << "Destruktor " << name << endl; }

	string toString() {
		string lStr{ "<none>" }, rStr{ "<none>" };

		if (left != nullptr) lStr = left->toString();
		if (right != nullptr) rStr = right->toString();

		string res;
		res += "{Me:" + name + " ";
		//res += "Parent:" + pStr + " "; //Note: Sluzi da vas navede na resenje
		res += "Left:" + lStr + " ";
		res += "Right:" + rStr + "}";
		return res;
	}
};


shared_ptr<Node> foo() {
	shared_ptr<Node> root = make_shared<Node>("koren");
	root->left = make_shared<Node>("levi");
	//Note: root treba da bude predak (parent) od root->left
	root->right = make_shared<Node>("desni");
	return root;
}


int main()
{
	shared_ptr<Node> k = foo();
	cout << k->toString() << endl;
	return 0;
}

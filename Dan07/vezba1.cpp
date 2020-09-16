#include <iostream>

using namespace std;

//ovde dodati implementaciju sablona

int main () {
    cout << "Sum = " << mySum(1, 2, 3, 0.5, 1.0e1) << endl;
    cout << "Sum = " << mySum(1.7, 2, 3, 0.5, 1.0e1) << endl;
    cout << "Sum = " << mySum(1.7) << endl;
    cout << "Sum = " << mySum(0.01, 9999) << endl;
    
    return 0;
}


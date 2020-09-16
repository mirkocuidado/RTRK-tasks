#include <iostream>

using namespace std;

//ovde dodati implementaciju sablona

int main () {
    cout << "Min = " << myMin(6, 7, 8, 4) << endl;
    cout << "Min = " << myMin(1, 2, 3, 0.5, 1.0e1) << endl;
    cout << "Min = " << myMin(1.7, 2, 3, 0.5, 1.0e1) << endl;
    cout << "Min = " << myMin(1.7) << endl;
    cout << "Min = " << myMin(0.01, 9999) << endl;
    cout << "Min = " << myMin(0.01, 9999, 0.00000001) << endl;
    
    return 0;
}




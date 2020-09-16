#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

//ovde dodati implementaciju šablona

int main () {

    int i1 = 5, i2 = 7;
    float f1 = 5.4, f2 = 7.3;
    const char* s1 = "ABC";
    const char* s2 = "PQR";
    
    myPrintf("Print with no args");
    myPrintf("Print 1 integer     -> %d", i1);
    myPrintf("Print 2 integers    -> %d, %d", i1, i2);
    myPrintf("Print 1 float       -> %f", f1);
    myPrintf("Print 2 floats      -> %f, %f", f1, f2);
    myPrintf("Print wrong int     -> %d", f1);
    myPrintf("Print 2 wrong nums  -> %d, %f", f1, i1);
    myPrintf("Print 1 const char  -> %f, %f", f1, f2);
    myPrintf("Print 2 const char  -> %s, %s", s1, s2);
    myPrintf("Print mix           -> str = %s, int = %d, flo = %f, str = %s, int = %d",
                                            s1, i1, f1, s2, i2);
    myPrintf("Print mix with err  -> str = %s, int = %d, flo = %f, str = %s, int = %d",
                                            s1, i1, f1, i1, i2);
                                            
    return 0;
}
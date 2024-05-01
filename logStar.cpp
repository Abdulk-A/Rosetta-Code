#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

//credit geeksforgeeks
//g++ logStar.cpp -o log

int _log(double x, double base) {
    return (int)(log(x) / log(base));
}

double recursiveLogStar(double n, double b) {
    if (n > 1.0) return 1.0 + recursiveLogStar(_log(n, b), b);
    return 0;
}

int main() {


    for(int i = 2; i <= 10; i++){
        cout << "Log*(10^12) = " << recursiveLogStar(pow(10,12), i) << "\n";
    }

    return 0;
}

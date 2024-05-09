#include <iostream>
#include "playground.h"

using namespace std;

int main() {

    Fraction a(5,8), b(5,9);

    a.add(b);
    a.printFraction();
    cout << a.DecimalValue() << endl;

    return 0;
}
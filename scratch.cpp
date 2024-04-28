
#include <iostream>
#include <random>
using namespace std;

int main(){

    srand(time(0));

    for(int i = 0; i < 25; i++){
        int k = rand() % 10 + 1;
        cout << k << " ";
    }
    return 0;
}
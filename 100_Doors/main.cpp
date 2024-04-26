#include <iostream>

using namespace std;

void print(int*arr, int n);

/*DESCRIPTION:


g++ -std=c++14 main.cpp -o code1

1.There are 100 doors in a row that are all initially closed. 
2.You make 100 passes by the doors.
3.The first time visit, open all the doors.
4.The second visit only visit every second door (#2, #4, $6) and toggle
5.the third visit only visit every third floor...
6.the fourt visti every 4th door
*/

int main(){

    int arr[100] = {1};

    print(arr, 100);

    for(int i = 1; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(j % i == 0) {
                if(arr[j] == 0) arr[j] = 1;
                else arr[j] = 0;
            }
        }
    }

    print(arr, 100);
    
    return 0;
}

void print(int*arr, int n) {

    for(int i = 0; i < n; i++) {
        if(i % 10 == 0) cout << endl;
        cout << arr[i] << " "; 
    }
    cout << endl;
}
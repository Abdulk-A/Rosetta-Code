#include <iostream>
#include "../helpful.h"
using namespace std;

int ctoi(char**c, int pos);

int main(int argc, char**argv) {

    if(argc != 3) {
        cout << "PLEASE MAKE SURE THERE ARE ONLY 3 ARGUMENTS!\n";
        exit(0);
    }

    int row = ctoi(argv, 1);
    int col = ctoi(argv, 2);

    int**arr = new int*[row];
    for(int i = 0; i < row; i++) arr[i] = new int[col];



    return 0;
}

int ctoi(char**c, int pos) {

    int num = 0, len = strlen(c[pos]), p;
    p = len - 1;

    for(int i = 0; i < len; i++){
        
        int ch = c[pos][i] - 48;
        if(ch < 0 || ch > 9) {
            cout << "PLEASE MAKE SURE ROW/COL ARE NUMBERS!\n";
            exit(0);
        }

        num += (pow(10, p) * ch);
        p--;
    }


    return num;
}
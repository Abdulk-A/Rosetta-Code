#include <iostream>
#include "../helpful.h"

using namespace std;

//g++ -std=c++11 main.cpp -o puzzle

#define BOARD_SIZE 4

bool check_board(int matrix[][BOARD_SIZE]);
void create_board(int matrix[][BOARD_SIZE]);
// void printMatrix2(int arr[][BOARD_SIZE], int r, int c);
void number_array(int* arr);



int main() {

    //creating board
    int matrix[BOARD_SIZE][BOARD_SIZE];

    int example[BOARD_SIZE][BOARD_SIZE] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
    create_board(matrix);

    
    bool check = check_board(matrix);


    printMatrix(matrix);
    cout << check << endl;

    return 0;
}

void number_array(int* arr) {
    for(int i = 0; i < 16; i++){
        arr[i] = i;
    }
}

//intialize board 
void create_board(int matrix[][BOARD_SIZE]) {
    int arr[16];
    number_array(arr);
    shuffle(arr, 16);

    int j = 0;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int k = 0; k < BOARD_SIZE; k++){
            matrix[i][k] = arr[j];
            j++;
        }
    }
}

bool check_board(int matrix[][BOARD_SIZE]) {

    int j = 1;
    for(int i = 0; i < BOARD_SIZE-1; i++){
        for(int k = 0; k < BOARD_SIZE; k++) {
            if(matrix[i][k] != j) return false;
            j++;
        }
    }

    for(int k = 0; k < BOARD_SIZE - 1; k++) {
        if(matrix[BOARD_SIZE - 1][k] != j) return false;
        j++;
    }

    return true;
}

// void printMatrix2(int arr[][4], int r, int c) {

//     for(int i = 0; i < r; i++){
//         for(int k = 0; k < c; k++){
//             cout << arr[i][k] << " ";
//         }
//         cout << endl;
//     }
// }
#include <iostream>
#include <vector>
#include "../helpful.h"

using namespace std;

//g++ -std=c++11 main.cpp -o puzzle

#define BOARD_SIZE 4

bool check_board(int matrix[][BOARD_SIZE]);
void create_board(int matrix[][BOARD_SIZE]);
vector<int> find_zero(int matrix[][BOARD_SIZE]);
void number_array(int* arr);
void print_possibilites(const vector<int> & possibilities);
void updateMatrix(int matrix[][BOARD_SIZE], const vector<int> possibilities, int num);

int main() {

    cout << "PLEASE MAKE SURE TO ENTER A NUMBER BETWEEN 1-15 OR Q/q to QUIT" << endl;

    //creating board
    int matrix[BOARD_SIZE][BOARD_SIZE];
    create_board(matrix);
    printMatrix(matrix);

    if (check_board(matrix)) return 0;

    vector<int> possibilities = find_zero(matrix);

    string s;

    do {
        cout << "Enter one of these numbers ";
        possibilities = find_zero(matrix);
        print_possibilites(possibilities);

        getline(cin, s);


        if(s == "Q" || s == "q") break;

        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                num = stoi(s);
                break;
            }
            else {
                cout << "MAKE SURE TO ENTER A VALID NUMBER!";
            }
        }
        

        updateMatrix(matrix, possibilities, num);
        if (check_board(matrix)) break;

        printMatrix(matrix);
        

    } while (true);
    
    // printMatrix(matrix);

    if(check_board(matrix)) {
        cout << "SUCCESS" << endl;
        printMatrix(matrix);
    }
    else cout << "FAILURE" << endl;

    return 0;
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



vector<int> find_zero(int matrix[][BOARD_SIZE]) {

    vector<int> possibilities;

    for(int i = 0; i < BOARD_SIZE; i++){
        for(int k = 0; k < BOARD_SIZE; k++){
            if(matrix[i][k] == 0) {
                if(i - 1 >= 0) possibilities.push_back(matrix[i - 1][k]);
                if(i + 1 < BOARD_SIZE) possibilities.push_back(matrix[i + 1][k]);
                if(k - 1 >= 0) possibilities.push_back(matrix[i][k - 1]);
                if(k + 1 <  BOARD_SIZE) possibilities.push_back(matrix[i][k + 1]);
            }
        }
    }

    return possibilities;
}

void number_array(int* arr) {
    for(int i = 0; i < 16; i++){
        arr[i] = i;
    }
}

void print_possibilites(const vector<int> & possibilities) {
    cout << "( ";
    for(auto i : possibilities) {
        cout << i << " ";
    }
    cout << "): ";
}

void updateMatrix(int matrix[][BOARD_SIZE], const vector<int> possibilities, int num) {

    bool found = false;
    for(auto i : possibilities) {
        if(i == num) {
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Not Possible" << endl;
        return;
    }

    int nx,ny,zx,zy;

    for(int i = 0; i < BOARD_SIZE; i++){
        for(int k = 0; k < BOARD_SIZE; k++) {
            if(matrix[i][k] == num) {
                nx = i;
                ny = k;
            }
            if(matrix[i][k] == 0) {
                zx = i;
                zy = k;
            }
        }
    }

    swap(matrix[nx][ny], matrix[zx][zy]);
}

// void printMatrix2(int arr[][4], int r, int c) {

//     for(int i = 0; i < r; i++){
//         for(int k = 0; k < c; k++){
//             cout << arr[i][k] << " ";
//         }
//         cout << endl;
//     }
// }
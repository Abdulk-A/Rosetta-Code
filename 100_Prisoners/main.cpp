#include <iostream>
#include <map>
#include <random>
#include <vector>
#include "../helpful.h"



/*
100 prisoners are individually numbered 1 to 100

A room having a cupboard of 100 opaque drawers numbered 1 to 100, that cannot be seen from outside.

Cards numbered 1 to 100 are placed randomly, one to a drawer, and the drawers all closed; at the start.

Prisoners start outside the room
They can decide some strategy before any enter the room.
Prisoners enter the room one by one, can open a drawer, inspect the card number in the drawer, then close the drawer.
A prisoner can open no more than 50 drawers.
A prisoner tries to find his own number.
A prisoner finding his own number is then held apart from the others.
If all 100 prisoners find their own numbers then they will all be pardoned. If any don't then all sentences stand.

*/
using namespace std;

//g++ -std=c++11 main.cpp -o prisoner

void numberArray(int*arr);
bool prisonerPlay(int * cards);
bool prisonerPlaySmart(int * cards);

int main() {

    //initialize and shuffle cards array
    int cards[ONE_HUNDRED];
    numberArray(cards);
    

    //prisoners opening cupbards
    int successCount = 0;

    for(int i = 0; i < 10000; i++){
        shuffle(cards, ONE_HUNDRED);
        if(prisonerPlaySmart(cards)) successCount++;
    }
    
    cout << successCount << endl;

    return 0;
}

void numberArray(int*arr) {
    for(int i = 0; i < ONE_HUNDRED; i++) {
        arr[i] = i;
    }
}

bool prisonerPlaySmart(int * cards) {

    for(int i = 0; i < ONE_HUNDRED; i++){
        int k = i;
        bool success = false;
        for(int j = 0; j < 50; j++){
            if(cards[k] == i) {
                success = true;
                break;
            }
            else k = cards[k];
        }
        if(!success) return false;
    }

    return true;
}

bool prisonerPlay(int * cards) {
    //initialize cupboards
    bool cupBoard[ONE_HUNDRED] = {false};

    srand(time(0));
    for(int i = 0; i < ONE_HUNDRED; i++) {
        bool success = false;
        for(int j = 0; j < 50; j++) {
            int k = rand() % ONE_HUNDRED;
            if(!cupBoard[k]) {
                cupBoard[k] = true;
                break;
            }
            if(cards[k] == i) {
                success = true;
                break;
            }
        }
        if(!success) return false;
    }
    return true;
}

/*
    for(int i = 0; i < ONE_HUNDRED; i++){
        vector<int> vec;
        for(int j = 0; j < 50; j++){

            while(true){
                int k = rand() % ONE_HUNDRED + 1;
                auto it = find(vec.begin(), vec.end(), k);

                if (it == vec.end()) {
                    vec.push_back(k);
                    break;
                }
            }
            if(cupBoard[vec[vec.size() - 1]] == prisoners[i]) {
                guilty[i] = true;
                break;
            }
            
        }
    }
*/

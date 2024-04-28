#include <iostream>
#include <map>
#include <random>
#include <vector>
#include "../helpful.h"
using namespace std;

//g++ -std=c++11 main.cpp -o prisoner

void numberArray(int*arr){
    for(int i = 0; i < ONE_HUNDRED; i++) {
        arr[i] = i + 1;
    }
}

int main() {

    // initialize prisoners from 1-100 are not yet to decide freedom
    int prisoners[ONE_HUNDRED];
    numberArray(prisoners);

    //guiltiness array
    bool guilty[ONE_HUNDRED] = {false};

    //number and shuffle cards
    int cards[ONE_HUNDRED];
    numberArray(cards);
    shuffle(cards, ONE_HUNDRED);

    //cupboard numbered and card is placed inside;
    map<int,int> cupBoard;

    for(int i = 1; i <= ONE_HUNDRED; i++) {
        cupBoard[i] = cards[i - 1];
    }

    //prisoner opening drawer

    srand(time(0));

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

    printArr(guilty, ONE_HUNDRED);



    // for(auto i : cupBoard) {
    //     cout << i.first << " " << i.second << endl;
    // }

    return 0;
}


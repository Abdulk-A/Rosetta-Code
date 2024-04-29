#ifndef HELPFUL_H
#define HELPFUL_H

#include <iostream>
#include <random>

#define ONE_HUNDRED 100

void shuffle(int * arr, int n);
void swap(int *x, int *y);

//printing array
template <typename T> 
void printArr(T*arr, int n) {

    for(int i = 0; i < n; i++) {
        if(i % 10 == 0) std::cout << std::endl;
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
}

template< typename T, size_t N, size_t M >
void printMatrix( T(&matrix)[N][M]) {
    for ( int x = 0; x < N; x ++ ) {
        for ( int y = 0; y < M; y++ ) {
            std::cout << " | " << matrix[x][y] << " | ";
        }
        std::cout << std::endl;
    }
}

//shuffle elements in array 
void shuffle(int * arr, int n) {

    srand(time(0));

    for(int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }
    
}

//swap elements for an array
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

#endif
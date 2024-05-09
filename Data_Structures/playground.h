
#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <iostream>
#include <vector>



#endif


class Fraction {  
    int numer, denom;

    public:
    Fraction(int numer, int denom);
    double DecimalValue();
    void add(Fraction b);
    Fraction getFraction();
    void printFraction();

    void simplify();
};

Fraction::Fraction(int numer, int denom){
    this->numer = numer;
    if (denom == 0) exit(EXIT_FAILURE);
    this->denom = denom;
}

double Fraction::DecimalValue() {
    return double(numer) / double(denom);
}

void Fraction:: add(Fraction b) {

    if(this->denom != b.denom) {
        if(this->denom > b.denom) {
            if(this->denom % b.denom == 0) {
                int val = this->denom / b.denom;
                b.denom = b.denom * val;
                b.numer = b.numer * val;
            }
            else {
                int i = this->denom;
                while(true) {
                    if(i % this->denom == 0 && i % b.denom == 0) break;
                    i++;
                }

                int aVal = i / this->denom, bVal = i / b.denom;

                this->numer = this->numer * aVal;
                this->denom = this->denom * aVal;

                b.numer = b.numer * bVal;
                b.denom = b.denom * bVal;
            }
        }
        else {
            if(b.denom % this->denom == 0) { 
                int val = b.denom / this->denom; 
                this->denom = this->denom * val;
                this->numer = this->numer * val;
            }
            else {
                int i = b.denom;
                while(true) {
                    if(i % b.denom == 0 && i % this->denom == 0) break;
                    i++;
                }

                int aVal = i / this->denom, bVal = i / b.denom;

                this->numer = this->numer * aVal;
                this->denom = this->denom * aVal;

                b.numer = b.numer * bVal;
                b.denom = b.denom * bVal;
            }
        }
    }

    this->numer = this->numer + b.numer;
    simplify();
}

void Fraction::simplify(){

    int i = (numer > denom) ? denom : numer;

    while(i > 0) { 
        if(i % numer == 0 && i % denom == 0) break;
        i--;
    }

    if(i > 0) {
        numer /= i;
        denom /= i;
    }
}

Fraction Fraction::getFraction(){
    return Fraction(numer,denom);
}

void Fraction::printFraction(){
    if(numer == denom) printf("%d\n", 1);
    else if (numer % denom == 0) printf("%d\n", numer / denom);
    else if (denom % numer == 0) printf("%d\n", denom / numer);
    else printf("%d\n--\n%d\n", numer, denom);
}
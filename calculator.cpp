#include "calculator.h"
#include <stdexcept>
#include <limits>
#include<iostream>
int Calculator::add(int a, int b) {
    // TODO
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    int temp;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    if((a > max - b && b>=0) ||(a<min -b && b < 0) ){throw std::overflow_error("overflow");}
    else{return a+b;}
}

int Calculator::sub(int a, int b) {
    // TODO
    return Calculator::add(a,-b);
}

int Calculator::mul(int a, int b) {
    int max = std::numeric_limits<int>::max();
    
    int min = std::numeric_limits<int>::min();
    int temp;

    if((b>0 && (a >= max /b +1)) || ( b>0 && (a <= min / b -1))){throw std::overflow_error("dd");}
    else if((b<0 && (a <= min /b -1)) || ( b<0 && (a >= max / b +1))){throw std::overflow_error("dd");}
    // TODO
    else {return a * b;}
}

int Calculator::div(int a, int b) {
    int min = std::numeric_limits<int>::min();
    if(b == 0){throw std::invalid_argument("dd");}
    else if((a ==min ) && b == -1){throw std::overflow_error("dd");}
    else{ return a / b;}
    // TODO
}
// Jorge A. Ruiz
// Professor Kent
// Computer Science 836
// Friday, February 13, 2015
// Assignment 01

#include <iostream>
#include "date.h"
using namespace std;

void Date::setDate(int m, int d, int y){
    if((m >= 1 && m <= 12) && (d >= 1 && d <= 31) && (y >= 1900 && y <= 2008)){
        month = m;
        day = d;
        year = y;
    } else {
        month = 9;
        day = 2;
        year = 2008;
    }
    cin.get();
}

void Date::printDate(){
    cout << month << '/' << day << '/' << year << endl;
}

// Jorge A. Ruiz
// Professor Kent
// Computer Science 836
// Friday, February 13, 2015
// Assignment 01

#include <iostream>
#include "date.h"

using namespace std;

int main(int argc, char** argv) {
    int m,d,y;
    Date dt; //DECLARING INSTANCE/OBJECT
    cout << "Enter month, day and year separated by spaces: ";
    cin >> m >> d >> y;
    dt.setDate(m,d,y); //CALLING THE MEMBER FUNCTION
    dt.printDate(); //CALLING MEMBER FUNCTION W/ NO PARAMETERS
    cout << "Press any key to continue...";
    cin.get();
    return 0;
}


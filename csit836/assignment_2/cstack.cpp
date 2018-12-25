// Jorge A. Ruiz
// Professor Kent
// Computer Science 836
// Thursday, March 20, 2015
// Assignment 02

#include <iostream>
#include "cstack.h"

using namespace std;

CSTACK::CSTACK(){
    top = -1;
    for(int i=0; i < 21; i++){
        data[i] = '\0';
    }
}

bool CSTACK::IsEmpty(){
    return (top == -1);
}

bool CSTACK::IsFull(){
    return (top == 21 - 1);
}


void CSTACK::Push(char ch){
    /*if (IsFull()){
        cout << "Stack is full\n"; NOT NEEDED FOR THIS ASSIGNMENT
    } else { */
        top++;
        data[top] = ch;
    //}
}

void CSTACK::Pop(){
    /*if (IsEmpty()){
        cout << "It's NOT a valid expression"; NOT NEEDED FOR THIS ASSIGNMENT
    } else { */
        top--;
    //}

}

char CSTACK::Top(){
    return data[top];
}
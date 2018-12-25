// Jorge A. Ruiz
// Professor Kent
// Computer Science 836
// Thursday, March 20, 2015
// Assignment 02

#include "cstack.h"
#include <iostream>
#include <cstring>

using namespace std;

bool isValidExpression(CSTACK&, char*);

int main(void){
    char expression[21];
    cout << "Enter an expression: ";
    cin >> expression;
    
    CSTACK stack1;
    
    if(isValidExpression(stack1,expression)){
        cout << endl << "It's a valid expression";
    } else {
        cout << endl << "It's NOT a valid expression";
    }
    
    return 0;
}

bool isValidExpression (CSTACK& stackA, char* strExp){
    
    for(int i=0 ; i < strlen(strExp)+1; i++){
        if (strExp[i] == '{'){
            stackA.Push(strExp[i]);
        } else if (strExp[i] == '['){
            stackA.Push(strExp[i]);   
        } else if (strExp[i] == '('){
            stackA.Push(strExp[i]);
        } else if (strExp[i] == '}'){
            if((strExp[i]-2) == stackA.Top() && !stackA.IsEmpty()){
                stackA.Pop();
            } else {
                return false;
            }
        } else if (strExp[i] == ']'){
            if((strExp[i]-2) == stackA.Top() && !stackA.IsEmpty()){
                stackA.Pop();
            } else {
                return false;
            }
        } else if (strExp[i] == ')'){
            if((strExp[i]-1) == stackA.Top() && !stackA.IsEmpty()){
                stackA.Pop();
            } else {
                return false;
            }    
        } 
    }
    
    if(stackA.IsEmpty() != true){
        return false;
    }
        
    return true;
}

/* ASCII VALUES
 * [ = 91
 * ] = 93
 * ( = 40
 * ) = 41
 * { = 123
 * } = 125
 */
#include <iostream>
#include "tree.h"

using namespace std;

PersonRec::PersonRec(char* n, int b, PersonRec* lC = NULL, PersonRec* rC = NULL){
    strcpy(name,n);
    bribe = b;
    lChild = lC;
    rChild = rC;
}

CTree::CTree(){
    root = NULL;
}

CTree::~CTree(){
    delete root;
}

void CTree::Add(){
    char aName[40];
    int aBribe;
    cout << endl << "Enter the person's name: ";
    cin >> aName;
    cout<< endl << "Enter the person's contribution: ";
    cin >> aBribe;
    AddItem(root, aName, aBribe);
}

bool CTree::isEmpty(){
    return root == NULL;
}

void CTree::View(){
    if (isEmpty() == false){
        cout << endl <<"Contributions" << endl;
        cout << "_______________" << endl;
        DisplayTree(root);
    } else if (isEmpty() == true){
        cout << endl << "The list is empty" << endl;
    }           
}

void CTree::DisplayTree(PersonRec* ptr){
    static int var = 1;
    if (ptr == NULL){
        return;
    } else {
        DisplayTree(ptr->rChild);
        cout << var << ' ' << ptr->name << " $" << ptr->bribe << endl;
        var++;
        DisplayTree(ptr->lChild);
    }
}

void CTree::AddItem(PersonRec* &aPtr, char* name, int bribe){
    if(isFull() == false){
        if (aPtr == NULL){
            aPtr = new PersonRec(name, bribe);
        } else {
            if (bribe > aPtr->bribe){
                AppendRight(aPtr, name, bribe);
            } else if (bribe < aPtr->bribe){
                 AppendLeft(aPtr, name, bribe);
            } else {
                return;
            }
        }
    } else {
        return;
    }
}


void CTree::AppendLeft(PersonRec* aPtr, char* name, int bribe){
    AddItem(aPtr->lChild, name, bribe);
}

void CTree::AppendRight(PersonRec* aPtr, char* name, int bribe){
    AddItem(aPtr->rChild, name, bribe);
}

bool CTree::isFull(){
    return false;
    /* For this assignment, you can assume there is available memory in the 
     * free store. Therefore, this function always will return false.*/
}


/*The Functions below this comment will not be used*/
/*"You do not need to use all of these member functions."*/


// PersonRec* CTree::Root(){
//     return root;
//     /*You do not need to use all of these member functions*/
// }



// void CTree::BuildRoot(char* name, int bribe){
//     //root = new PersonRec(name, bribe);
//     /*You do not need to use all of these member functions*/
// }
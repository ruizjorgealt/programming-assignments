#include <iostream>
#include <string>
#include "cqueue.h"
using namespace std;

enum choice {BOOKED, WAITING};
const int LINES = 2;
int showMenu(void);
void addPassenger(CQueue*);
void deletePassenger(CQueue*);
void showPassengers(CQueue*);

int main (void){
    CQueue qPassengers[LINES];
    int x;
    do{
    x = showMenu();
    switch (x){
        case 1: addPassenger(qPassengers);
        break;
        case 2: deletePassenger(qPassengers);
        break;
        case 3: showPassengers(qPassengers);
        break;
    }

    } while (x != 4);
    
    return 0;
}

int showMenu(void){
    int select;
    cout << "Menu\n";
    cout << "========\n";
    cout << "1. Add Passenger\n";
    cout << "2. Delete Passenger\n";
    cout << "3. Show Passengers\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> select;
    return select;
}
 
void addPassenger(CQueue* p){
    if(p[BOOKED].IsEmpty() == true){
        p[BOOKED].Enqueue();
    } else if (p[WAITING].IsEmpty() == true){
        p[WAITING].Enqueue();
    } else {
        cout << "Sorry. Plane and waiting list fully booked. Try later";
    }
}
void deletePassenger(CQueue* p){
    if(p[BOOKED].IsEmpty() == true){
        cout << "No passengers to delete" << endl;
    } else {
        p[BOOKED].Dequeue();
    }
    
    if(p[WAITING].IsEmpty() == false){
        
    }
}
void showPassengers(CQueue* p){
    if(p[BOOKED].IsEmpty() == false){
        cout << "Booked passengers: " << endl;
        cout << "=======================" << endl;
        p[BOOKED].Front();
    } else if (p[WAITING].IsEmpty() == false){
        cout << "Waiting list: " << endl;
        cout << "=======================" << endl;
        p[WAITING].Front();
    }
}
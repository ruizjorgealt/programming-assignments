#include <iostream>
#include "cqueue.h"
using namespace std;

CQueue::CQueue(){
    front = (MAX-1);
    rear = (MAX-1);
    /*
    for(int i=0; i<MAX-1; i++){
        
    }*/
}

void CQueue::Enqueue(){
    cin.ignore();
    cout << "Enter name: ";
    cin.getline(passengers[front].name,80);
    cout << "Booking " << passengers[front].name << " on flight";
    if(rear == (rear+1)%MAX){
        rear = 0;
    } else {
        rear++;
    }
}

void CQueue::Dequeue(){
    cout << "Removing " << passengers[front].name << " from Booked passengers";
    
    if(front == (front+1)%MAX){
        front = 0;
    } else {
        front++;
    }
}

bool CQueue::IsEmpty(){
    if (front == rear){
        return true;
    } else {
        return false;
    }
}

bool CQueue::IsFull(){
    if((rear+1)%MAX == front){
        return true;
    } else {
        return false;
    }
}

Passenger CQueue::Front(){
    for(int i=0; i< MAX-1; i++){
        cout << passengers[i].name << endl;
    }
}
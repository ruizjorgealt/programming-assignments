#include "emplist.h"
#include <iostream>
#include <string>

EmployeeList::EmployeeList(){
	head = NULL;
}

EmployeeList::~EmployeeList(){
	Employee *PtrA, *PtrB;
	PtrA = head;
	while (PtrA){
		PtrB = PtrA->link;
		delete PtrA;
		PtrA = PtrB;
	}
}

int EmployeeList::TotalPay(){
	return TotalPayR(head);
}

int EmployeeList::TotalPayR(Employee* head){
	static int num = 0;
	if (head == NULL){
		return num;
	}
	else {
		num += head->pay;
		TotalPayR(head->link);
	}
}

void EmployeeList::AddToList(){
	string aName;
	int aPay;
	cout << "Name: ";
	cin >> aName;
	cout << "Pay: ";
	cin >> aPay;

	Employee *thePtr;
	thePtr = new Employee;
	thePtr->link = NULL;
	thePtr->name = aName;
	thePtr->pay = aPay;

	Employee *currentPointer = head;
	Employee *tempo = NULL;
	bool flag = true;

	while (currentPointer != NULL && flag){
		if (thePtr->pay <= currentPointer->pay){
			tempo = currentPointer;
			currentPointer = currentPointer->link;
		}
		else
			flag = false;
	}

	if (currentPointer == head){
		thePtr->link = head;
		head = thePtr;
	}
	else{
		thePtr->link = currentPointer;
		tempo->link = thePtr;
	}
}

void EmployeeList::ViewList(){
	Employee *temp;
	temp = head;
	do{
		if (IsEmpty()){
			cout << "List is empty" << endl;
		}
		else{
			cout << " Name: " << temp->name << "\n Pay: " << temp->pay << endl;
			temp = temp->link;
		}
	} while (temp);

}

bool EmployeeList::IsEmpty(){
	return head == NULL;
}

void EmployeeList::MovetoFront(){
	/*
	if (!IsEmpty() && head->link != NULL){
		Employee *tmp, *currPtr;
		tmp = head;
		while (tmp->link){
			tmp = tmp->link;
		}

		currPtr = head;
		head = tmp;
		head->link = currPtr;
		tmp = NULL;
		currPtr = NULL;
	}
	else {
		cout << "ERROR!!! ONLY HAVE ONE PERSON" << endl;
	}*/
}
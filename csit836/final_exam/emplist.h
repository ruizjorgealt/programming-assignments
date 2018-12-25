#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
	int pay;
	Employee* link;
	// add constructors if you wish - not required
};

class EmployeeList {
public:
	EmployeeList();
	~EmployeeList();
	void AddToList();
	void ViewList();
	void MovetoFront();
	int TotalPay();
private:
	Employee* head;
	int TotalPayR(Employee*);
	bool IsEmpty();
};
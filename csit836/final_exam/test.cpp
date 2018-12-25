#include "emplist.h"
#include <iostream>
using namespace std;
#include<string>
// add any other standard library functions you wish - not required

int displayMenu(void);
void processChoice(int);
EmployeeList myList; // global variable - OK since given code

int main()
{
	int num;
	do
	{
		num = displayMenu();
		if (num != 4)
			processChoice(num);
	} while (num != 4);
	cout << "Total pay: " << myList.TotalPay() << endl;
	system("Pause");
	return 0;
}

int displayMenu(void)
{
	int choice;
	cout << "1. Add employee to list\n";
	cout << "2. View list\n";
	cout << "3. Move last employee to front\n";
	cout << "4. Exit program\n\n";
	cout << "Please enter choice: ";
	cin >> choice;
	return choice;
}

void processChoice(int choice)
{
	switch (choice)
	{
	case 1:   myList.AddToList();
		break;
	case 2:   myList.ViewList();
		break;
	case 3:   myList.MovetoFront();
	}
}


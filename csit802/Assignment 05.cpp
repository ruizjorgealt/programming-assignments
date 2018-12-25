//	Jorge A. Ruiz
//	Professor Sefiani
//	Computer Science 802
//	Tuesday, May 27, 2014
//	Assigment 04

#include <iostream>
#include <cstdlib>

// Functions prototypes
int menu(int choice);
void fibonacci(int, int);
bool isprime(int);
void divisors(int);

using namespace std;
char a;
// The main function
int main ()
{
	int choice = 0,
		 low,
		 high,
		 num;
	bool prime = true;	
		
	do
	{ 	
		choice = menu(choice);	
		
		if (choice == 1)
		{
			cout << "Enter a range (.e.g.:0 100): ";
			cin >> low >> high;
			fibonacci(low, high);
		}
		
		else if (choice == 2)
		{
			cout << "Enter a number: ";
			cin >> num;
			if (isprime(num))
				cout << endl << "Number " << num << " is prime.";
			else
				cout << endl << "Number " << num <<" is not prime.";
				
			cout << endl;	
		}
		
		else if (choice == 3)
		{
			cout << "Enter a number: ";
			cin >> num;
			divisors(num);
		}
		else if (choice == 4)
			exit(0);		
	
	} while ( choice != 4);
	return 0;
}

// Menu function
int menu(int choice)
{
	// Filter good input
	do
	{
	cout << endl << "Select the type of numbers to print: ";
	cout << endl << "1. Fibonacci series";
	cout << endl << "2. Prime numbers";
	cout << endl << "3. Divisors";
	cout << endl << "4. Quit";
	cout << endl << "Enter your choice: "; 
	cin >> choice;
	} while ((choice < 1) || (choice > 4));
	
	return choice;
}

// The Fibonacci's Sequence Function 
void fibonacci(int low, int high)
{
	int original = 0,
	 	 next = 1,
	    final = 0;
	
	for (int i = low; i < high; i++)
	{
		final = original + next;
		if ( (final >= low) && (final <= high))
			cout << final << ", ";
			
		original = next;
		next = final;
	}	
	cout << endl;
	system("pause");	
}

// The Prime Testing Function
bool isprime(int num)
{
	bool prime = true;
	
	for(int i = 2; i < num; i++)
	{	
		if(num % i == 0)
		{
			prime = false;
		}
	}
	return prime;
	system("pause");	
}

// The Divisor Function
void divisors(int num)
{
	for (int x = 2; x < num; x++)
	{
		if (num % x == 0)
		{
			cout << x << ' ';
		}
	}
	cout << endl;
	system("pause");	
}
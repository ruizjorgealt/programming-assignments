// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 802
// Monday, September 22, 2014 
// Assigment 01


#include <iostream>

using namespace std;
// Calc Function Prototype
void calc(int n1, int d1, int n2, int d2, int& n, int& d, char sign);
// Reduce Function Prototype
bool reduce(int& n,int&  d);
int main()
{
	char answer;
	// Do-While loop to perform the program at least once
	
	do {
		
		// Declaring all variables
		int n1, d1, n2, d2, n, d;	
		char slash, sign;
		bool isReduce = false;
		
		/* Promp the user to enter the fraction expressions
			then we read them into their dedicated variables */
		cout << "Enter a fraction expression: ";
		cin >> n1 >> slash >> d1 >> sign >> n2 >> slash >> d2;

		// Call calc function to perform the operation
		calc(n1, d1, n2, d2, n, d, sign);
		
		/* The boolean variable will call the reduce function which
			then returns a boolean data type (FALSE OR TRUE) */
		isReduce = reduce(n, d);

		// Displays fraction
		cout << endl << n << '/' << d << endl;

		// The isReduce variable will then work as a flag, depending on its value
		if (isReduce)
			cout << endl << "The result was reduced." << endl;
		else
			cout << endl << "The result was not reduced." << endl;

		// Prompts user if they would like to continue
		cout << endl << "More [Y/N]: ";
		cin >> answer;
		
		// Take the answer character and turns it into a uppercase
		answer = toupper(answer);
		
		/* This loop allows us to filter bad input,
			if the user enters bad input, they will enter
			a loop, they will get out of the loop until
			they enter the appropiate input*/

		while (answer != 'N' && answer != 'Y')
		{
			cout << endl << "More?, Please Enter [Y/N]: ";
			cin >> answer;
			answer = toupper(answer);
		}

	} while (answer == 'Y');
	
	
	system("pause");
	return 0;
}

// Calc function for mathematical calculations
void calc(int n1, int d1, int n2, int d2, int& n, int& d, char sign)
{
	/*	Depending on the sign, we will perform
	 	some mathematical operations with
	 	the fractions */
	if (sign == '+')
	{
		n = n1 * d2 + n2 * d1;
		d = d1 * d2;
	}
	else if (sign == '*')
	{
		n = n1 * n2;
		d = d1 * d2;
	}
	else if (sign == '-')
	{
		n = n1 * d2 - d1 * n2;
		d = d1 * d2;
	}
	else if (sign == '/')
	{
		n = n1 * d2;
		d = d1 * n2;
	}
}

// Reduce function
bool reduce(int& n, int&  d)
{

	bool isreduce = false;

	// Reducing the fraction
	for (int i = d * n; i > 1; i--)
	{
		if (n % i == 0 && d % i == 0)
		{
			n /= i;
			d /= i;
			
			/* if a reduction takes place, the
				boolean variable is set to true */
			isreduce = true;
		}
	}

	return isreduce;
}


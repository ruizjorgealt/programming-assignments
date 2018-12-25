//	Jorge A. Ruiz
//	Professor Sefiani
//	Computer Science 802
//	Monday, April 28, 2014
//	Test 03

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	// Declare variables
	int max, n1, d1, n2, d2, 
		key, // For the correct answer
		score = 0, 
		answer; 

	// Random number generator
	srand((unsigned)time(0));

	// Prompt user to enter max number of questions
	cout << "Enter the number of questions to generate? ";
	cin >> max;

	// Enter for loop because we need to loop for a fixed number of times
	for ( int i = 0; i < max; i++) 
	{
		// Generating denominators and numberators
		n1 = 1 + rand() % 10;
		d1 = 1 + rand() % 10;
		n2 = 1 + rand() % 10;
		d2 = 1 + rand() % 10;

		// Displaying question and fractions
		cout << "\nFor the following, specify if the first fraction is smaller than,\nlarger than or equal to the second.\nTo quit, select quit." << endl << endl;
		cout << n1 << '/' << d1 << ' ' << n2 << '/' << d2 << endl;

		// Displaying answer choices
		cout << "1. Smaller" << endl 
			 << "2. Larger" << endl
			 << "3. Equal" << endl
			 << "4. Quit" << endl
			 << "Enter answer: ";
		cin >> answer;

		// Assiging the key variable the 
		// right answer according to the answer choices
		if ( n1 * d1 < n2 * d2)
		key = 1;
		else if (n1 * d1 > n2 * d2)
		key = 2;
		else if (n1 * d1 == n2 * d2)
		key = 3;

		// If user enter 4, we end and display total score
		if ( answer == 4)
			break;

		// If user enters the right answer, we add score
		else if ( answer == key)
		{
			cout << endl << "Right!" << endl;
			score++;
		}

		// Anything else is wrong
		else 
			cout << endl << "Wrong!" << endl;
	} 

	// Displays the score in a percentage form
	cout << "\n\nYour score is " << (double)score/max * 100 << '%';

	cout << endl;
	system("pause");
	return 0;
}
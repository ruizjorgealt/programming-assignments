// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 802
// May 19, 2014
// Test 04

#include <iostream>
#include <ctime>

using namespace std;

// Function prototypes
int generate(int, int);
int max(int n1, int n2, int max);

int main()
{
	// Random number generator
	srand((unsigned)time(0));
	int n1, n2, maxNum, maximum;
	
	// Get range; low and high numbers
	cout << "Enter lower and upper limits: ";
	cin >> n1 >> n2;
	
	// Get max number of integers to generate
	cout << "Enter number of Intergers to generate: ";
	cin >> maxNum;

	// Calling max function
	maximum = max( n1, n2, maxNum);
	
	// Displaying the maximum number generated
	cout << "Maximum number generated is: " << maximum << endl;

	system("pause");
	return 0;
}

// Max function
int max (int n1, int n2, int maxNum)
{
	int numGen, max = 0; // numGen = Number generated

	/* Call generate function as many times as
	desired by the user. */
	for (int i = 0; i < maxNum; i++)
		{
			// We get the single generated number by the generate function
			numGen = generate( n1, n2);
			// Getting the max
			if ( numGen > max )
				 max = numGen;
		}	

	return max;
}

// Generate function; returns random number
int generate(int n1, int n2)
{
	int randNum;
	randNum = n1 + rand() % (n2 - n1 + 1);
	
	// We are going to return a single random generated number
	return randNum;
}
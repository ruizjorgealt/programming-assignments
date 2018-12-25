// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 802
// March 05, 2014
// Test 01

#include <iostream>

using namespace std;

int main()
{
	const int DIFF = 48; // The difference for converting from char to int
	char num[4], word[4];
	int n1, n2, n3, n4, total, w;
	
	
	cout << "Enter a four digit number: ";
	cin >> num;


	// Substracting the difference
	n1 = num[0] - DIFF; 
	n2 = num[1] - DIFF;
	n3 = num[2] - DIFF;
	n4 = num[3] - DIFF;

	// Getting the total
	total = n1 + n2 + n3 + n4; 

	// Displaying to the user
	cout << endl << "The total is " << total << endl;

	cout << endl << "Enter a four letter word: ";
	
	// Initialize word
	cin >> word;
	
	word[0] = word[0] + word[1] + word[2] + word[3] / 4; 
		
	
	// Displaying the average
	cout << endl << "The average letter of your word is " << word[0] << endl << endl;

	system("pause");

	return 0;

}
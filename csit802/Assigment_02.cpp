// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 802
// Sunday, March 09, 2014
// Assigment 02

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    // Creating c-string
	char digits[5];
    
    cout << "\nEnter a 4-Digit number: ";
    
	cin >> digits;
    
    // Variables that will be assigned to a single digit from the c-string
    long double num01, num02, num03, num04, total, BASE;
    
    cout << "\nEnter a base: ";
    
    cin >> BASE;
    
    // Initializing the individual integers
	num01 = digits[0]-'0';
	num02 = digits[1]-'0';
	num03 = digits[2]-'0';
	num04 = digits[3]-'0';
    
    
    // Math convertion
	num04 = num04 * pow( BASE, 0);
    num03 = num03 * pow( BASE, 1);
    num02 = num02 * pow( BASE, 2);
    num01 = num01 * pow( BASE, 3);
	
    // Getting total
	total = num01 + num02 + num03 + num04;
    
    // Displaying
	cout << endl << digits[0] << digits[1] << digits[2] << digits[3] << " in base " << BASE << " is " << total << endl << endl;
    
	system("pause");
    
	return 0;
    
}
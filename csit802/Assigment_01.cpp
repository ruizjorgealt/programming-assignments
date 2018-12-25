// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 802
// Tuesday, February 18, 2014
// Assigment 01

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    float bill; // Set the bill as a float
    cout << "\nEnter the bill amount: $";
    cin >> bill; // Input the value for bill
    
    
    float tax; // Set the tax as a float
    cout << "\nEnter the tax rate : %";
    cin >> tax;
    
    float totaltax;
    totaltax = (tax * 0.01) * bill; // Converting the tax to decimals, and getting the tax
    
    float tip; // Set the tip as a float
    cout << "\nEnter percentage you would like to tip: %";
    cin >> tip; // Input the value for tip
    
    float totaltip;
    totaltip = (tip * 0.01)*bill;// Operation that allows us to get the tip
    
    
    float total;
    total = ( totaltip + totaltax ) + bill;
    // The taxes and tips are added
    // Added to the actual total amount of bill
    
    
    // Displays the info the user has submitted
    cout << "\nThe total including tax of " << tax <<"%"
    " and gratuity of " << tip << "%";
	cout << fixed << setprecision(2) << showpoint; // Output the total with precisionset
	cout << " is $" << total ;
    
    
    
    int  people; // Define the number of people in which the total amount will be divided; people is a whole number
    cout << "\n\nEnter the number of people in which you wish to divide: ";
    cin >> people;
    
    float average; // I used avegrage to define the result of the division
    average = total/people; // Total divided by the number of persons
    
	cout << fixed << setprecision(2) << showpoint; // Manipulating the output with decimal placement
    cout << "\nThe amount for each of " << people << " persons is $" << average; // Displays the average and the number of persons
    
    cout <<"\n\nRate the service by selecting one of the following: \n" // Displays ratings
    "\n1. Excellent"
    "\n2. Above Average"
    "\n3. Average"
    "\n4. Below Average"
    "\n5. Terrible\n";
    
    int rating; // Allows the user to enter a desired rating
    cout << "\nEnter your choice: ";
    cin >> rating;
    
    
    system ("pause");
    return 0;
    
}
// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 839
// Monday, October 20, 2014  
// Assigment 02

#include <iostream>
#include <string>

// The Function Prototypes for all the options
int option_01(char [], char&, int&);
void option_02(char [], char&, int&);
void option_03(char [], int);
void option_04(char [], int, int);
void option_05(char [], int, int);
void option_06(char[]);


using namespace std;
int main()
{
	// Variables
	// I initialized the char sentence array to null in order to get rid
	// of the trash that it initially has stored in it.
	char sentence[256] = {'\0'}, search;
	int choice, index = -1, count = 0, n, limit = 0;
    
	// Do-while loop in order to execute the menu at least once
	do{
        cout <<  endl << "Please enter a string: ";
        cin.getline(sentence, 256);
		
		// This loop allows me to get the last index character
		// from the array, which helps me to determine if the
		// input given by the users is good or bad.
		for (int i = 256 - 1; i >= 0; i--)
		{
			// Since we start from 256 to 0, the loop will check from top to bottom
			// for nulls until the first character is encoutered, then the loop will break
			// and substract the the counter from 256; thus giving me the limit or the laxt index.
			if (sentence[i] == '\0')
				limit++;
			else
				break;	
		}
 
		// This variable will hold the last character placement of the char array
		limit = 256 - 1 - limit;       

        cout << endl << "1. Search for a character in the string";
        cout << endl << "2. Change a character within the string";
        cout << endl << "3. Display the first n characters of the string";
        cout << endl << "4. Display the last n character of the string";
        cout << endl << "5. Display all characters that lie between two given indices";
        cout << endl << "6. Null the string";
        cout << endl << "7. Exit";
        cout << endl << "Choice: ";
        cin >> choice;
        
		// Decitions based in the choice entered by the user
		if (choice == 1)
		{
			index = option_01(sentence, search, count);
				
			if (index != -1)
			{
	            cout << endl << "There are " << count << ' ' << search <<"'s in \""
	            << sentence <<"\" with the 1st one at index " << index << endl;
			}
			else
			{
	            cout << endl << "There are no " << search <<"'s in \""
	           		   << sentence << "\"" << endl;
			}
		}
		
		else if (choice == 2)
		{
			cout << endl << "What is the index of the character you want to change? ";
			cin >> index;
			cout << endl << "What character do you want in that position? ";
			cin >> search;
			
			// If the user enters an index greater than limit which is the last character in the array,
			// an error message will be shown, if it is less then we call the function do the operation.
			
			if (index > limit) 
			{
				cout << "That position is outside the bounds of the string. String unchanged.";
			} 
			else 
			{
				option_02(sentence, search, index);
				cout << endl << "The new string is \"" << sentence << "\"" << endl;

			}
	            
		}

		else if (choice == 3) 
		{
			
			cout << "How many characters from the beginning of the string do you want to display? ";
			cin >> n;
			
			// Shows error is the variable n has way more characters than the limit. Then it will loop back to the menu
			if (n > limit) 
			{
				cout << "Error: too many characters.";
			} 
			else 
			{
				option_03(sentence, n);
			}
		}
		
		else if (choice == 4) 
		{
			cout << "How many characters from the end of the string do you want to display? ";
			cin >> n;
			if (n > limit) 
			{
				cout << "Error: too many characters.";
			} 
			else 
			{
				option_04(sentence, n, limit);

			}
		}
		
		else if (choice == 5) 
		{
			cout << "Please enter the beginning index: ";
			cin >> index;
			cout << "Please enter the ending index: ";
			cin >> n;
			if (index < 0 || n > limit) 
			{
				cout << "Error: one or more indices are outside the bounds of the array.";
			} 
			else 
			{
				option_05(sentence, index, n);
			}
		}
		
		// As you can see, I used limit in order to promp the errors.
		
		
		else if (choice == 6) 
		{
			option_06(sentence);
		}
		
		
		// Clear the buffer.
		cin.getline(sentence, 256);
		limit = 0;
		cin.ignore('\0');

		// The loop will quit once 7 is entered.
		}while(choice != 7);
	
	
	
	return 0;
}

// The functions 

int option_01(char sentence[], char& search, int& count)
{
	int index = -1;
	
	cout << "Please enter the character to search for: ";
	cin >> search;
	
	for (int i = 0; i < 256; i++)
	{
		if (sentence[i] == search)
        {
            if (index == -1)
            {
                count++;
                index = i;
            }
            else
            {
                count++;
            }
        }
	}
	return index;
}

void option_02(char sentence[], char& search, int& index)
{

	// Searching for a character
	for (int i = 0; i < 256; i++)
	{
		if (index == i)
		{
			sentence [i] = search;
		}
	}
    
}

void option_03(char sentence[], int n)
{
	// Displaying the first number of characters
	for (int i = 0; i < n; i++)
	{
		cout << sentence[i];
	}
	cout << endl;
}

void option_04(char sentence[], int n, int limit)
{
	
	for (int i = limit - n + 1; i < 256; i++) 
	{
		cout << sentence[i];
	}
	cout << endl;
}

void option_05(char sentence[], int first_index, int last_index)
{
	for (int i = first_index + 1; i < last_index; i++)
	{
		cout << sentence[i];
	}
	
}

void option_06(char sentence[])
{
	bool null;
	
	// Checking to see if arrays was aleary null
	for (int i = 0; i < 256; i++)
	{
		if (sentence[i] == '\0')
		{
			null = true;
		}
		else 
		{
			null = false;
			break;
		}
	}
	
	// Nullifying the array
	for (int i = 0; i < 256; i++) 
	{
		sentence[i] = '\0';
	}
	
	if (null)
	{
		cout << endl << "The string was already Null. Nothing was changed.";
	}
	else
	{
		cout << endl << "The string is now Null.";
	}
}

//////////////////////////////////////////////
// THE PROGRAM RUNS JUST LIKE YOUR EXAMPLE  //
// I FOLLOWED THE MODEL                     //
//////////////////////////////////////////////
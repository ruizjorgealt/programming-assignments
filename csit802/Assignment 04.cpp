//	Jorge A. Ruiz
//	Professor Sefiani
//	Computer Science 802
//	Sunday, May 04, 2014
//	Assigment 04

#include <iostream>
#include <string>
using namespace std;
int main()
{
	
	// Creating random number
	srand((unsigned) time(0));
	
	// Declaring and Initialiazing variables
	int		num,						// For creating random number
            chronoNum		=	0,	// Chronological Order
            answer,					// User input
            score			=	0,	// Total points score
            questionNumb	=	1,	// Initial number of question
            trials,					// Number of trials per question
				maxQuestions 	=	10;// Maximun number of question
	string	president;				//	President's name and period

	cout << "Enter the order number for each of the following presidents: " << endl << endl;

	// Loop iterates if we have less than 10 questions, which is the max in this case
	while (questionNumb < maxQuestions)
	{
		// Assigns random number between 1 and 10
		num = 1 + rand() % 10;
		
		// Prevents repeating of presidents in a consecutive order
		// Won't be asking for the same president twice or more
		while (num == chronoNum)
		num = 1 + rand() % 10;
		
		// Assigns Presidents and Chronological order to variables
		switch (num)
		{
			case 1:	president = "George Washington (1789-1797)";
					 		chronoNum = 1;
					 		break;
			case 2:	president = "John Adams (1797-1801)";
					 		chronoNum = 2;
					 		break;
			case 3:	president = "Thomas Jefferson (1801-1809)";
					 		chronoNum = 3;
					 		break;
			case 4:	president = "James Madison (1809-1817)";
					 		chronoNum = 4;
					 		break;
			case 5:	president = "James Monroe (1817-1825)";
					 		chronoNum = 5;
							break;
			case 6:	president = "John Quincy Adams (1825-1829)";
					 		chronoNum = 6;
					 		break;
			case 7: 	president = "Andrew Jackson (1829-1837)";
							chronoNum = 7;
							break;
			case 8:	president = "Martin Van Buren (1837-1841)";
							chronoNum = 8;
							break;
			case 9:	president = "William H. Harrison (1841)";
							chronoNum = 9;
							break;
			case 10:	president = "John Tyler (1841-1845)";
							chronoNum = 10;
							break;					}
		
		// Displays the question and allows the user to input an answer
		cout << president << ": ";
		cin >> answer;
		
		// Enters nested inner loop for trials and right/wrong answer
		for (trials = 1; trials < 3; trials++)
		{
			// If answer is wrong we give the player two more chances
			if (answer != chronoNum)
			{	
				cout << "Wrong! Try again: ";
				cin >> answer;
			}	
			
			// If answer is right, then we add 1 to score and break loop to restart another question
			if (answer == chronoNum)
			{
				cout << "Right!" << endl;
				score++;
				break; 
			}
		}
		
		// If the players had the max trials per question; we display correct answer
		if (trials == 3)
		cout << "The correct answer is " << chronoNum << endl;
		questionNumb++;
	} 
	
	// Displays score once loop condition is false
	cout << endl << "You answered " << score << " of " << maxQuestions << " correctly." << endl; 
	
	system("pause");
	return 0;
}
/* Do test_02 using the while loops */

#include <iostream>
#include <ctime>

using namespace std;
int main()
{
	srand((unsigned)time(0));
	int num, choice, correct = 0, tries = 0, max = 10;
		
	
	num = 1 + rand() % 6;
	
	while (tries < max)4
	{
		if (num > 0 && num <= 6)
			{
				if (num == 1)
				{	cout << "George Washington: ";
					cin >> choice;
					if (choice == 1)
					{
						cout << "\nRight!\n";
						correct += 1;
					}
					else
						cout << "\nWrong!\n";
				}

				else if (num == 2)
				{	cout << "John Adams: ";
					cin >> choice;
					if (choice == 2)
					{
						cout << "\nRight!\n";
						correct += 1;
					}
					else
						cout << "\nWrong!\n";
				}
				else if (num == 3)
				{	cout << "Thomas Jefferson: ";
					cin >> choice;
					if (choice == 3)
					{
						cout << "\nRight!\n";
						correct += 1;
					}
					else
						cout << "\nWrong!\n";
				}
				else if (num == 4)
				{	cout << "James Madison: ";
					cin >> choice;
					if (choice == 4)
					{
						cout << "\nRight!\n";
						correct += 1;
					}
					else
						cout << "\nWrong!\n";
				}
				else if (num == 5)
				{	cout << "James Monroe: ";
					cin >> choice;
					if (choice == 5)
					{
						cout << "\nRight!\n";
						correct += 1;
					}
					else
						cout << "\nWrong!\n";
				}
				else if (num == 6)
				{	cout << "John Quicy Adams: ";
					cin >> choice;
					if (choice == 6)
					{
						cout << "\nRight!\n";
						correct += 1;
					}
					else
						cout << "\nWrong!\n";
				}
			}

		num = 1 + rand() % 6;
		tries++;
	}
	
	cout << "\nYou got " << correct << " out of " << max << endl;
}
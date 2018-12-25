// Jorge A. Ruiz
// Professor Sefiani
// Computer Science 802
// Sunday, March 30, 2014
// Assigment 03

#include <iostream>
#include <ctime>

using namespace std;
int main()
{
	// Declaring variables
	int days, month;
	int year, leap;
	char slash = '/';
	
	// Generating random numbers that will become the date
	srand((unsigned)time(0));
	
	// Assigning the days and month
	days = 1 + rand() % (31 - 1 + 1);
	month = 1 + rand() % (12 - 1 + 1);


	// Filters the existing holidays
	if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
		|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
		{
			cout << "Generated " << month << slash << days << " which is a Holiday." << endl;
			
			// New date is generated since it was a holiday
			days = 1 + rand() % 31;
			month = 1 + rand() % 12;
			
			// Filters the existing holidays 
			if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
				|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
				{
					cout << "Generated the alternate of " << month << slash << days << " which is a Holiday.";
				}
			// Filters the invalid dates
			else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
				{
					cout << "Generated the alternate of " << month << slash << days << " which is invalid.";
				}	
			// Filters the leap date
			else if (month == 2 && days == 29)
				{
					cout << "Generated " << month << slash << days << endl;
					cout << "Enter current year: ";
					cin >> year;
					leap = year % 4;
					
					if(leap == 0)
						cout << year << " is a leap year so " << month << slash << days << " is valid.";
					else if (leap != 0)
					{
						cout << year << " is not leap year so " << month << slash << days << " is invalid.";

					}
				}
			// Displays if date is valid
			else 
				cout << "Generated the alternate of " << month << slash << days << " as a new Holiday.";
		}
	
	// Filters the invalid dates	
	else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
		{
			cout << "Generated " << month << slash << days << " which is invalid." << endl;
			
			// New date is generated since it was an invalid date
			days = 1 + rand() % 31;
			month = 1 + rand() % 12;
			
			// Filters holidays
			if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
				|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
				{
					cout << "Generated the alternate of " << month << slash << days << " which is a Holiday.";
					
					// Generates new date since it is a holiday
					days = 1 + rand() % 31;
					month = 1 + rand() % 12;
					
					// Filters holidays
					if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
						|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
						{
							cout << "Generated " << month << slash << days << " which is a Holiday.";
						}
					
					// Filters invalid dates
					else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
						{
							cout << "Generated " << month << slash << days << " which is invalid.";
							days = 1 + rand() % 31;
							month = 1 + rand() % 12;
							
							if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
								|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
								{
									cout << "Generated " << month << slash << days << " which is a Holiday.";
								}
								
							else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
								{
									cout << "Generated " << month << slash << days << " which is invalid.";
									
									// Generates new date since it is invalid
									days = 1 + rand() % 31;
									month = 1 + rand() % 12;
									
									if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
										|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
										{
											cout << "Generated " << month << slash << days << " which is a Holiday.";
										}
										
									else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
										{
											cout << "Generated " << month << slash << days << " which is invalid.";
										}	

									else if (month == 2 && days == 29)
										{
											cout << "Generated " << month << slash << days << endl;
											cout << "Enter current year: ";
											cin >> year;
											leap = year % 4;
											
											if(leap == 0)
												cout << year << " is a leap year so " << month << slash << days << " is valid.";
											else if (leap != 0)
											{
												cout << year << " is not leap year so " << month << slash << days << " is invalid.";

											}
										}

									else 
										cout << "Generated " << month << slash << days << " as a Holiday.";

								}	

							else if (month == 2 && days == 29)
								{
									cout << "Generated " << month << slash << days << endl;
									cout << "Enter current year: ";
									cin >> year;
									leap = year % 4;
									
									if(leap == 0)
										cout << year << " is a leap year so " << month << slash << days << " is valid.";
									else if (leap != 0)
									{
										cout << year << " is not leap year so " << month << slash << days << " is invalid.";

									}
								}

							else 
								cout << "Generated " << month << slash << days << " as a Holiday.";
						}	
					// Filters leap date
					else if (month == 2 && days == 29)
						{
							cout << "Generated " << month << slash << days << endl;
							cout << "Enter current year: ";
							cin >> year;
							leap = year % 4;
							
							if(leap == 0)
								cout << year << " is a leap year so " << month << slash << days << " is valid.";
							else if (leap != 0)
							{
								cout << year << " is not leap year so " << month << slash << days << " is invalid.";

							}
						}

					else 
						cout << "Generated " << month << slash << days << " as a Holiday.";
					
				}
				
			else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
				{
					cout << "Generated the alternate of " << month << slash << days << " which is invalid.";
				}	
			
			else if (month == 2 && days == 29)
				{
					cout << "Generated " << month << slash << days << endl;
					cout << "Enter current year: ";
					cin >> year;
					leap = year % 4;
					
					if(leap == 0)
						cout << year << " is a leap year so " << month << slash << days << " is valid.";
					else if (leap != 0)
					{
						cout << year << " is not leap year so " << month << slash << days << " is invalid.";

					}
				}
			
			else 
				cout << "Generated the alternate of " << month << slash << days << " as a new Holiday.";
		}	
	
	// Filters the date that might be a leap year
	else if (month == 2 && days == 29)
		{
			// Determines if year is leap or not
			cout << "Generated " << month << slash << days << endl;
			cout << "Enter current year: ";
			cin >> year;
			leap = year % 4;
			
			// If leap year, then it displays the new date as valid
			if(leap == 0)
				cout << year << " is a leap year so " << month << slash << days << " is valid.";
			
			// Displays date as invalid, and generates a new date if NOT leap year
			else if (leap != 0)
			{
				cout << year << " is not leap year so " << month << slash << days << " is invalid.";
				
				days = 1 + rand() % 31;
				month = 1 + rand() % 12;
				
				if ((month == 1 && days == 1) || (month == 5 && days == 26) || (month == 7 && days == 4) 
					|| (month == 9 && days == 12) || (month == 11 && days == 25) || (month == 11 && days == 25))
					{
						cout << "Generated " << month << slash << days << " which is a Holiday.";
					}
					
				else if ((month == 4 && days == 31) || (month == 6 && days == 31) || (month == 9 && days == 31) || (month == 11 && days == 31))
					{
						cout << "Generated " << month << slash << days << " which is invalid.";
					}	

				else if (month == 2 && days == 29)
					{
						cout << "Generated " << month << slash << days << endl;
						cout << "Enter current year: ";
						cin >> year;
						leap = year % 4;
						
						if(leap == 0)
							cout << year << " is a leap year so " << month << slash << days << " is valid.";
						else if (leap != 0)
						{
							cout << year << " is not leap year so " << month << slash << days << " is invalid.";

						}
					}

				else 
					cout << "Generated " << month << slash << days << " as a Holiday.";

			}
		}
	// If there are no invalid dates, already existing dates, nor leap dates, then we display the new holiday. 
	else 
		cout << "Generated " << month << slash << days << " as a new Holiday." << endl;
		
		//system("pause");
		return 0;
}		
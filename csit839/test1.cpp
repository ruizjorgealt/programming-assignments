// Jorge A. Ruiz
// CSIT 839
// Professor Sefiani
// Test 01

#include <iostream>
#include <ctime>
//#include <conio.h>
using namespace std;

void sort(int [], int, int);

int main(){
	const long long int SIZE = 1000;

	int nums[SIZE], n;

	srand((unsigned)time(0));

	for (int i = 0; i < SIZE; i++){
		nums[i] = 0 + rand() % (1000 - 0 + 1);
	}

	cout << "List of numbers generated: ";

	for (int i = 0; i < SIZE; i++){
		cout << " " << nums[i];
	}

	cout << endl;
	
	cout << endl << "How many of the largest do you want moved to the end of the list? MAX: " << SIZE << " :: ";
	cin >> n;


	sort(nums, SIZE, n);

	cout << "Modified list after moving " << n 
		<< " elements to the end of the list:" << endl;

	for (int i = 0; i < SIZE; i++)
		cout << nums[i] << ' ';

	cout << endl << endl << "Press enter to continue";


	//_getch();
	return 0;
}

void sort(int nums[], int SIZE,int n){
	int tmp;
	cout << endl;

	//SORTING ALGORITHM; SWAP
	for (int i = 0; i < n; i++){
		for (int i = 0; i < (SIZE - 1); i++){
			if (nums[i] > nums[i+1]){
				tmp  = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = tmp;
			}
		}


	}


}

// JORGE A. RUIZ
// CSIT 839
// PROFESSOR SEFIANI

#include <iostream>
#include <ctime>

void sort(int array[][30],int , bool );
int binarySearch(int[][30], int, int, int [], int []);
void randomize(int nums[][30], int , int );
void oneDSort(int oneDarray[],int , bool);
void display(int nums[][30], int );
using namespace std;
int main(){
    
    int nums[15][30], search, col[15 * 30], row[15 * 30], count = 0, size, ch =1;
    int oneDarray[30];
    bool sorting;
    col[0] = -1;
    row[0] = -1;
    
    srand((unsigned)time(0));
    // Filling array with random numbers
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 30; j++){
            nums[i][j] = 1 + rand() % 100;
        }
    }
    
    // Prompts the user how to sort the array w/ loop that prevents trash input
    do{
    cout << "To sort from smallest to largest enter [1]" << endl;
    cout << "To sort from largest to smallest enter [2]" << endl;
    cout << "Enter choice: ";
    cin >> ch;
    }while(ch < 1 || ch > 2);
    
    if (ch == 1)
        sorting = true;
    else if (ch == 2)
        sorting = false;
    
    // Calls sort function
    sort(nums,15, sorting);
    display(nums, 15);   
    
    // Prompts user to enter a number to search for
    cout << endl << "Enter a number to search for: ";
    cin >> search;
    // Calls integer returning function
    count = binarySearch(nums, 15, search, row, col);
    // Displays results of searching for the integer
    if(row[0] != -1 && col[0] != -1){
        int n = count - 1;
        cout << endl << search << " was found " << count << " times ";
        for (int i = 0; i <= n; i++){
        cout << endl << "row " << row[i];
        cout << " and column " << col[i];
        }
    }
    else
        cout << search << " was not found!\n" << endl;

    // Loop to stop user from entering wrong number of rows
    do{
    cout << endl << "Enter number of rows to randomize: ";
    cin >> size;
    }while(size < 1 || size > 15);
    // Calls randomize function
    randomize(nums,15,size);
    
    // Displays 2d array w/ sorted rows
    cout << endl << "The last " << size 
         << " rows have been randomized: " << endl;
    display(nums, 15);   

    // For loop sends each row individually to the one-dimensional array
    // sort function to sort it, then place it back into the main 2d array
    for(int i = (15 - size); i < 15 ; i++){
        for(int j = 0; j < 30; j++){
            oneDarray[j] = nums[i][j];
        } 
        // Calls function to sort the one-dimensional array
        oneDSort(oneDarray, 30, sorting);
        // Places the sorted 1d array row back into the main 2d array
        for(int j = 0; j < 30; j++){
                nums[i][j] = oneDarray[j];
            }
    }
    // Displays 2d array with sorted rows
    // The array will be displayed according to your instructions; however,
    // you told me to ignore the part where we have to print the
    // array sorted in its entirely.
    cout << endl << "Randomized rows are now sorted: " << endl;
    display(nums, 15);  

    system("Pause");
    return 0;
}

// I sorted the array as a "whole" after you told me through e-mail
void sort(int nums[][30],int cols, bool sorting){
    int array[15 * 30];
    int n = 0, minIndex, minValue, size = cols * 30;
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < 30; j++){
            array[n] = nums[i][j];
            n++;
        }
    }
    // I used the selection for its efficiency 
    for(int startScan = 0; startScan < (size - 1); startScan++ ){
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++ ){
            if(array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
    if(sorting){
        n = 0;
        for(int i=0; i < cols; i++){
            for(int j=0; j < 30; j++){
                nums[i][j] = array[n];
                n++;
            }
        }
    }
    else{
        n = n - 1;
        for(int i=0; i < cols; i++){
            for(int j=0; j < 30; j++){
                nums[i][j] = array[n];
                n--;
            }
        }
    }

}

int binarySearch(int array[][30],int rows, int search, int r[], int c[]){
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 30; j++){
            if (array[i][j] ==  search){
                r[count] = i;
                c[count] = j;
                count++;
            }
        }
    }
    return count;
}

void randomize(int nums[][30], int MAX_ROWS, int size){
    int oneDarray[15 * 30];
    int n = 0;
    for(int i = (MAX_ROWS - size); i < MAX_ROWS; i++){
        for(int j = 0; j < 30; j++){
            nums[i][j] = 1 + rand() % 100;
            oneDarray[n]=nums[i][j];
            n++;
        }
    }
}

void oneDSort(int oneDarray[],int size, bool sorting){
    int minIndex, minValue;
    if(sorting){
        for(int startScan = 0; startScan < (size - 1); startScan++ ){
            minIndex = startScan;
            minValue = oneDarray[startScan];
            for(int index = startScan + 1; index < size; index++ ){
                if(oneDarray[index] < minValue){
                    minValue = oneDarray[index];
                    minIndex = index;
                }
            }
        oneDarray[minIndex] = oneDarray[startScan];
        oneDarray[startScan] = minValue;
        }
    }
    else{
        for(int startScan = 0; startScan < (size - 1); startScan++ ){
            minIndex = startScan;
            minValue = oneDarray[startScan];
            for(int index = startScan + 1; index < size; index++ ){
                if(oneDarray[index] > minValue){
                    minValue = oneDarray[index];
                    minIndex = index;
                }
            }
        oneDarray[minIndex] = oneDarray[startScan];
        oneDarray[startScan] = minValue;
        }

    }    
}

// Display the 2d array, this function was approved by you. I asked you in class
void display(int nums[][30], int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 30; j++){
            cout << nums[i][j] << ' ';
            
        }
        cout << endl;
    }
}


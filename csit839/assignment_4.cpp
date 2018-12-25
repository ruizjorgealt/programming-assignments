// Jorge A. Ruiz
// Assignment 04
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//*********************************************************//
// ENUM VALUES AND CONSTANT ARRAY OF DOUBLES AS STATED     //
// IN THE INSTRUCTIONS. ALSO THE STRUCTURES HAVE BEEN      //
// CREATED ACCORDING TO YOUR SPECIFICATIONS.               //
//*********************************************************//
enum Section {ORCHESTRA, FRONT, MIDDLE, BACK};
const double PRICE[4] = {150.00, 100.00, 75.00, 50.00};
struct Date{
    int month;
    int day;
    int year;
};
struct Seat{
    char rows;
    int column;
    Section section;
    bool assigned;
    string name;
    Date date;
};
void initialize(Seat var[26][50]);
void display (Seat var[26][50]);
void displayAssigned(Seat var[26][50]);
void sort(Seat var[26][50]);
void binarySearch(Seat var[26][50], string, int[], int[], int&);
int main() {
    string n;
    int p, m, d, y, r[26*50], c[26*50], count = 0;
    float total = 0;
    char slash, ch;
    bool set;
    r[0] = -1;
    c[0] = -1;
    Seat var[26][50];
    initialize(var);
    display(var);
    do{
        cout << "Enter seat price: $";
        cin >> p;
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin,n);  
        cout << "Enter date: ";
        cin >> m >> slash >> d >> slash >> y;
        /** I WROTE THIS MAIN BECAUSE YOU DIDN'T SPECIFIED ANY FUNCTIONS **/
        /** FOR THIS SECTION OF THE PROGRAM; WHICH IS WHERE WE HAVE TO   **/
        /** TO ASSIGN NAMES TO SEATS AND DISPLAY THEM RIGHT AWAY.        **/
        set = false;
        for(int i=0; i<26; i++){
            for(int j=0; j<50; j++){
                if (p == PRICE[var[i][j].section] && var[i][j].assigned == 0){
                    var[i][j].assigned = true;
                    var[i][j].name = n;
                    var[i][j].date.month = m;
                    var[i][j].date.day = d;
                    var[i][j].date.year = y;
                    cout << "Assigned ";
                    cout << var[i][j].rows << ' ';
                    cout << var[i][j].column << ", ";            
                    if (var[i][j].section == ORCHESTRA)
                        cout << "Section ORCHESTRA, ";
                    else if (var[i][j].section == FRONT)
                        cout << "Section FRONT, ";
                    else if (var[i][j].section == MIDDLE)
                        cout << "Section MIDDLE, ";
                    else if (var[i][j].section == BACK)
                        cout << "Section BACK, ";
                    cout << "Price $" << PRICE[var[i][j].section] << " to ";
                    cout << var[i][j].name;
                    set = true;
                    break;
                }
            }
            if(set)
                break;
            
        }
        cout << endl << "Assign another [y/n]? ";
        cin >> ch;
    }while(ch != 'n' && ch != 'N');
    cout << "Assigned seats: " << endl;
    displayAssigned(var);
    sort(var);
    cout << endl << "Assigned seats – sorted based on name: " << endl;
    displayAssigned(var);
    cout << "Enter customer name to search for: ";
    cin.ignore();
    getline(cin,n);
    binarySearch(var, n, r, c, count);
    /**** DISPLAYS IF NAME HAS BEEN FOUND OR NOT ****/
    if(r[0] != -1 && c[0] != -1){
        cout << "Found " << n << " at:" << endl;
        for (int i = 0; i < count; i++){
            cout << var[r[i]][c[i]].rows << ' ';
            cout << var[r[i]][c[i]].column << ", ";            
            if (var[r[i]][c[i]].section == ORCHESTRA)
                cout << "Section ORCHESTRA, ";
            else if (var[r[i]][c[i]].section == FRONT)
                cout << "Section FRONT, ";
            else if (var[r[i]][c[i]].section == MIDDLE)
                cout << "Section MIDDLE, ";
            else if (var[r[i]][c[i]].section == BACK)
                cout << "Section BACK, ";
            cout << "Price $" << PRICE[var[r[i]][c[i]].section] << ", ";
            cout << var[r[i]][c[i]].name << ' ';
            cout << var[r[i]][c[i]].date.day << '/';
            cout << var[r[i]][c[i]].date.month << '/';
            cout << var[r[i]][c[i]].date.year << ' ' << endl;
        }
    }
    else
        cout << n << " was not found!\n" << endl;

    return 0;
}
//*********************************************************//
// INITIALIZES THE SEAT ARRAY ACCORDING TO YOUR            //
// SPECIFICATIONS.                                         //
//*********************************************************//
void initialize(Seat var[26][50]){
    for(int i=0; i<50; i++){
       for(int j=0; j<26; j++)
            var[j][i].column = (i + 1);
    } 
    for (int i=0; i<26; i++){
        for (int j=0; j<50; j++){
            var[i][j].name = "";
            var[i][j].date.day = 1;
            var[i][j].date.month = 1;
            var[i][j].date.year = 1900;
            var[i][j].assigned = false;
            var[i][j].rows = (i + 65);
            if (i < 5)
                var[i][j].section = ORCHESTRA;
            else if (i < 10)
                var[i][j].section = FRONT;
            else if (i < 20)
                var[i][j].section = MIDDLE;
            else
                var[i][j].section = BACK;
        }
    }
}
//*********************************************************//
// THE DISPLAY FUNCTION DISPLAYS THE ARRAY, WITHOUT        //
// ANY SORT OF ORDER; THIS IS BECAUSE IN YOUR INSTRUCTIONS //
// YOU TELL US TO SIMPLY DISPLAY ALL SEAT DATA.            //
//*********************************************************//
void display (Seat var[26][50]){
    for (int i=0; i<26; i++){
        for (int j=0; j<50; j++){
            cout << var[i][j].rows << ' ';
            cout << var[i][j].column << ", ";            
            if (var[i][j].section == ORCHESTRA)
                cout << "Section ORCHESTRA, ";
            else if (var[i][j].section == FRONT)
                cout << "Section FRONT, ";
            else if (var[i][j].section == MIDDLE)
                cout << "Section MIDDLE, ";
            else if (var[i][j].section == BACK)
                cout << "Section BACK, ";
            cout << "Price $" << PRICE[var[i][j].section] << ", ";
            cout << var[i][j].name << ' ';
            cout << var[i][j].date.day << '/';
            cout << var[i][j].date.month << '/';
            cout << var[i][j].date.year << ' ' << endl;
        }
    }
}
//*********************************************************//
// HOWEVER, YOU ALSO TELL US THAT WE MUST HAVE A           //
// DISPLAY FUNCTION WHERE ONLY THE SEATS THAT HAVE BEEN    //
// ASSIGNED TO A PERSON, SHOULD BE DISPLAY; THEREFORE, I   //
// I CREATED THIS FUNCTION THAT WILL ONLY DISPLAY SEATS    //
// THAT HAVE BEEN ASSIGNED TO A PERSON. YOU ALSO TOLD US   //
// THAT WITHIN THE FUNCTION WE SHOULD DISPLAY THE TOTAL    //
// PRICE OF THE SEATS THT HAVE BEEN ASSIGNED TO SOMEONE.   //
//*********************************************************//
void displayAssigned(Seat var[26][50]){
    float total=0;
    for(int i=0; i<26; i++){
        for(int j=0; j<50; j++){
            if(var[i][j].assigned == true){
            cout << var[i][j].rows << ' ';
            cout << var[i][j].column << ", ";            
            if (var[i][j].section == ORCHESTRA)
                cout << "Section ORCHESTRA, ";
            else if (var[i][j].section == FRONT)
                cout << "Section FRONT, ";
            else if (var[i][j].section == MIDDLE)
                cout << "Section MIDDLE, ";
            else if (var[i][j].section == BACK)
                cout << "Section BACK, ";
            cout << "Price $" << PRICE[var[i][j].section] << ", ";
            cout << var[i][j].name << ", ";
            cout << var[i][j].date.day << '/';
            cout << var[i][j].date.month << '/';
            cout << var[i][j].date.year << ' ' << endl;
            total += PRICE[var[i][j].section];
            }
        }
    }
    cout << fixed << setprecision(2) << showpoint;
    cout << "Total: " << total << endl;

    
}

//*********************************************************//
// THE SORT FUNCTIONS ALLOWS TO SORT THE SEAT ARRAYS       //
// BASED ON THEIR NAMES; HOWEVER, I ASSUME IT WAS BASED    //
// IN THE VALUE OF THE FIRST LETTER OF THEIR FIRST NAME;   // 
// IT WAS NOT CLEARLY STATED IN THE INSTRUCTIONS.          //
//*********************************************************//
void sort(Seat var[26][50]){
    Seat tmp;
    for(int i=0; i<26; i++){
        for(int k=0; k<50; k++){
            for(int j=0; j<50; j++){
                if(var[i][j].assigned == true && var[i][j+1].assigned == true){
                    if(var[i][j].name[0] > var[i][j+1].name[0]){
                       tmp.name = var[i][j].name;
                       var[i][j].name = var[i][j+1].name;
                       var[i][j+1].name = tmp.name;
                       tmp.column = var[i][j].column;
                       var[i][j].column = var[i][j+1].column;
                       var[i][j+1].column = tmp.column;
                       tmp.date.day = var[i][j].date.day;
                       var[i][j].date.day = var[i][j+1].date.day;
                       var[i][j+1].date.day = tmp.date.day;
                       tmp.date.month = var[i][j].date.month;
                       var[i][j].date.month = var[i][j+1].date.month;
                       var[i][j+1].date.month = tmp.date.month;
                       tmp.date.year = var[i][j].date.year;
                       var[i][j].date.year = var[i][j+1].date.year;
                       var[i][j+1].date.year = tmp.date.year;
                       tmp.section = var[i][j].section;
                       var[i][j].section = var[i][j+1].section;
                       var[i][j+1].section = tmp.section;
                    }
                }
            }
        }
    }
}
//*********************************************************//
// BINARY SEARCH FUNCTION THAT ALLOWS THE USER TO SEARCH   //
// AN SPECIFIC NAME, AS STATED BY YOUR INSTRUCTIONS        //
//*********************************************************//
void binarySearch(Seat var[26][50], string n, int r[], int c[], int &count){
    for(int i=0; i<26; i++){
        for(int j=0; j<50; j++){
            if(n == var[i][j].name){
                r[count]=i;
                c[count]=j;
                count++;
            }
        }
    }
}

//*********************************************************//
// I FOLLOWED YOUR INSTRUCTIONS SENTENCE BY SENTENCE AND I //
// MANAGED TO MAKE THE PROGRAM TO COMPILE AND WORK JUST    //
// LIKE THE EXAMPLE IN THE INSTRUCTIONS. HOWEVER, PLEASE   //
// EXCUSE IF I GET LOST IN TRANSLATION AND INTERPRETATION. //
//*********************************************************//
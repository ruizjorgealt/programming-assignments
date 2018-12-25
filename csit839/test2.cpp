//JORGE A RUIZ

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
	string states[120] = {"Afghanistan", "Albania", "Algeria", "Angola",  "Armenia", " Austria", "Bangladesh", "Barbados",  "Belgium",  "Belize"," Bolivia", "Bosnia and Herzegovina"," Botswana"," Bulgaria", "Cambodia", "Chile", "Colombia", "Congo"," Costa Rica", "Croatia", "Cuba", "Cyprus", "Czech Republic", "Denmark", "Dominican Republic", "East Timor", "Ecuador", "Egypt", "El Salvador", "Eritrea", "Estonia", "Ethiopia", "Finland", "Georgia", "Ghana", "Grenada", "Guatemala", "Guinea", "Guyana"," Haiti", "Honduras", "Hungary", "Iceland", "India", "Indonesia", "Iran", "Iraq", "Ireland", "Jamaica", "Jordan", "Kazakhstan"," Kenya", "Korea, North", "Korea, South", "Kosovo", "Kuwait", "Kyrgyzstan", "Laos"," Latvia", "Lebanon", "Liberia", "Libya", "Lithuania", "Macedonia", "Madagascar", "Malaysia", "Moldova", "Mongolia", "Montenegro", "Morocco", "Mozambique", "Myanmar", "Namibia", "Nepal", "New Zealand", "Nicaragua", "Nigeria", "Norway", "Oman", "Pakistan", "Panama", "Paraguay", "Peru", "Philippines", "Poland", "Portugal", "Qatar", "Romania", "Rwanda", "Saudi Arabia", "Senegal", "Serbia", "Sierra Leone", "Singapore", "Slovakia", "Somalia", "South Africa", "Sri Lanka", "Sudan", "Sweden", "Switzerland", " Syria", "Taiwan", "Tajikistan", "Tanzania", "Thailand", "Tunisia", "Turkey", "Turkmenistan", "Uganda", "Ukraine", "United Arab Emirates", "Uruguay", "Uzbekistan", "Venezuela", "Vietnam", "Zambia", "Zimbabwe"};
	string capitals[120] = {"Kabul", "Tirana", "Algiers", "Luanda", "Yerevan", "Vienna", "Dhaka", "Bridgetown", "Brussels", "Belmopan", "Sucre", "Sarajevo", "Gaborone", "Sofia", ", Phnom Penh", "Santiago", "Santafe de Bogota", "Kinshasa", "San Jose", "Zagreb", "Havana", "Lefkosia", "Prague", "Copenhagen", "Santo Domingo", "Dili", "Quito", "Cairo", "San Salvador", "Asmara", "Tallinn", "Addis Ababa", "Helsinki", "Tbilisi", "Accra", "St. Georges", "Guatemala City", "Conakry", "Georgetown", "Port-au-Prince", "Tegucigalpa", "Budapest", "Reykjavik", "New Delhi", "Jakarta", "Tehran", "Baghdad", "Dublin", "Kingston", "Amman", "Astana", "Nairobi", "Pyongyang", "Seoul", "Pristina", "Kuwait", "Bishkek", "Vientiane", "Riga", "Beirut", "Monrovia", "Tripoli", "Vilnius", "Skopje", "Antananarivo", "Kuala Lumpur", "Chisinau", "Ulaan Baatar", "Podgorica", "Rabat", "Maputo", "Rangoon", "Windhoek", "Kathmandu", "Wellington", "Managua", "Abuja", "Oslo", "Muscat", "Islamabad", "Panama City", "Asunción", "Lima", "Manila", "Warsaw", "Lisbon", "Doha", "Bucharest", "Kigali", "Riyadh", "Dakar", "Belgrade", "Freetown", "Singapore", "Bratislava", "Mogadishu", "Pretoria", "Colombo", "Khartoum", "Stockholm", "Bern", "Damascus", "Taipei", "Dushanbe", "Dodoma", "Bangkok", "Tunis", "Ankara", "Ashgabat", "Kampala", "Kiev", "Abu Dhabi", "Montevideo", "Tashkent", "Caracas", "Hanoi", "Lusaka", "Harare"};	
	string answer;
	int selected[10];
	float pts = 0;
	float total = 0;
	int n[10];
	int trials = 0;
	float score;
	srand((unsigned)time(0));

	for(int i = 0; i < 10; i++){
		for(int d = 0 ; d < 10; d++){
			n[d] = selected[d] = 1 + rand() % 119;
			cout << n[d] << endl;
		}
			

		for (int r = 0; r < 10; r++){
			for (int a = 0; a < 10; a++){
				if (n[a] == selected[a]){
					while(n[a] == selected[a]){ 
						n[a] = 1 + rand() % 119;
					}
				}
			}
		}
		
		
		for (int b = 0; b < 10; b++) {
			cout << n[b] << " " << selected[b] << endl;
			
		}
		
		selected[i] = n[i];
		cout << "What is the capital of " << states[n[i]] << "? ";
		getline(cin, answer);
		if (answer == "q" || answer == "Q")
			break;

		for (trials = 1; trials < 3; trials++){
			// If answer is wrong we give the player two more chances
			if(trials == 1)
						total += 1;
			if (answer != capitals[n[i]])
			{
				cout << "Wrong! Try again: ";
				getline(cin, answer);
			}

			// If answer is right, then we add 1 to score and break loop to restart another question
			if (answer == capitals[n[i]])
			{
				cout << "Right!" << endl;
				pts += 1;
				break;
			}

		}

		if (trials == 3)
			cout << "The capital of " << states[n[i]] << " is " << capitals[n[i]] << endl;

	}
	score = ((pts/total)*100);
	cout << fixed << setprecision(2) << showpoint;
	cout << "The score percentage is " << score << "%" << endl;
	
	

	system("Pause");
	return 0;
}
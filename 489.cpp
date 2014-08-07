//Steven Kester Yuwono - UVa 489 - Hangman Judge

#include <iostream>
#include <sstream>
using namespace std;

bool isAllGuessed(bool chosenChar[]){
	for(int i=0;i<200;i++){
		if(chosenChar[i]==true){
			return false;
		}
	}
	return true;
}

int main(){
	bool chosenChar[200];
	bool guessedChar[200];
	for(int i=0;i<200;i++){
		chosenChar[i]=false;
		guessedChar[i]=false;
	}
	int countWrong=0;
	char tempChar;
	string tempString;
	int round=0;
	cin >> round;
	getline(cin,tempString);
	while(round!=-1){
		countWrong=0;
		
		getline(cin,tempString);
		istringstream istream(tempString);
		while(istream >>tempChar){
			chosenChar[tempChar]=true;
		}
		
		getline(cin,tempString);
		istringstream istream2(tempString);
		while(istream2 >> tempChar){
			if(chosenChar[tempChar]==true){
				chosenChar[tempChar]=false;
			}
			else if (chosenChar[tempChar]==false){
				if(guessedChar[tempChar]==false){
					countWrong++;
				}
			}
			guessedChar[tempChar]=true;
			if(isAllGuessed(chosenChar)){
				break;
			}
		}
		
		cout << "Round " << round << endl;
		if(isAllGuessed(chosenChar)){
			if(countWrong<7){
				cout << "You win." << endl;
			}
			else{
				cout << "You lose." << endl;
			}
		}
		else{
			if(countWrong<7){
				cout << "You chickened out." << endl;
			}
			else{
				cout << "You lose." << endl;
			}
		}
		for(int i=0;i<200;i++){
			guessedChar[i]=false;
			chosenChar[i]=false;
		}
		cin >> round;
		getline(cin,tempString);
	}
	
	return 0;
}

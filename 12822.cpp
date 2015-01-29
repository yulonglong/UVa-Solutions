//Steven Kester Yuwono - UVa 12822

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

int currTime;
int currScoreHome;
int currScoreGuest;
long long energyHome;
long long energyGuest;

int energy[9];
void init(){
	energy[0] = 6;
	energy[1] = 2;
	energy[2] = 5;
	energy[3] = 5;
	energy[4] = 4;
	energy[5] = 5;
	energy[6] = 6;
	energy[7] = 3;
	energy[8] = 7;
	energy[9] = 6;
	return;
}

void init2(){
	currTime = 0;
	currScoreHome = 0;
	currScoreGuest = 0;
	energyHome = 0;
	energyGuest = 0;
	return;
}

int convertTime(string t) {
	istringstream istream(t);
	string h,m,s;
	getline(istream,h,':');
	getline(istream,m,':');
	getline(istream,s);
	int tm = (atoi(h.c_str())*3600) + (atoi(m.c_str())*60) + atoi(s.c_str());
	return tm;
}

void calculateEnergy(int intTime) { 
	if(currScoreHome == 0){
		energyHome += (6*(intTime-currTime));
	}
	else {
		long long energyConsumed = 0;
		int tempCurrScoreHome = currScoreHome;
		while (tempCurrScoreHome > 0) {
			int digit = tempCurrScoreHome % 10;
			energyConsumed += energy[digit];
			tempCurrScoreHome /= 10;
		}
		energyHome += (energyConsumed*(intTime-currTime));
	}

	if(currScoreGuest == 0){
		energyGuest += (6*(intTime-currTime));
	}
	else {
		long long energyConsumed = 0;
		int tempCurrScoreGuest = currScoreGuest;
		while (tempCurrScoreGuest > 0) {
			int digit = tempCurrScoreGuest % 10;
			energyConsumed += energy[digit];
			tempCurrScoreGuest /= 10;
		}
		energyGuest += (energyConsumed*(intTime-currTime));
	}
}

int main() {
	init();
	string cmd;
	string t;
	int tc = 0;
	
	while(getline(cin,cmd,' ')) {
		if (cmd == "START") {
			tc++;
			init2();
			getline(cin,t);
			currTime = convertTime(t);
		}
		else if (cmd == "SCORE") {
			getline(cin,t,' ');
			string team;
			getline(cin,team,' ');
			string scoreStr;
			getline(cin,scoreStr);
			int score = atoi(scoreStr.c_str());
			int intTime = convertTime(t);

			calculateEnergy(intTime);

			if(team == "home"){
				currScoreHome += score;
			}
			else if(team == "guest"){
				currScoreGuest += score;
			}
			currTime = intTime;
		}
		else if (cmd == "END") {
			getline(cin,t);
			int intTime = convertTime(t);
			calculateEnergy(intTime);
			cout << "Case " << tc << ": " << energyHome + energyGuest << endl;
		}
	}
	return 0;
}
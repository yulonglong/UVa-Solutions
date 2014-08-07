//579 - ClockHands

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
	string hour;
	int hourInt;
	double hourAngle;
	string minute;
	int minuteInt;
	double minuteAngle;
	double totalAngle;
	int index=0;
	string word;
	
	
	getline(cin,word);
	while(word!="0:00"){
		for(int i=0;i<4;i++){
			if(word[i]==':'){
				index=i;
			}
		}
		hour=word.substr(0,index);
		minute=word.substr(index+1);
		hourInt = atoi(hour.c_str());
		minuteInt = atoi(minute.c_str());
		
		hourAngle = (((double)hourInt+(double)minuteInt/60.0)/12.0)* 360.0;
		minuteAngle = ((double)minuteInt/60.0)* 360.0;
		if(hourAngle>minuteAngle){
			totalAngle=hourAngle-minuteAngle;
		}
		else{
			totalAngle=minuteAngle-hourAngle;
		}
		
		if (totalAngle>180){
			totalAngle=360.000-totalAngle;
		}
		
		cout << fixed;
		cout << setprecision(3) << totalAngle << endl;
		
		getline(cin,word);
	}
	return 0;
}

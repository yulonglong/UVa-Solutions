//573 - The Snail

#include <iostream>
using namespace std;

int main(){
	int H=0;
	int U=0;
	int D=0;
	int F=0;
	int day=1;
	double currPos=0;
	double currU=0;
	double fatigue=0;
	double doubleH = 0;
	
	cin >> H >> U >> D >> F;
	while(H>0){
		doubleH =H;
		day=1;
		currPos=0;
		currU=U;
		fatigue=(F/100.0)*U;
		do{
			currPos=currPos+currU;
			if(currPos>doubleH){
					cout << "success on day " << day << endl;
				break;
			}
			currPos=currPos-D;
			if(currPos<0){
				cout << "failure on day " << day << endl;
				break;
			}
			currU=currU-fatigue;
			if(currU<0){
				currU=0;
			}
			day++;
		}while(currPos>=0);
		cin >> H >> U >> D >> F;
	}
	
	return 0;
}

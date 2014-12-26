//Steven Kester Yuwono - UVa 10281

#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstdlib>
using namespace std;

int main(){
	string line;
	int currH, currM, currS, currSpeed;
	double currDist;
	currH = 0;
	currM = 0;
	currS = 0;
	currSpeed = 0;
	currDist = 0.0;
	while(getline(cin,line)){
		istringstream istream(line);
		string hstring, mstring, sstring;
		getline(istream,hstring,':');
		getline(istream,mstring,':');
		getline(istream,sstring,' ');
		bool changeSpeed = true;
		string speedstring;
		if(istream >> speedstring){
			changeSpeed = true;
		}
		else {
			changeSpeed = false;
		}

		int queryH = atoi(hstring.c_str());
		int queryM= atoi(mstring.c_str());
		int queryS = atoi(sstring.c_str());
		int querySpeed = atoi(speedstring.c_str());

		int currSec = currH*3600 + currM*60 + currS;
		int querySec = queryH*3600 + queryM*60 + queryS;
		int diffSec = querySec - currSec;
		double distTravelled = (double)diffSec * ((double)currSpeed*1000.0/3600.0) /1000.0;
		currDist = currDist + distTravelled;
		currH = queryH;
		currM = queryM;
		currS = queryS;

		if(changeSpeed){
			currSpeed = querySpeed;
		}
		else{
			printf("%.2d:%.2d:%.2d %.2f km\n", currH, currM, currS, currDist);
		}
	}
	return 0;
}
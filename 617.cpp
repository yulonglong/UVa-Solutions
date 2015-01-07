//Steven Kester Yuwono - UVa 617

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct traffic{
	double L;
	int G;
	int Y;
	int R;
	 bool operator<(const traffic& rhs) const { L < rhs.L; }
};

vector<traffic> store;
bool validSpeed[62];

bool isValidSpeed(int speed){
	bool valid = true;
	for (int i=0;i<(int)store.size();i++){
		double timetaken = store[i].L * 3600 / (double)speed ;
		int green = store[i].G*100;
		int yellow = store[i].Y*100;
		int red = store[i].R*100;
		int timetakenint = (int)(timetaken*100);
		//cout << timetakenint << endl;

		bool isRed = false;
		int currCheckpoint = 0;
		while (currCheckpoint <= timetakenint){
			if(!isRed){
				if((currCheckpoint <= timetakenint)&&(timetakenint <= currCheckpoint + green + yellow)){
					break;
				}
				currCheckpoint = currCheckpoint + green + yellow;
				isRed = true;
			}
			else {
				currCheckpoint = currCheckpoint + red;
				isRed = false;
			}
		}
		if(timetakenint < currCheckpoint){
			return false;
		}
	}
	return true;
}

void printAnswer(){
	bool first = true;
	bool inRange = false;
	int start = -1;
	int end = -1;
	for(int speed=30;speed<=61;speed++){
		if (validSpeed[speed]){
			if(!inRange){
				start = speed;
				end = speed;
				inRange = true;
			}
			else {
				end = speed;
			}
		}
		else {
			if(!((start==-1)&&(end==-1))){
				if(start==end){
					if(first){
						first = false;
						cout << start;
					}
					else{
						cout << ", " << start;
					}
				}
				else if (start<end){
					if(first){
						first = false;
						cout << start << "-" << end;
					}
					else{
						cout << ", " << start << "-" << end;
					}
				}
			}
			inRange = false;
			start = -1;
			end = -1;
		}
	}

	if(first){
		cout << "No acceptable speeds.";
	}
	cout << endl;
	return;
}

int main(){
	int n;
	int tc = 1;
	while ((cin >> n)&&(n != -1)){
		store.clear();
		memset(validSpeed,0,sizeof(validSpeed));

		for (int d=0;d<n;d++){
			traffic newTraffic;
			cin >> newTraffic.L >> newTraffic.G >> newTraffic.Y >> newTraffic.R;
			store.push_back(newTraffic);
		}
		sort(store.begin(),store.end());
		for(int speed=30;speed<=60;speed++){
			validSpeed[speed] = isValidSpeed(speed);
		}
		
		cout << "Case " << tc << ": ";
		printAnswer();
		tc++;
	}
	return 0;
}
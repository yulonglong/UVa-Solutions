// Steven Kester Yuwono - UVa 12554
#include <iostream>
#define MAX 101
using namespace std;

string name[MAX];

int main() {
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> name[i];
	}
	int currIndex = 0;
	for (int j=0;j<n/16+1;j++) {
		for(int i=0;i<4;i++){
			cout << name[currIndex] << ": Happy" << endl;
			currIndex = (currIndex+1)%n;
			cout << name[currIndex] << ": birthday" << endl;
			currIndex = (currIndex+1)%n;
			cout << name[currIndex] << ": to" << endl;
			currIndex = (currIndex+1)%n;
			if (i==2)
				cout << name[currIndex] << ": Rujia" << endl;
			else
				cout << name[currIndex] << ": you" << endl;
			currIndex = (currIndex+1)%n;
		}
	}
	return 0;
}

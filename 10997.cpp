//Steven Kester Yuwono - UVa 10997

#include <iostream>
using namespace std;

int store[21][3];

bool canadaWins(int n, int canadaIndex){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int maxIndex = -1;
				int maxScore = -1;
				for(int z=0;z<n;z++){
					int score = i*store[z][0] + j*store[z][1] + k*store[z][2];
					if(maxScore<score){
						maxScore = score;
						maxIndex = z;
					}
				}
				if(maxIndex == canadaIndex) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int tc;
	while ((cin>>tc)&&(tc>0)) {
		int canadaIndex = -1;
		for(int i=0;i<tc;i++){
			string country;
			int g,s,b;
			cin >> country >> store[i][0] >> store[i][1] >> store[i][2];

			if (country == "Canada") {
				canadaIndex = i;
			}
		}
		if(canadaWins(tc,canadaIndex)) {
			cout << "Canada wins!" << endl;
		}
		else {
			cout << "Canada cannot win." << endl;
		}
	}
	return 0;
}
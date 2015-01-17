//Steven Kester Yuwono - UVa 12545

#include <iostream>
using namespace std;

int getDiff(string S, string T){
	int unmatchedZeroS = 0;
	int unmatchedOneS = 0;
	int unmatchedQnZeroS = 0;
	int unmatchedQnOneS = 0;
	int zeroS = 0;
	int zeroT = 0;
	for(int i=0;i<(int)S.length();i++){
		if ((S[i] == '0')||(S[i] == '?')){
			zeroS++;
		}
		if (T[i] == '0') {
			zeroT++;
		}

		if (S[i] != T[i]) {
			if (S[i] == '1') {
				unmatchedOneS++;
			}
			else if (S[i] == '0') {
				unmatchedZeroS++;
			}
			else if (S[i] == '?') {
				if (T[i] == '1') {
					unmatchedQnOneS++;
				}
				else if (T[i] == '0') {
					unmatchedQnZeroS++;
				}
			}
		}
	}

	if (zeroT > zeroS){
		return -1;
	}
	int score = 0;
	score = min(unmatchedZeroS,unmatchedOneS);
	unmatchedZeroS -= score;
	unmatchedOneS -= score;
	if (unmatchedOneS > 0) {
		score += unmatchedOneS;
		unmatchedQnOneS -= unmatchedOneS;
		unmatchedQnZeroS += unmatchedOneS;
		unmatchedOneS = 0;
		score = score + unmatchedQnOneS + unmatchedQnZeroS;
	}
	else {
		score = score + unmatchedZeroS + unmatchedQnZeroS + unmatchedQnOneS;
	}
	return score;
}

int main() {
	int tc;
	cin >> tc;
	for(int d=1;d<=tc;d++){
		string S,T;
		cin >> S;
		cin >> T;
		cout << "Case " << d << ": " << getDiff(S,T) << endl;
	}
	return 0;
}
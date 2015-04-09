// Steven Kester Yuwono - UVa 12820

#include <iostream>
#include <cstring>
using namespace std;

bool isCool(string word) {
	int freq[27]; memset(freq,0,sizeof(freq));
	bool freqCount[30]; memset(freqCount,false,sizeof(freqCount));
	for(int i=0;i<word.length();i++) freq[word[i]-'a']++;
	int countLetters = 0;
	for(int i=0;i<27;i++){
		if(freq[i] > 0) {
			if(freqCount[freq[i]] == false) freqCount[freq[i]] = true;
			else return false;
			countLetters++;
		}
	}
	if(countLetters <= 1) return false;

	return true;
}

int main () {
	int n; int tc=1;
	while (cin >> n){
		int count =0;
		for(int i=0;i<n;i++) {
			string word; cin >> word;
			if(isCool(word)) count++;
		}
		cout << "Case " << tc++ << ": " << count << endl;
	}
	return 0;
}
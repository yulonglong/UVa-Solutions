// Steven Kester Yuwono - UVa 12718

#include <iostream>
#include <cstring>
using namespace std;

// start and end index are inclusive
int countDromicpalin(string &word,int start){
	int count = 0;
	int freq[27]; memset(freq,0,sizeof(freq));
	for(int end=start;end<(int)word.length();end++){
		freq[word[end]-'a']++;
		bool odd = true;
		if((end-start)%2 == 1) odd = false;

		bool valid = true;
		for(int i=0;i<27;i++){
			if(freq[i]%2 == 1) {
				if(!odd) {
					valid = false;
					break;
				}
				else {
					odd = false;
				}
			}
		}
		if(valid) count++;
	}
	return count;
}

int main() {
	int tc; cin >> tc;
	for(int d = 1; d<=tc; d++){
		int count = 0;
		string word; cin >> word;
		for(int i=0;i<(int)word.length();i++){
			count += countDromicpalin(word,i);
		}
		cout << "Case " << d << ": " << count << endl;
	}
	return 0;
}
// Steven Kester Yuwono - UVa 417
#include <iostream>
#include <map>
#define MAX 83682
using namespace std;

string store[MAX];
map<string,int> storeMap;
map<string,int>::iterator it;

void init() {
	// Store all possible strings in an array
	int index = 1;
	for(int i=0;i<26;i++){
		char curr = (i+'a');
		string currStr = "";
		currStr = curr;
		store[index++] = currStr;
	}
	int lowerRange = 1;
	int upperRange = 26;
	while(index < MAX) {
		for(int j=lowerRange;j<=upperRange;j++){
			string currStr = store[j];
			int nextIndex = currStr[currStr.length()-1]-'a'+1;
			for(int i=nextIndex;i<26;i++){
				char curr = (i+'a');
				string newStr = currStr + curr;
				store[index++] = newStr;
			}
		}
		lowerRange = upperRange + 1;
		upperRange = index-1;
	}

	// convert the array strings to map
	for(int i=1;i<MAX;i++){
		storeMap.insert(pair<string,int>(store[i],i));
	}
	return;
}

int getValue(string word){
	it = storeMap.find(word);
	if(it == storeMap.end()){
		return 0;
	}
	else {
		return it->second;
	}
}


int main() {
	init();
	string word;
	while (cin >> word) {
		cout << getValue(word) << endl;
	}
	return 0;
}
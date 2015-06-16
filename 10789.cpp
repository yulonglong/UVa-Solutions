// Steven Kester Yuwono - UVa 10789

#include <iostream>
#include <set>
#include <map>
#include <cstring>
#define MAX 2010
using namespace std;

set<int> primeSet;
set<int>::iterator itp;
map<char,int> freq;
map<char,int>::iterator it;

void init() {
	bool primeArray[MAX];
	memset(primeArray,true,sizeof(primeArray));
	primeArray[1] = false;
	for(int i=2;i<MAX;i++){
		if(primeArray[i]) {
			for(int j=i+i;j<MAX;j+=i) {
				primeArray[j] = false;
			}
		}
	}
	for(int i=2;i<MAX;i++){
		if(primeArray[i]) {
			primeSet.insert(i);
			//cout << i << endl;
		}
	}
}

int main() {
	init();
	int tc; cin >> tc;
	string temp; getline(cin,temp);
	for(int d=1;d<=tc;d++){
		freq.clear();
		string line;
		getline(cin,line);
		for(int i=0;i<(int)line.length();i++){
			it = freq.find(line[i]);
			if (it == freq.end()) {
				freq.insert(pair<char,int>(line[i],1));
			}
			else {
				it->second += 1;
			}
		}
		bool answered = false;
		cout << "Case " << d << ": ";
		for(it = freq.begin(); it != freq.end();it++){
			itp = primeSet.find(it->second);
			if(itp != primeSet.end()) {
				cout << it->first;
				answered = true;
			}
		}
		if(!answered) cout << "empty";
		cout << endl;
	}
	return 0;
}

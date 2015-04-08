// Steven Kester Yuwono - UVa 1584

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--){
		string sequence; cin >> sequence;
		int length = sequence.length();
		vector<string> store;
		store.push_back(sequence);
		for(int i=1;i<length;i++){
			string first = sequence.substr(i);
			string second = sequence.substr(0,i);
			store.push_back(first+second);
		}
		sort(store.begin(),store.end());
		cout << store[0] << endl;
	}
	return 0;
}
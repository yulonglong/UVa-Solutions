// Steven Kester Yuwono - UVa 902

#include <iostream>
#include <map>
using namespace std;

map<string, int> store;
map<string, int>::iterator it;

int main() {
	int N;
	while(cin >> N) {
		store.clear();
		string line;
		cin >> line;
		for(int i=0;i<(int)line.length()-N+1;i++){
			string temp;
			temp = line.substr(i,N);
			it = store.find(temp);
			if(it == store.end()) {
				store.insert(pair<string,int>(temp,1));
			}
			else {
				it->second += 1;
			}
		}
		int maxCount = 0;
		string maxStr;
		for(it = store.begin();it != store.end(); it++){
			if (it->second > maxCount) {
				maxCount = it->second;
				maxStr = it->first;
			}
		}
		cout << maxStr << endl;
	}
	return 0;
}
// Steven Kester Yuwono - UVa 11136

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
using namespace std;

map<int,int> store;
map<int,int>::iterator it;

int main() {
	string line;
	while ((getline (cin,line)) && (line !="0")) {
		store.clear();
		long long total = 0;
		store.clear();
		int n = atoi(line.c_str());
		for(int i=0;i<n;i++){
			getline(cin,line);
			istringstream istream(line);
			int num; istream >> num;
			while (istream >> num) {
				it = store.find(num);
				if (it == store.end()) {
					store.insert(pair<int,int>(num,1));
				}
				else {
					it->second += 1;
				}
			}
			it = store.begin();		
			int smallest = it->first;
			it->second -= 1;
			if (it->second == 0) store.erase(it);
			it = store.end(); it--;
			int largest = it->first;
			it->second -= 1;
			if (it->second == 0) store.erase(it);
			total = total + largest - smallest;
		}
		cout << total << endl;		
	}
	return 0;
}

// Steven Kester Yuwono - UVa 10374

#include <iostream>
#include <map>
using namespace std;

map<string,pair<string,int> > candidate;
map<string,pair<string,int> >::iterator it;
int main() {
	bool first = true;
	int tc;
	cin >> tc;
	while(tc--) {
		if(first) {
			first  = false;
		}
		else {
			cout << endl;
		}
		candidate.clear();

		string temp;
		int n,m;
		cin >> n;
		getline(cin,temp); // dummy getline
		for(int i=0;i<(n*2);i+=2){
			string name, party;
			getline(cin,name);
			getline(cin,party);
			pair<string,int> tempPair(party,0);
			candidate.insert(pair<string,pair<string, int> >(name,tempPair));
		}
		cin >> m;
		getline(cin,temp); // dummy getline
		for(int i=0;i<m;i++){
			string name;
			getline(cin,name);
			it = candidate.find(name);
			if(it!=candidate.end()){
				(it->second).second += 1;
			}
		}

		int max = -1;
		bool duplicate = false;
		string winningParty;
		for(it=candidate.begin();it!=candidate.end();it++){
			if ((it->second).second > max) {
				max = (it->second).second;
				duplicate  = false;
				winningParty = (it->second).first;
			}
			else if ((it->second).second == max) {
				duplicate = true;
			}
		}

		if(duplicate){
			cout << "tie" << endl;
		}
		else {
			cout << winningParty << endl;
		}
		
	}
	return 0;
}
// Steven Kester Yuwono - UVa 12168
// Augmenting Path

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#define V 502
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<ii> cats, dogs;
vector<vi> AdjList;
vi match, vis;

int Aug(int l) {
	if (vis[l])
		return 0;
	vis[l] = 1;
	for (int j = 0; j < (int)AdjList[l].size(); j++) {
		int r = AdjList[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--) {
		int c,d,v;
		cin >> c >> d >> v;

		cats.clear();
		dogs.clear();
		AdjList.clear();
		AdjList.assign(V, vi());

		for(int i=0;i<v;i++){
			string first, second;
			cin >> first >> second;
			int intFirst = atoi(first.substr(1).c_str());
			int intSecond = atoi(second.substr(1).c_str());;
			
			if(first[0] == 'D') {
				dogs.push_back(pair<int,int>(intFirst,intSecond));
			}
			else if(second[0] == 'D') {
				cats.push_back(pair<int,int>(intFirst,intSecond));
			}
		}

		int catSize = cats.size();
		int dogSize = dogs.size();

		for(int i=0;i<catSize;i++){
			for(int j=0;j<dogSize;j++){
				if ((cats[i].first == dogs[j].second) || (dogs[j].first == cats[i].second)) {
					AdjList[i].push_back(j);
				}
			}
		}

		int MCBM = 0;
		match.assign(V, -1);
		for (int l = 0; l < catSize; l++) {
			vis.assign(V, 0);
			MCBM += Aug(l);
		}
		printf("%d\n", v - MCBM);
	}
}

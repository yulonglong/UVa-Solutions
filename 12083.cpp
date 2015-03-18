// Steven Kester Yuwono - UVa 12083
// Augmenting Path

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define V 505
using namespace std;

struct Node {
	int height;
	string gender;
	string music;
	string sport;
	Node(int h, string g, string m, string s) : height(h), gender(g), music(m), sport(s) {}
};

vector<Node> male;
vector<Node> female;

bool isNoCouple(const Node &lhs, const Node &rhs){
	if (abs(lhs.height - rhs.height) > 40) {
		return true;
	}
	if (lhs.gender == rhs.gender) {
		return true;
	}
	if (lhs.music != rhs.music) {
		return true;
	}
	if (lhs.sport == rhs.sport) {
		return true;
	}
	return false;
}

typedef pair<int, int> ii;
typedef vector<int> vi;

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

void init() {
	male.clear();
	female.clear();
	AdjList.clear();
	AdjList.assign(V, vi());
}

int main(){
	int tc;
	cin >> tc;
	while (tc--) {
		init();
		int N;
		cin >> N;
		for(int i=0;i<N;i++){
			int h;
			string g,m,s;
			cin >> h >> g >> m >> s;
			Node newStudent(h,g,m,s);

			if (g == "M"){
				male.push_back(newStudent);
			}
			else{
				female.push_back(newStudent);
			}
			
		}
		int maleSize = male.size();
		int femaleSize = female.size();
		int Vleft = maleSize;

		for(int i=0;i<maleSize;i++){
			for(int j=0;j<femaleSize;j++){
				if (!isNoCouple(male[i],female[j])) {
					AdjList[i].push_back(j);
				}
			}
		}

		int MCBM = 0;
		match.assign(V, -1);
		for (int l = 0; l < Vleft; l++) {
			vis.assign(Vleft, 0);
			MCBM += Aug(l);
		}
		printf("%d\n", N - MCBM);
	}
}

// Steven Kester Yuwono - UVa 12644
// Maximum Cardinality Bipartite Matching (MCBM) Unweighted
// Augmenting Path

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
	int count[26];
};

bool isMultiply(Node &challenge, Node &vocab) {
	for(int i=0;i<26;i++){
		if (challenge.count[i] > vocab.count[i]) {
			return false;
		}
	}
	return true;
}

void createNode (string word, Node &newNode) {
	memset(newNode.count,0,sizeof(newNode.count));
	for(int i=0;i<(int)word.length();i++) {
		newNode.count[word[i]-'a']++;
	}
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

int main() {
	int n,m;
	while (cin >> n >> m) {
		int V = n+m;
		int Vleft = n;

		AdjList.clear();
		AdjList.assign(V, vi());

		vector<Node> vocab;
		vector<Node> chall;

		for(int i=0;i<n;i++){
			string temp;
			cin >> temp;
			Node newNode;
			createNode(temp,newNode);
			vocab.push_back(newNode);
		}

		for(int i=0;i<m;i++){
			string temp;
			cin >> temp;
			Node newNode;
			createNode(temp,newNode);
			chall.push_back(newNode);
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(isMultiply(chall[j],vocab[i])) {
					AdjList[i].push_back(j+n);
					AdjList[j+n].push_back(i);
				}
			}
		}
		
		int MCBM = 0;
		match.assign(V, -1);
		for (int l = 0; l < Vleft; l++) {
			vis.assign(Vleft, 0);
			MCBM += Aug(l);
		}
		printf("%d\n", MCBM);
	}
	return 0;
}

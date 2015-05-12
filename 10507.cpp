//Steven Kester Yuwono - UVa 10507

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#define MAX 1100
using namespace std;

class UnionFind{
	private:
	vector<int> p, rank;
	public:
	UnionFind(int N){
		rank.assign(N,0);
		p.assign(N,0);
		for(int i=0;i<N;i++){
			p[i]=i;
		}
	}
	int findSet(int i){
		return (p[i]==i) ? i :(p[i] = findSet(p[i]));
	}
	bool isSameSet(int i,int j){
		return findSet(i)==findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i), y = findSet(j);
			if(rank[x]>rank[y]){
				p[y]=x;
			}
			else{
				p[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
	}
};

int main(){
	int n, m;
	while(cin >> n >> m) {
		map<char,int> mappo;
		map<char,int>::iterator it;

		int index = 0;
		char active[3];
		for(int i=0;i<3;i++){
			cin >> active[i];
			mappo.insert(pair<char,int>(active[i],index++));
		}

		UnionFind uf(26);
		uf.unionSet(0,1);
		uf.unionSet(1,2);

		vector<int> adjList[MAX];

		for(int i=0;i<m;i++){
			char c1, c2;
			cin >> c1 >> c2;
			int index1, index2;

			it = mappo.find(c1);
			if(it == mappo.end()){
				index1 = index;
				mappo.insert(pair<char,int>(c1,index++));
			}
			else {
				index1 = it->second;
			}


			it = mappo.find(c2);
			if(it == mappo.end()){
				index2 = index;
				mappo.insert(pair<char,int>(c2,index++));
			}
			else {
				index2 = it->second;
			}

			adjList[index1].push_back(index2);
			adjList[index2].push_back(index1);
		}

		int currYear = -1;
		int prevConnected = 0;
		int currConnected = 3;
		while(currConnected > prevConnected){
			currYear++;
			prevConnected = currConnected;

			queue<int> q;

			for(int i=3;i<n;i++){
				if(uf.isSameSet(i,0)) continue;
				int countConnected = 0;
				for(int j=0;j<(int)adjList[i].size();j++){
					if(uf.isSameSet(adjList[i][j],0)) {
						countConnected++;
					}
				}
				if(countConnected >= 3){
					q.push(i);
				}
			}

			while(!q.empty()){
				uf.unionSet(q.front(),0);
				q.pop();
			}

			currConnected = 0;
			for(int i=0;i<n;i++){
				if(uf.isSameSet(i,0)) {
					currConnected++;
				}
			}
		}

		if (currConnected < n) {
			printf("THIS BRAIN NEVER WAKES UP\n");
		}
		else {
			printf("WAKE UP IN, %d, YEARS\n",currYear);
		}
	}
	return 0;
}

//Steven Kester Yuwono - UVa 11503

#include <bits/stdc++.h>
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

map<string,int> m;
int value[100000];

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		UnionFind uf(100000);
		for(int i=0;i<100000;i++){
			value[i]=1;
		}
		
		m.clear();
		int n;
		cin >> n;
		while(n--){
			string name1, name2;
			int p1, p2;
			cin >> name1 >> name2;
			map<string,int>::iterator it;
			it=m.find(name1);
			if(it!=m.end()){
				p1=it->second;
			}
			else{
				p1=m.size();
				m.insert(pair<string,int>(name1,p1));
			}
			it=m.find(name2);
			if(it!=m.end()){
				p2=it->second;
			}
			else{
				p2=m.size();
				m.insert(pair<string,int>(name2,p2));
			}
			
			if(!uf.isSameSet(p1,p2)){
				int set1=uf.findSet(p1);
				int set2=uf.findSet(p2);
				uf.unionSet(p1,p2);
				int set3=uf.findSet(p1);
				value[set3]=value[set1]+value[set2];
			}
			int set1=uf.findSet(p1);
			cout << value[set1] << endl;
		}
	}
		
	return 0;
}

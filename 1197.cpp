//Steven Kester Yuwono - UVa 1197

#include <cstdio>
#include <vector>
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
	while ((scanf("%d %d",&n,&m)==2)&& (n || m)) {
		UnionFind uf(n);
		for(int d=0;d<m;d++){
			int num; scanf("%d",&num);
			int initNum; scanf("%d",&initNum);
			for(int z=1;z<num;z++){
				int temp; scanf("%d",&temp);
				uf.unionSet(initNum,temp);
			}
		}
		int groupSuspect = uf.findSet(0);
		int count = 0;
		for(int i=0;i<n;i++) {
			if (uf.findSet(i) == groupSuspect) {
				count++;
			}
		}

		printf("%d\n",count);
	}
		
	return 0;
}

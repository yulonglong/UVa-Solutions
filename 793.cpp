//Steven Kester Yuwono - UVa 793

#include <iostream>
#include <sstream>
#include <cstdlib>
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
	string temp;
	getline(cin,temp);
	int tc = atoi(temp.c_str());
	getline(cin,temp); // blank line
	while(tc--){
		getline(cin,temp);
		int n = atoi(temp.c_str());
		
		int successful = 0;
		int unsuccessful = 0;
		UnionFind uf(n+1);

		while(true){
			getline(cin,temp);
			if(temp.length()==0) {
				cout << successful << "," << unsuccessful << endl;
				if (tc) cout << endl;
				break;
			}
			else {
				char query;
				int x,y;
				istringstream istream(temp);
				istream >> query >> x >> y;
				if(query == 'c') {
					uf.unionSet(x,y);
				}
				else {
					if(uf.isSameSet(x,y)) successful++;
					else unsuccessful++;
				}
			}
		}
	}
		
	return 0;
}

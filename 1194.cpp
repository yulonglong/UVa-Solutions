// Steven Kester Yuwono - UVa 1194

#include <cstdio>
#include <vector>
using namespace std;

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
	int n,m,k;
	while ((scanf("%d", &n)==1)&&(n!=0)) {
		scanf("%d %d",&m,&k);
		int V = n+m+1;
		int Vleft = n;

		AdjList.clear();
		AdjList.assign(V, vi());
		for(int i=0;i<k;i++){
			int jobNum, x, y;
			scanf("%d %d %d",&jobNum,&x,&y);
			AdjList[x].push_back(y+n);
			AdjList[y+n].push_back(x);
		}
		
		int MCBM = 0;
		match.assign(V, -1);
		for (int l = 1; l <= Vleft; l++) {
			vis.assign(Vleft, 0);
			MCBM += Aug(l);
		}
		printf("%d\n", MCBM);
	}
	return 0;
}

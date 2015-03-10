// Steven Kester Yuwono - UVa 12873
// Max Flow

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define INF 2000000000
#define MAX 525
using namespace std;


int res[MAX][MAX],f,s,t;
vector<int> p;
vector<int> edges[MAX];

void init() {
	memset(res,0,sizeof(res));
	for(int i=0;i<MAX;i++){
		edges[i].clear();
	}
}

void augment(int v, int minEdge){
	if (v==s){
		f=minEdge;
		return;
	}
	else if(p[v] !=-1){
		augment(p[v], min(minEdge,res[p[v]][v]));
		res[p[v]][v] -=f;
		res[v][p[v]] +=f;
	}
}

int EdmondKarp(){
	int totalmf=0;
	while(1){
		f=0;
		vector<int> dist(MAX,INF);
		dist[s]=0;
		queue<int> q;
		q.push(s);
		p.assign(MAX,-1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u == t) break;
			for(unsigned int x=0;x<edges[u].size();x++){
				int v=edges[u][x];
				if((res[u][v] > 0 )&& (dist[v]==INF)){
					dist[v] =dist[u]+1;
					q.push(v);
					p[v]=u;
				}
			}
		}
		augment(t,INF);
		if(f==0) break;
	
		totalmf+=f;
	}
	return totalmf;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		init();
		int P, S, C, m;
		scanf("%d %d %d %d",&P,&S,&C,&m);

		s = 0;
		t = P+S+1;
		for (int i=1;i<=P;i++){
			res[0][i] = 1;
			edges[0].push_back(i);
			edges[i].push_back(0);
		}

		for (int i=0;i<m;i++){
			int contestant, site;
			scanf("%d %d",&contestant,&site);
			res[contestant][site+P] = 1;
			edges[contestant].push_back(site+P);
			edges[site+P].push_back(contestant);
		}

		for(int i=1;i<=S;i++){
			res[i+P][t] = C;
			edges[i+P].push_back(t);
			edges[t].push_back(i+P);
		}

		printf("%d\n",EdmondKarp());
	}
}

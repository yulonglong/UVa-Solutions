//Steven Kester Yuwono - UVa 820

#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 2000000000
#define MAX 102
using namespace std;

int res[MAX][MAX],f,s,t;
vector<int> p;

void augment(int v, int minEdge){
	if (v==s){
		f=minEdge;
		return;
	}
	else if(p[v] !=-1){
		augment(p[v], min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
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
			int u = q.front(); q.pop();
			if (u == t) break;
			 for(int v = 0; v < MAX; v++) {
				if((res[u][v] > 0 )&& (dist[v]==INF)){
					dist[v] = dist[u]+1;
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
	int n;
	int tc = 1;
	while ((scanf("%d",&n)==1)&&(n!=0)) {
		memset(res,0,sizeof(res));
		int c;
		scanf("%d %d %d",&s,&t,&c);
		for(int i=0;i<c;i++){
			int from,to,cost;
			scanf("%d %d %d",&from,&to,&cost);
			res[from][to] += cost;
			res[to][from] += cost;
		}
		printf("Network %d\n",tc++);
		printf("The bandwidth is %d.\n\n",EdmondKarp());
	}
	return 0;
}

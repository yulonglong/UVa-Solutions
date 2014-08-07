//Steven Kester Yuwono - UVa 11045

#include <bits/stdc++.h>
#define MAX 40
#define INF 2000000000
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
		res[p[v]][v] -=f;
		res[v][p[v]] +=f;
	}
}

int EdmondKarp(){
	int totalmf=0;
	while(1){
		f=0;
		//BFS
		vector<int> dist(MAX,INF);
		dist[s]=0;
		queue<int> q;
		q.push(s);
		p.assign(MAX,-1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u==t) break;
			for(int v=0;v<MAX;v++){
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
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int tc;
	cin >> tc;
	while(tc--){
		memset(res,0,sizeof(res));
		int ns,np;
		cin >> ns >> np;
		for(int i=7;i<np+7;i++){
			res[i][np+7]=1;
		}
		int numType = ns/6;
		for(int i=1;i<=6;i++){
			res[0][i]=numType;
		}
		
		for(int d=7;d<np+7;d++){
			string first,second;
			cin >> first >> second;
			
			if(first=="XS"){
				res[1][d]=1;
			}
			else if(first=="S"){
				res[2][d]=1;
			}
			else if(first=="M"){
				res[3][d]=1;
			}
			else if(first=="L"){
				res[4][d]=1;
			}
			else if(first=="XL"){
				res[5][d]=1;
			}
			else if(first=="XXL"){
				res[6][d]=1;
			}
			
			if(second=="XS"){
				res[1][d]=1;
			}
			else if(second=="S"){
				res[2][d]=1;
			}
			else if(second=="M"){
				res[3][d]=1;
			}
			else if(second=="L"){
				res[4][d]=1;
			}
			else if(second=="XL"){
				res[5][d]=1;
			}
			else if(second=="XXL"){
				res[6][d]=1;
			}
		}
		
		s=0;
		t=np+7;
		int maxflow = EdmondKarp();
		if( maxflow == np){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}

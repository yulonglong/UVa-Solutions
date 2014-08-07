#include <bits/stdc++.h>
#define INF 2000000000
#define MAX 5100
using namespace std;


int res[MAX][MAX],f,s,t,s1,a,b;
vector<int> p;
vector<int> edges[5100];

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
	#ifndef ONLINE_JUDGE
	freopen("in2.txt","r",stdin);
	#endif
	
	int tc;
	cin >> tc;
	while(tc--){
		memset(res,0,sizeof(res));
		for(int i=0;i<MAX;i++){
			edges[i].clear();
		}
		
		cin >> s1 >> a >> b;
		
		int maxInitialVertex=s1*a;
		t=2*(s1*a)+1;
		s=0;
		
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				res[i][j]=0;
			}
		}
		
		for(int i=1;i<=maxInitialVertex;i++){
			if(i+a<=maxInitialVertex){
				edges[i+maxInitialVertex].push_back(i+a);
				res[i+maxInitialVertex][i+a]=1;
			}
			if(i-a>0){
				edges[i+maxInitialVertex].push_back(i-a);
				res[i+maxInitialVertex][i-a]=1;
			}
			if(i+1<=maxInitialVertex){
				edges[i+maxInitialVertex].push_back(i+1);
				res[i+maxInitialVertex][i+1]=1;
			}
			if(i-1>0){
				edges[i+maxInitialVertex].push_back(i-1);
				res[i+maxInitialVertex][i-1]=1;
			}
			edges[i].push_back(i+maxInitialVertex);
			res[i][i+maxInitialVertex]=1;
		}
		/*
		for(int i=1;i<=s1*a;i++){
			cout << res[maxInitialVertex+i][16] << " ";
			if(i%a==0){
				cout << endl;
			}
		}*/
		
		for(int i=1;i<=a;i++){
			edges[maxInitialVertex+i].push_back(t);
			res[maxInitialVertex+i][t]=1;
			edges[maxInitialVertex+i+(a*(s1-1))].push_back(t);
			res[maxInitialVertex+i+(a*(s1-1))][t]=1;
		}
		for(int i=1;i<=s1;i++){
			edges[maxInitialVertex+1+(i-1)*a].push_back(t);
			res[maxInitialVertex+1+(i-1)*a][t]=1;
			edges[maxInitialVertex+i+(i*(a-1))].push_back(t);
			res[maxInitialVertex+i+(i*(a-1))][t]=1;
		}
		/*
		cout << endl;
		for(int i=1;i<=s1*a;i++){
			cout << res[maxInitialVertex+i][t] << " ";
			if(i%a==0){
				cout << endl;
			}
		}*/
		/*
		for(int j=1;j<=s1*a;j++){
			cout << endl;
			for(int i=1;i<=s1*a;i++){
				cout << res[j][maxInitialVertex+i] << " ";
				if(i%a==0){
					cout << endl;
				}
			}	
		}*/
				
		
		for(int i=0;i<b;i++){
			int x,y;
			cin >> x >> y;
			int vertex= y+(a*(x-1));
			edges[0].push_back(vertex);
			res[0][vertex]=1;
		}
		/*
		cout << endl;
		for(int i=1;i<=s1*a;i++){
			cout << res[0][i] << " ";
			if(i%a==0){
				cout << endl;
			}
		}*/
		
		
		int mf=EdmondKarp();
		//cout << mf << endl;
		if(mf==b){
			cout << "possible" << endl;
		}
		else{
			cout << "not possible" << endl;
		}
		
	}
}

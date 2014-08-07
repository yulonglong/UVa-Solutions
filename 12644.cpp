//uva 12644
#include <bits/stdc++.h>
#define MAX_V 1010
#define INF 2000000000
using namespace std;

int res[MAX_V][MAX_V], mf, f ,s ,t,n;
int resCopy[MAX_V][MAX_V];
vector<int> p;
vector<int> adjL[MAX_V];

string jackword[MAX_V];
string jillchallenge[MAX_V];

void augment(int v, int minEdge){
	if (v==s){
		f=minEdge;
		return;
	}
	else if(p[v] !=-1){
		augment(p[v], min(minEdge,res[p[v]][v]));
		res[p[v]][v] -=f;
		res[v][p[v]] +=f;
		adjL[v].push_back(p[v]);
	}
}
int EK(){
	int totalmf=0;
	while(1){
		f=0;
		vector<int> dist(MAX_V,INF);
		dist[s]=0;
		queue<int> q;
		q.push(s);
		p.assign(MAX_V,-1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(unsigned int x=0;x<adjL[u].size();x++){
				int v=adjL[u][x];
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

bool solveChallenge(string jack,string jill){
	int jackcount[125];
	int jillcount[125];
	memset(jackcount,0,sizeof(jackcount));
	memset(jillcount,0,sizeof(jillcount));
	for(unsigned int i=0;i<jack.length();i++){
		jackcount[(int)jack[i]]++;
	}
	for(unsigned int i=0;i<jill.length();i++){
		jillcount[(int)jill[i]]++;
	}
	for(int i=0;i<125;i++){
		if(jackcount[i]<jillcount[i]){
			return false;
		}
	}
	return true;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int numjack,numjill;
	while(cin>>numjack>>numjill){
		memset(res,0,sizeof(res));
		for(int i=0;i<MAX_V;i++){
			adjL[i].clear();
		}
		for(int i=0;i<numjack;i++){
			cin >> jackword[i];
		}
		for(int i=0;i<numjill;i++){
			cin >> jillchallenge[i];
		}
		
		for(int i=1;i<=numjack;i++){
			res[0][i]=1;
			adjL[0].push_back(i);
		}
		for(int i=numjack+1;i<=numjack+numjill;i++){
			res[i][numjack+numjill+1]=1;
			adjL[i].push_back(numjack+numjill+1);
		}
		
		for(int i=0;i<numjill;i++){
			for(int j=0;j<numjack;j++){
				if(solveChallenge(jackword[j],jillchallenge[i])){
					res[j+1][numjack+1+i]=1;
					adjL[j+1].push_back(numjack+1+i);
				}
			}
		}
		s=0;
		t=numjack+numjill+1;
		
		int total = EK();
		cout << total << endl;
		
	}
	return 0;
}

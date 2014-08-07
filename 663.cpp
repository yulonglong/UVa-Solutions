//Steven Kester Yuwono - UVa 663

#include <bits/stdc++.h>
#define MAX_V 100
#define MAX 100
#define INF 2000000000
using namespace std;

int res[MAX_V][MAX_V], mf, f ,s ,t,n;
int resCopy[MAX_V][MAX_V];
vector<int> p,p2,p3;

void copy(int a[][100],int b[][100]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			a[i][j]=b[i][j];
		}
	}
}

void vectorCopy(vector<int> &a, vector<int> &b){
	a.clear();
	for(unsigned i=0;i<b.size();i++){
		a.push_back(b[i]);
		//cout << a[i] << " " << b[i] << endl;
	}
}

void augment(int v, int minEdge){
	if (v==s){
		f=minEdge;
		return;
	}
	else if (p[v] != -1){
		augment(p[v], min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
		if((v<n+65)&&(v>=65)){
			if(p[v]!=-1){
				p2[v]=p[v];
			}
		}
	}
}

int EK(){
	mf=0;
	p2.assign(MAX_V,-1);
	while(true){
		f=0;
		vector<int> dist(MAX_V, INF);
		dist[s]=0;
		queue<int> q;
		q.push(s);
		p.assign(MAX_V,-1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(u==t){
				break;
			}
			for(int v=0;v<MAX_V;v++){
				if((res[u][v] > 0) && (dist[v]==INF)){
					dist[v]=dist[u]+1;
					q.push(v);
					p[v]=u;
				}
			}
		}
		augment(t,INF);
		if (f==0){
			break;
		}
		mf+=f;
	}
	return mf;
}

int xmin[MAX];
int xmax[MAX];
int ymin[MAX];
int ymax[MAX];
int y[MAX];
int x[MAX];

void initialize(){
	memset(xmin,0,sizeof(xmin));
	memset(xmax,0,sizeof(xmax));
	memset(ymin,0,sizeof(ymin));
	memset(ymax,0,sizeof(ymax));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
}

vector<int> match, vis;
vector<int> AdjList[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int counter=1;
	scanf("%d",&n);
	while(n!=0){
		memset(res,0,sizeof(res));
		memset(resCopy,0,sizeof(resCopy));
		initialize();
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d",&xmin[i],&xmax[i],&ymin[i],&ymax[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				if((x[i]<xmax[j])&&(x[i]>xmin[j])){
					if((y[i]<ymax[j])&&(y[i]>ymin[j])){
						res[i][j+65]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			res[0][i]=1;
			res[64+i][65+n]=1;
		}
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout << res[i][64+j] << " ";
			}
			cout << endl;
		}*/
		
		copy(resCopy,res);
		s=0;
		t=65+n;
		int total=EK();
		
		bool valid=false;
		
		p3.assign(MAX_V,-1);
		vectorCopy(p3,p2);
		
		for(int i=65;i<65+n;i++){
			if(p3[i]==-1){
				continue;
			}
			copy(res,resCopy);
			res[p3[i]][i]=0; 
			//cout<<p3[i];
			EK();
			if(mf==total-1){
				valid=true;
			}
			else{
				p3[i]=-1;
				//break;
			}
		}
		printf("Heap %d\n",counter++);
		
		if(!valid){
			printf("none\n\n");
		}
		else{
			int first=1;
			for(int i=65;i<65+n;i++){
				if(p3[i]!=-1){
					if(first){
						printf("(%c,%d)",(char)i,p3[i]);
						first=0;
					}
					else{
						printf(" (%c,%d)",(char)i,p3[i]);
					}
				}
			}
			printf("\n\n");
		}
		
		scanf("%d",&n);
	}
	return 0;
}

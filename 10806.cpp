//Steven Kester Yuwono - UVa 10806

#include <bits/stdc++.h>
#define N 220
#define INF 2000000000
using namespace std;

int s,t;
int numVertex;
int adjM[N][N];
int tempAdjM[N][N];
int visited[N];
int length[N];
int parent[N];


void resetVisitedAndLengthAndParent(){
	memset(visited,false,sizeof(visited));
	for(int i=0;i<N;i++){
		parent[i]=1;
		length[i]=INF;
	}
}

void resetAdjM(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tempAdjM[i][j]=2000000000;
		}
	}
}

void dijkstra(){
    resetVisitedAndLengthAndParent();
   
	queue<int> q;
	q.push(s);
	length[s]=0;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		visited[curr]=false;
		for(int i=1;i<=numVertex;i++){
			if(length[curr]+tempAdjM[curr][i]<length[i]){
				length[i]=length[curr]+tempAdjM[curr][i];
				parent[i]=curr;
				if(!visited[i]){
					q.push(i);
					visited[i]=true;
				}
			}
		}
	}
    return ;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	
	cin >> numVertex;
	while(numVertex!=0){
		resetAdjM();
		int numEdges;
		cin >>numEdges;
		for(int i=0;i<numEdges;i++){
			int a,b,weight;
			cin >> a >> b >> weight;
			tempAdjM[a][b]=weight;
			tempAdjM[b][a]=weight;
		}
				
		s=1;
		dijkstra();
		
		int firstPrisoner=length[numVertex];
		
		if(firstPrisoner==2000000000){
			cout << "Back to jail" << endl;
			cin >> numVertex;
			continue;
		}
			
			
		int test=numVertex;
		while(parent[test]!=test){
			int test2=parent[test];
			tempAdjM[test2][test]=-tempAdjM[test2][test];
			tempAdjM[test][test2]=INF;
			test=test2;
		}
		
		s=numVertex;
		dijkstra();
		
		int secondPrisoner=length[1];
		
		if(secondPrisoner==2000000000){
			cout << "Back to jail" << endl;
		}
		else{
			cout << firstPrisoner+secondPrisoner << endl;
		}
		
		cin >> numVertex;
	}
	return 0;
}

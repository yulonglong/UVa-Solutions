#include <bits/stdc++.h>
using namespace std;

int N,M,I;
int age[510];
int person[510];
vector<int> parent[510];
vector<int> topo[510];
int minimum;
bool visited[510];

void dfsParent(int index,int x){
	visited[index]=true;
	for(unsigned int i=0;i<parent[index].size();i++){
		int newIndex=parent[index][i];
		if(!visited[newIndex]){
			dfsParent(newIndex,x);
		}
	}
	topo[x].push_back(index);
	return;
}


int main(){
	while(scanf("%d %d %d",&N,&M,&I)==3){
		
		memset(age,0,sizeof(age));
		memset(visited,false,sizeof(visited));
		for(int i=0;i<510;i++){
			parent[i].clear();
			topo[i].clear();
			person[i]=i;
		}
		
		for(int i=1;i<=N;i++){
			scanf("%d",&age[i]);
		}
		for(int i=0;i<M;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			parent[b].push_back(a);
		}
		
		//visit all edges from every single node, and store the parent nodes in a topo vector storage
		for(int i=1;i<=N;i++){
			memset(visited,false,sizeof(visited));
			for(unsigned int j=0;j<parent[i].size();j++){
				int index=parent[i][j];
				if(!visited[index]){
					dfsParent(index,i);
				}
			}
		}
				
		
		for(int i=0;i<I;i++){
			char cmd;
			int a,b;
			cin >> cmd;
			if(cmd=='T'){
				scanf("%d %d",&a,&b);
				swap(age[person[a]],age[person[b]]);
				swap(person[a],person[b]);
			}
			else{
				scanf("%d",&a);
				memset(visited,false,sizeof(visited));
				a=person[a];
				minimum=99999;
				for(unsigned int i=0;i<topo[a].size();i++){
					minimum=min(minimum,age[topo[a][i]]);
				}
				if(minimum==99999){
					printf("*\n");
				}
				else{
					printf("%d\n",minimum);
				}
			}
		}
	}
	return 0;
}

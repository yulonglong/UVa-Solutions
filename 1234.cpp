//Steven Kester Yuwono - UVa 1234

#include <bits/stdc++.h>
using namespace std;

struct Road {
    int v, c;
    Road(int v, int c) : v(v), c(c) {}
    inline bool operator < (const Road& that) const {
		return c < that.c;
	}
}; 

vector<Road> adjList[10010];
priority_queue<Road> pq;
bool visited[10010];
int vstart[10000];
int vcount[10000];
int vcounter=0;


int dfs(int vertex){
	visited[vertex]=true;
	int count=1;
	for(unsigned int i=0;i<adjList[vertex].size();i++){
		if(!visited[adjList[vertex][i].v]){
			count += dfs(adjList[vertex][i].v);
		}
	}
	return count;
}

int main(){
	//freopen("in2.txt","r",stdin);
	int tc;
	cin >> tc;
	while(tc--){
		memset(visited,false,sizeof(visited));
		memset(vstart,0,sizeof(vstart));
		memset(vcount,0,sizeof(vcount));
		vcounter=0;
		
		for(int i=0;i<10010;i++){
			adjList[i].clear();
		}
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=m;i++){
			int a,b,cost;
			cin >> a >> b >> cost;
			adjList[a].push_back(Road(b,cost));
			adjList[b].push_back(Road(a,cost));
		}
		
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				vcount[vcounter]=dfs(i);
				vstart[vcounter]=i;
				vcounter++;
			}
		}
		int result=0;
		for(int i=0;i<vcounter;i++){
			int vtotal=0;
			pq.push(Road(vstart[vtotal],0));
			memset(visited,false,sizeof(visited));
			while(vtotal<vcount[i]){
				Road curr= pq.top();
				pq.pop();
				if(visited[curr.v]){
					result+=curr.c;
				}
				else{
					visited[curr.v]=true;
					vtotal++;
					
					for(unsigned int j=0;j<adjList[curr.v].size();j++){
						if(!visited[adjList[curr.v][j].v]){
							pq.push(adjList[curr.v][j]);
						}
					}
				}
			}
			
			while(!pq.empty()){
				result+=pq.top().c;
				pq.pop();
			}
			
			cout << result << endl;
		}
	}
	return 0;
}

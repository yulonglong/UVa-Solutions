//Steven Kester Yuwono - UVa 318
//Single Source Shortest Path (SSSP) - Dijkstra

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 502
#define INF 2e9
using namespace std;

typedef pair<int,int> ii;

vector<ii> adjList[MAX];
bool visited[MAX];
int dist[MAX];
int n, m;

void reset(){
	for(int i=0;i<MAX;i++){
		adjList[i].clear();
	}
	memset(visited,0,sizeof(visited));
	for(int i=0;i<MAX;i++){
		dist[i]=INF;
	}
}

struct node{
	int curr;
	int cost;
	bool operator() ( const node& lhs, const node& rhs){
		return (lhs.cost>rhs.cost);
	}
};

void dijkstra(){
	priority_queue <node, vector<node>, node> pq;
	node firstNode;
	firstNode.curr = 1;
	firstNode.cost = 0;
	dist[1] = 0;
	pq.push(firstNode);
	while(!pq.empty()){
		int curr = pq.top().curr;
		int len = pq.top().cost;
		pq.pop();

		if(visited[curr]){
			continue;
		}
		visited[curr]=true;
		
		for(int i=0;i<(int)adjList[curr].size();i++){
			int dest = adjList[curr][i].first;
			int destLen = adjList[curr][i].second;
			if(dist[dest]>dist[curr]+destLen){
				dist[dest]=dist[curr]+destLen;
				node destNode;
				destNode.curr = dest;
				destNode.cost = len+destLen;
				pq.push(destNode);
			}
		}
	}

	return;
}

void handleCornerCases(double &ans, int &l, int &r){
	for(int i=1;i<=n;i++){
		if((dist[i]>ans)&&(dist[i]!=INF)){
			ans = dist[i];
			l = i;
			r = -1;
		}
	}

	for (int src = 1; src <= n; src++) {
	    for (int i = 0; i < (int) adjList[src].size(); i++) {
	        int dest = adjList[src][i].first;
	        int t1 = dist[src];
	        int t2 = dist[dest];
	        if (t1 < t2) {
				swap(t1, t2);
			}
	        float endTime = t1 + ((adjList[src][i].second - (t1 - t2)) / 2.0);
	        if ((t1!=INF)&&(t2!=INF)&&(endTime>ans)) {
				if(src<dest){
					l = src;
					r = dest;
				}
				else if(dest<src){
					r = src;
					r = dest;
				}
				ans = endTime;
	        }
	    }
    }
    return;
}

int main(){
	int tc=1;
	
	while((cin >> n >> m)&&(n|m)){
		reset();
		for(int i=1;i<=m;i++){
			int src, dest, len;
			cin >> src >> dest >> len;
			adjList[src].push_back(ii(dest,len));
			adjList[dest].push_back(ii(src,len));
		}

		dijkstra();

		double ans = 0;
		int l = 1;
		int r = -1;

		handleCornerCases(ans,l,r);

		if(r==-1){
			printf("System #%d\n",tc++);
			printf("The last domino falls after %.1f seconds, at key domino %d.\n\n",ans,l);
		}
		else{
			printf("System #%d\n",tc++);
			printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n",ans,l,r);
		}
		
	}
	return 0;
}